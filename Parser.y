%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "Parser.tab.h"
    #include "globals.h"
    #include "quadruples.cpp"

    int yylex();
    extern FILE *yyin;  
    void yyerror(char* );
    extern int yylineno;  

    symbol symbol_table[MAX_SYMBOLS];

    int block_counter = 0;
    int symbol_table_index = 0;

    int curr_function_index = 0;
    int curr_function_arg_count = 0;
    int called_function_index = 0;
    int is_argument = 0;
    int is_loop = 0;
    int has_return = 0;

    int insertion_index = -1;

    FILE *error_output_file = NULL;

    // Checks if memory allocation was successful
    void check_mem_alloc(Node *node);

    // Creates a new AST node with the given type
    Node *create_node(char *type);

    // Validates types for arithmetic operations (unary or binary)
    Node *check_valid_types_arithmetic(Node *operand1, Node *operand2, int curr_line);

    // Validates types for boolean operations (unary or binary)
    Node *check_valid_types_bool(Node *operand1, Node *operand2, int curr_line);

    // Validates types for bitwise operations (binary only)
    Node *check_valid_types_bitwise(Node *operand1, Node *operand2, int curr_line);


    void end_scope(int line_number);
    int symbol_exists(char *identifier);
    int add_symbol(char *ident_data_type, char *identifier, char *type, int line_number, bool is_function_argument);
    int check_symbol(char *identifier, bool is_assigned, int line_number);
    void check_integer(int index, int value, int line_number);
    void check_float(int index, float value, int line_number);
    void check_bool(int index, bool value, int line_number);
    void check_string(int index, char *value, int line_number);
    void check_char(int index, char *value, int line_number);
    void check_variable_type(int i, int line_number);
    void check_value_type(char *ident_data_type, int line_number);
    // Checks if the number of arguments in a function call matches the declaration
    void check_function_argument_count(int i, int line_number);

    // Pops function arguments from the stack and generates corresponding quadruples
    void pop_function_parameters(int index);

    // Displays the symbol table to a given file
    void write_symbol_table_to_file(const char *filename);

    // Logs all unused variables (functions, arguments, identifiers) to a file
    void write_unused_symbols_to_file(const char *filename);

    // Removes all output files
    int delete_output_files();




%}

%union { 
 int int_type;
 char* string_type; 
 float float_type;
 bool bool_type;
 char char_type;
 struct Node *node;
}

%code requires
{
#include<stdbool.h>
}

%token INT FLOAT CHAR BOOL STRING
%token PRINT VOID RETURN CONTINUE SWITCH BREAK CASE DEFAULT IF ELSE FOR WHILE DO 
%token BOOL_VALUE LOGICAL_AND LOGICAL_OR LOGICAL_NOT EQUAL NOT_EQUAL BITWISE_OR BITWISE_AND BITWISE NOT
%token SEMICOLON COMMA MOD ADD SUB MUL DIV POW SHIFT_LEFT SHIFT_RIGHT GREATER_THAN LESS_THAN ASSIGN GREATER_EQUAL LESS_EQUAL POST_INC POST_DEC
%token CONSTANT IDENTIFIER STRING_VALUE CHAR_VALUE INTEGER_VALUE FLOAT_VALUE

%left BITWISE_OR BITWISE_AND BITWISE_NOT LOGICAL_AND LOGICAL_OR
%left GREATER_THAN LESS_THAN GREATER_EQUAL LESS_EQUAL EQUAL NOT_EQUAL
%left ADD SUB MUL DIV MOD SHIFT_LEFT SHIFT_RIGHT POST_INC POST_DEC

%right POW ASSIGN LOGICAL_NOT

%type <string_type> CONSTANT IDENTIFIER data_type STRING_VALUE CHAR_VALUE
%type <float_type> FLOAT_VALUE
%type <int_type> INTEGER_VALUE
%type <bool_type> BOOL_VALUE

%type <node> expression function_call return_statement declaration_statement RETURN
%%
program:
        program statement       
        |
        ;
block:
        '{' {block_counter++;} program '}' {end_scope(yylineno);}             
        ;

statement:    block
            | declaration_statement
            | assignment_statement
            | expression SEMICOLON
            | print_statement
            | conditional_statement
            | function_declaration
            | BREAK SEMICOLON{jump_to_end_of_loop();}
            | CONTINUE SEMICOLON {}
            | return_statement SEMICOLON{fprintf(quadrupleFilePointer, "\treturn\n");}
            ;

conditional_statement 
    : if_wrapper
    | while_wrapper
    | do_while_wrapper
    | switch_wrapper
    | for_wrapper
    ;

if_wrapper
    : { push_if_end_label(++loop_end_counter); } 
      if_statement 
      { pop_if_end_label(); }
    ;

if_statement
    : IF expression 
      { jump_if_false(++false_label_counter); } 
      block 
      { jump_to_end_of_if(); pop_last_false_label(); } 
      else_statement
    ;

else_statement 
    : ELSE block
    | ELSE if_statement
    | 
    ;

while_wrapper
    : { push_start_label(++loop_start_counter, "while"); }
      while_statement
      { pop_start_label(); }
    ;

while_statement
    : WHILE expression 
      { jump_if_false(++false_label_counter); } 
      block 
      { jump_to_start_of_loop("while"); pop_last_false_label(); }
    ;

do_while_wrapper
    : { push_start_label(++loop_start_counter, "do_while"); }
      do_while_statement
      { pop_start_label(); }
    ;

do_while_statement
    : DO block WHILE '(' expression ')' SEMICOLON 
      { jump_if_false(++false_label_counter); jump_to_start_of_loop("do_while"); pop_last_false_label(); }
    ;

switch_wrapper
    : { push_end_label(++loop_end_counter); } 
      switch_statement 
      { pop_end_label(); }
    ;

switch_statement:
    SWITCH '(' IDENTIFIER 
    { 
        push_switch_identifier($3);
        check_symbol($3, 0, yylineno); 
    } 
    ')' '{' case_statement '}' 
    { 
        pop_switch_identifier(); 
    }
    ;

default_statement:
    DEFAULT ':' block
    ;

case_statement:
    CASE expression 
    { 
        push_case_value();
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
        jump_if_false(++false_label_counter); 
    }
    ':' block 
    { 
        pop_last_false_label(); 
    }
    case_statement
    | default_statement
    | 
    ;    

for_wrapper
    : FOR '(' 
        { is_loop = 1; } 
        statement 
        { push_start_label(++loop_start_counter, "for"); } 
        statement 
        { jump_if_false(++false_label_counter); } 
        statement 
      ')' 
      { is_loop = 0; } 
      block 
      { jump_to_start_of_loop("for"); pop_last_false_label(); }
    ;


declaration_statement:
    data_type IDENTIFIER 
    { 
        insertion_index = add_symbol($1, $2, "variable", yylineno, false); 
    }
    ASSIGN expression SEMICOLON 
    { 
        insertion_index = -1;
        write_identifier_quadruple($2, "pop"); 
    }
    | data_type IDENTIFIER
    { 
        insertion_index = add_symbol($1, $2, "variable", yylineno, false); 
    }
    SEMICOLON 
    { 
        insertion_index = -1; 
    }
    | data_type CONSTANT  
    { 
        insertion_index = add_symbol($1, $2, "constant", yylineno, false); 
    }
    ASSIGN expression SEMICOLON 
    { 
        insertion_index = -1; 
        write_identifier_quadruple($2, "pop"); 
    }
    ;

assignment_statement:
    IDENTIFIER ASSIGN 
    { 
        insertion_index = check_symbol($1, 1, yylineno); 
    } 
    expression SEMICOLON 
    { 
        write_identifier_quadruple($1, "pop"); 
    }
    | CONSTANT ASSIGN 
    { 
        printf("Error at line: %d constants must not be reassigned\n", yylineno);
        exit(EXIT_FAILURE); 
        insertion_index = -1; 
    } 
    expression SEMICOLON 
    ;

print_statement:
    PRINT 
    { 
        insertion_index = -1;
    }
    '(' expression ')' SEMICOLON 
    { 
        fprintf(quadrupleFilePointer, "\t%s\n", "print");
    }
    ;

data_type: 
    INT 
    { 
        $$ = "int";   
    }
    | FLOAT 
    { 
        $$ = "float"; 
    }
    | STRING 
    { 
        $$ = "string"; 
    }
    | CHAR 
    { 
        $$ = "char";  
    }
    | BOOL 
    { 
        $$ = "bool";  
    }
    | VOID 
    { 
        $$ = "void";  
    }
    ;


expression:

    '(' expression ')'  
    { 
        $$ = $2;
    }
    | function_call
    { 
        $$ = $1;  
    }
    |
    IDENTIFIER 
    { 
        int i = check_symbol($1, 0, yylineno);
        check_variable_type(i, yylineno);
        $$ = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple($1, "push");
    }
    |
    IDENTIFIER POST_INC
    { 
        int i = check_symbol($1, 0, yylineno);
        check_variable_type(i, yylineno);
        $$ = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple($1, "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_inc");
        write_identifier_quadruple($1, "pop");
    }
    |
    IDENTIFIER POST_DEC
    { 
        int i = check_symbol($1, 0, yylineno);
        check_variable_type(i, yylineno);
        $$ = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple($1, "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_dec");
        write_identifier_quadruple($1, "pop");
    }
    | CONSTANT 
    { 
        int i = check_symbol($1, 0, yylineno); 
        check_variable_type(i, yylineno);
        $$ = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple($1, "push");
    }
    | INTEGER_VALUE 
    { 
        $$ = create_node("int");
        check_value_type("int", yylineno);
        check_integer(insertion_index, $1, yylineno);
    }       
    | FLOAT_VALUE 
    { 
        $$ = create_node("float");
        check_value_type("float", yylineno);
        check_float(insertion_index, $1, yylineno);
    }         
    | BOOL_VALUE 
    { 
        $$ = create_node("bool");
        check_value_type("bool", yylineno);
        check_bool(insertion_index, $1, yylineno);
    }   
    | STRING_VALUE
    { 
        $$ = create_node("string");
        check_value_type("string", yylineno);
        check_string(insertion_index, $1, yylineno);
    }        
    | CHAR_VALUE  
    { 
        $$ = create_node("char");
        check_value_type("char", yylineno);
        check_char(insertion_index, $1, yylineno);
    } 
    | SUB expression        
    { 
        $$ = check_valid_types_arithmetic($2, NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "neg");
    }          
    | LOGICAL_NOT expression
    { 
        $$ = check_valid_types_bool($2, NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_not");
    }
    
    | expression ADD expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "add");
    }
    | expression SUB expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","sub");
    }           
    | expression MUL expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mul");
    }          
    | expression DIV expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "div");
    }           
    | expression POW expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","pow");
    }
    | expression MOD expression
    { 
        $$ = check_valid_types_arithmetic($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mod");
    }         
    
    | expression BITWISE_OR expression  
    { 
        $$ = check_valid_types_bitwise($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_or");
    }
    | expression BITWISE_AND expression 
    { 
        $$ = check_valid_types_bitwise($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_and");
    }
    | expression SHIFT_LEFT expression         
    { 
        $$ = check_valid_types_bitwise($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_left");
    }
    | expression SHIFT_RIGHT expression         
    { 
        $$ = check_valid_types_bitwise($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_right");
    }
    
    | expression LOGICAL_AND expression
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_and");
    }    
    | expression LOGICAL_OR expression 
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_or");
    } 

    | expression EQUAL expression    
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
    }  
    | expression NOT_EQUAL expression
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "not_equal");
    } 

    | expression GREATER_THAN expression    
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_than");
    }            
    | expression GREATER_EQUAL expression 
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_equal");
    }        
    | expression LESS_THAN expression    
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_than");
    }             
    | expression LESS_EQUAL expression 
    { 
        $$ = check_valid_types_bool($1, $3, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_equal");
    }         
    ;
    
return_statement:
    RETURN
    | RETURN 
    expression 
    { 
        has_return = 1; 
    }
    ;


function_call:
    IDENTIFIER 
    { 
        curr_function_arg_count = 0;
        called_function_index = check_symbol($1, 0, yylineno);
    } 
    '(' 
    {is_argument = 1;}
    arguments_list 
    { 
        is_argument = 0;
        check_function_argument_count(called_function_index, yylineno); 
    }
    ')' 
    { 
        fprintf(quadrupleFilePointer, "\tcall %s\n", $1);
        $$ = create_node(symbol_table[called_function_index].ident_data_type); 
    }
    ;

arguments_list:
    expression 
    { 
        curr_function_arg_count++; 
    } 
    COMMA arguments_list
    | expression 
    { 
        curr_function_arg_count++; 
    }
    | 
    ;

function_declaration:
    data_type IDENTIFIER 
    { 
        fprintf(quadrupleFilePointer, "%s:\n", $2);
    } 
    '(' parameters_list ')' 
    { 
        curr_function_index = add_symbol($1, $2, "function", yylineno, 0);
        pop_function_parameters(curr_function_index); 
    }
    block 
    { 
        fprintf(quadrupleFilePointer, "\tend %s\n", $2);
    }
    ;

parameters_list:
    data_type IDENTIFIER 
    { 
        insertion_index = add_symbol($1, $2, "variable", yylineno, true); 
    } 
    COMMA parameters_list
    | data_type IDENTIFIER 
    { 
        insertion_index = add_symbol($1, $2, "variable", yylineno, true); 
    }
    | 
    ;


%%

void check_mem_alloc(Node *node)
{
    if (!node)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

Node *create_node(char *type)
{
    Node *node = (Node *)malloc(sizeof(Node));
    check_mem_alloc(node);
    node->type = type;
    return node;
}

Node *check_valid_types_arithmetic(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (!operand2)
    {
        if (strcmp(operand1->type, "int") != 0 && strcmp(operand1->type, "float") != 0)
        {
            printf("Error at line %d: Invalid type for unary operator (int and float types are valid only)\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (strcmp(operand1->type, "string") == 0 ||
            strcmp(operand2->type, "string") == 0 ||
            strcmp(operand1->type, "char") == 0 ||
            strcmp(operand2->type, "char") == 0 ||
            strcmp(operand1->type, "void") == 0 ||
            strcmp(operand2->type, "void") == 0)
        {
            printf("Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }
    
    res->type = operand1->type;
    return res;
}

Node *check_valid_types_bool(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (!operand2)
    {
        // Handle unary negation operator (!)
        if (strcmp(operand1->type, "string") == 0 || strcmp(operand1->type, "char") == 0 || strcmp(operand1->type, "void") == 0)
        {
            printf("Error at line %d: Invalid type for negation operator (!)\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Handle binary operators (&&, ||, <, <=, >, >=, ==, !=)
        if (strcmp(operand1->type, "string") == 0 ||
            strcmp(operand2->type, "string") == 0 ||
            strcmp(operand1->type, "char") == 0 ||
            strcmp(operand2->type, "char") == 0 ||
            strcmp(operand1->type, "void") == 0 ||
            strcmp(operand2->type, "void") == 0)
        {
            printf("Error at line %d: Invalid types for boolean operator\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }

    res->type = "bool";
    return res;
}

Node *check_valid_types_bitwise(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (strcmp(operand1->type, "int") != 0 || strcmp(operand2->type, "int") != 0)
    {
        printf("Error at line %d: Invalid types for bitwise operator\n", curr_line);
        exit(EXIT_FAILURE);
    }

    res->type = "int";
    return res;
}

void end_scope(int line_number)
{
    // === Function Return Validations ===
    if (curr_function_index != -1 && strcmp(symbol_table[curr_function_index].type, "function") == 0)
    {
        // Case 1: Non-void function missing return
        if (!has_return && strcmp(symbol_table[curr_function_index].ident_data_type, "void") != 0)
        {
            printf("Error at line %d: Missing 'return' in Function\n", line_number);
            fprintf(error_output_file, "Error at line %d: Missing 'return' in Function %s\n", line_number, symbol_table[curr_function_index].identifier);
            exit(EXIT_FAILURE);
        }

        // Case 2: Void function has a return
        if (has_return && strcmp(symbol_table[curr_function_index].ident_data_type, "void") == 0)
        {
            printf("Error at line %d: It's a void Function; can't have 'return'\n", line_number);
            fprintf(error_output_file, "Error at line %d: It's a void Function; can't have 'return'\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    // === Reset Function Scope Flags ===
    insertion_index = -1;
    curr_function_index = -1;
    has_return = 0;

    // === Mark Variables in This Scope as Ended ===
    for (int i = 0; i < symbol_table_index; i++)
    {
        if (symbol_table[i].scope_level == block_counter)
        {
            symbol_table[i].scope_ended = true;
        }
    }

    // === Exit the Current Scope Level ===
    block_counter--;
}

int symbol_exists(char *identifier)
{
    // === Search for Identifier in Current Scope ===
    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (strcmp(symbol_table[i].identifier, identifier) == 0 &&
            symbol_table[i].scope_level == block_counter &&
            !symbol_table[i].scope_ended)
        {
            return symbol_table[i].declaration_line;
        }
    }
    return -1;
}

int add_symbol(char *ident_data_type, char *identifier, char *type, int line_number, bool is_function_argument)
{
    // === Check for Redeclaration in Current Scope ===
    int L = symbol_exists(identifier);
    if (L != -1 && !is_function_argument)
    {
        printf("Error at line %d: %s is already declared in this scope_level at line %d\n", line_number, identifier, L);
        fprintf(error_output_file, "Error at line %d: %s is already declared in this scope_level at line %d\n", line_number, identifier, L);
        exit(EXIT_FAILURE);
    }

    // === Create New Symbol Entry ===
    struct symbol newItem;
    newItem.identifier = identifier;
    newItem.ident_data_type = ident_data_type;
    newItem.type = type;
    newItem.declaration_line = line_number;
    newItem.id = symbol_table_index;

    newItem.is_function_argument = is_function_argument;
    newItem.is_assigned_to_func = false;
    newItem.scope_ended = false;
    newItem.is_initialized = false;
    newItem.is_used = false;

    // === Determine Scope Level ===
    if (is_function_argument || is_loop)
    {
        newItem.scope_level = block_counter + 1;
    }
    else
    {
        newItem.scope_level = block_counter;
    }

    // === Link Function Arguments if This is a Function ===
    if (strcmp(type, "function") == 0)
    {
        int j = 0;
        for (int i = 0; i < symbol_table_index; i++)
        {
            if (symbol_table[i].is_function_argument &&
                symbol_table[i].scope_level == (block_counter + 1) &&
                !symbol_table[i].is_assigned_to_func)
            {
                newItem.function_arguments[j] = symbol_table[i].id;
                symbol_table[i].is_assigned_to_func = true;
                j++;
            }
        }
        newItem.curr_function_arg_count = j;
    }

    // === Add to Symbol Table ===
    symbol_table[symbol_table_index++] = newItem;

    return newItem.id;
}


int check_symbol(char *identifier, bool is_assigned, int line_number)
{
    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (strcmp(symbol_table[i].identifier, identifier) == 0 && !symbol_table[i].scope_ended)
        {
            if (!symbol_table[i].is_initialized &&
                strcmp(symbol_table[i].type, "variable") == 0 &&
                !symbol_table[i].is_function_argument &&
                !is_assigned)
            {
                printf("Error at line %d: %s used before initialization\n", line_number, identifier);
                fprintf(error_output_file, "Error at line %d: %s used before initialization\n", line_number, identifier);
                exit(EXIT_FAILURE);
            }

            if (!is_assigned)
            {
                symbol_table[i].is_used = true;
            }

            return symbol_table[i].id;
        }
    }

    printf("Error at line %d: %s undeclared identifier\n", line_number, identifier);
    fprintf(error_output_file, "Error at line %d: %s undeclared identifier\n", line_number, identifier);
    exit(EXIT_FAILURE);
}

static void push_correct_value_based_on_type(const char *type, int int_val, float float_val)
{
    if (strcmp(type, "float") == 0)
        fprintf(quadrupleFilePointer, "\tpush %f\n", (float)float_val);
    else if (strcmp(type, "bool") == 0)
        fprintf(quadrupleFilePointer, "\tpush %d\n", (bool)int_val);
    else if (strcmp(type, "int") == 0)
        fprintf(quadrupleFilePointer, "\tpush %d\n", int_val);
}

static void validate_assignment_type(int index, const char *expected_type, const char *value_type, int line_number)
{
    if ((strcmp(expected_type, "string") == 0 || strcmp(expected_type, "char") == 0 || strcmp(expected_type, "void") == 0))
    {
        printf("Error at line %d: %s '%s' variable assigned '%s' value\n",
               line_number, symbol_table[index].identifier, expected_type, value_type);
        fprintf(error_output_file, "Error at line %d: %s '%s' variable assigned '%s' value\n",
                line_number, symbol_table[index].identifier, expected_type, value_type);
        exit(EXIT_FAILURE);
    }
}

void check_integer(int index, int value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %d\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    symbol_table[index].is_initialized = true;

    if ((!symbol_table[index].scope_ended && strcmp(type, "void") != 0 && strcmp(type, "char") != 0 && strcmp(type, "string") != 0) || is_argument)
    {
        push_correct_value_based_on_type(type, value, (float)value);
    }
    else
    {
        validate_assignment_type(index, type, "int", line_number);
    }

    if (is_argument == 1)
        insertion_index = -1;
}

void check_float(int index, float value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %f\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    symbol_table[index].is_initialized = true;

    if ((!symbol_table[index].scope_ended && strcmp(type, "void") != 0 && strcmp(type, "char") != 0 && strcmp(type, "string") != 0) || is_argument)
    {
        push_correct_value_based_on_type(type, (int)value, value);
    }
    else
    {
        validate_assignment_type(index, type, "float", line_number);
    }

    if (is_argument == 1)
        insertion_index = -1;
}


// Helper: Report type mismatch error and exit
void report_type_error(int line_number, const char *identifier, const char *actual_type, const char *assigned_type)
{
    printf("Error at line %d: %s type is '%s' but assigned '%s'\n", line_number, identifier, actual_type, assigned_type);
    fprintf(error_output_file, "Error at line %d: %s type is '%s' but assigned '%s'\n", line_number, identifier, actual_type, assigned_type);
    exit(EXIT_FAILURE);
}

// Helper: Common post-check update
void finalize_assignment(int index)
{
    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

// Boolean check
void check_bool(int index, bool value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %d\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if (((strcmp(type, "string") != 0 && strcmp(type, "char") != 0 && strcmp(type, "void") != 0) && !symbol_table[index].scope_ended) || is_argument)
    {
        push_correct_value_based_on_type(type, (int)value, (float)value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "bool");
    }
    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

// String check
void check_string(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "string") == 0 && !symbol_table[index].scope_ended) || is_argument)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "string");
    }

    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

// Char check
void check_char(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "char") == 0 && !symbol_table[index].scope_ended) || is_argument)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "char");
    }

    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

// Helper: Report function errors with type mismatch
void report_type_mismatch_error(int line_number, const char *identifier1, const char *type1, const char *identifier2, const char *type2)
{
    printf("Error at line %d: %s is %s variable but found %s\n", line_number, identifier1, type1, type2);
    fprintf(error_output_file, "Error at line %d: %s is %s variable but found %s\n", line_number, identifier1, type1, type2);
    exit(EXIT_FAILURE);
}

bool are_types_compatible(const char *type1, const char *type2)
{
    if ((strcmp(type1, "string") == 0 && strcmp(type2, "char") == 0) ||
        (strcmp(type1, "char") == 0 && strcmp(type2, "string") == 0))
    {
        return true;
    }
    return strcmp(type1, type2) == 0;
}


// Helper: Check parameter type compatibility
void check_argument_type_compatibility(int line_number, int insertion_index, const char *expected_type, const char *actual_type)
{
    if (are_types_compatible(expected_type, actual_type))
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, expected_type, symbol_table[called_function_index].identifier, actual_type);
    }
}

/**
 * Checks if the type of the variable being assigned matches the expected type. 
 * 
 * If the types do not match, it reports a type mismatch error and exits the program.
 * If the types match and the source symbol is not a function, it marks the symbol as initialized.
 */
void check_variable_type(int symbol_index, int line_number)
{

    if (symbol_index == -1 || insertion_index == -1) return;

    const char *expected_type = symbol_table[symbol_index].ident_data_type;
    const char *actual_type = symbol_table[insertion_index].ident_data_type;

    if (strcmp(expected_type, actual_type) != 0)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, actual_type, symbol_table[symbol_index].identifier, expected_type);
    }
    else if (strcmp(symbol_table[insertion_index].type, "function") != 0)
    {
        symbol_table[insertion_index].is_initialized = true;
    }
}

// Main check for parameter type assignment
void check_value_type(char *ident_data_type, int line_number)
{
    if (is_argument == 1)
    {
        insertion_index = (curr_function_arg_count < symbol_table[called_function_index].curr_function_arg_count)
                              ? symbol_table[called_function_index].function_arguments[curr_function_arg_count]
                              : -1;
    }

    if (insertion_index == -1) return;

    const char *expected_type = symbol_table[insertion_index].ident_data_type;
    if (strcmp(expected_type, ident_data_type) != 0 && are_types_compatible(expected_type, ident_data_type))
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, expected_type, symbol_table[called_function_index].identifier, ident_data_type);
    }
}

// Function argument count check
void check_function_argument_count(int i, int line_number)
{
    int expected_arg_count = symbol_table[i].curr_function_arg_count;

    if (curr_function_arg_count > expected_arg_count)
    {
        printf("Error at line %d: too many arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        fprintf(error_output_file, "Error at line %d: too many arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        exit(EXIT_FAILURE);
    }
    else if (curr_function_arg_count < expected_arg_count)
    {
        printf("Error at line %d: too few arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        fprintf(error_output_file, "Error at line %d: too few arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        exit(EXIT_FAILURE);
    }
}

// Pop function arguments
void pop_function_parameters(int index)
{
    for (int i = symbol_table[index].curr_function_arg_count - 1; i >= 0; --i)
    {
        int argIndex = symbol_table[index].function_arguments[i];
        write_identifier_quadruple(symbol_table[argIndex].identifier, "pop");
    }
}


void write_symbol_table_to_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "===============================================================================================================================\n");
    fprintf(fp, " ID | Identifier     | Type     | Data Type | Line | Scope | FuncArg | Used | Init | AssignToFunc | ScopeEnded | Func Args\n");
    fprintf(fp, "===============================================================================================================================\n");

    for (int i = 0; i < symbol_table_index; i++)
    {
        struct symbol node = symbol_table[i];
        
        fprintf(fp, "%3d | %-14s | %-8s | %-9s | %4d | %5d |    %d    |  %d  |  %d  |      %d      |     %d     | ", 
                node.id, 
                node.identifier ? node.identifier : "(null)", 
                node.type ? node.type : "(null)", 
                node.ident_data_type ? node.ident_data_type : "(null)",
                node.declaration_line, 
                node.scope_level, 
                node.is_function_argument, 
                node.is_used, 
                node.is_initialized,
                node.is_assigned_to_func,
                node.scope_ended);

        if (node.curr_function_arg_count > 0)
        {
            for (int j = 0; j < node.curr_function_arg_count; j++)
            {
                fprintf(fp, "%d", node.function_arguments[j]);
                if (j != node.curr_function_arg_count - 1)
                    fprintf(fp, ",");
            }
        }
        else
        {
            fprintf(fp, "None");
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "===============================================================================================================================\n");

    fclose(fp);
}


void write_unused_symbols_to_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening unused variables file");
        exit(EXIT_FAILURE);
    }

    // Check each symbol and write warnings for unused symbols
    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (!symbol_table[i].is_used) // Skip used symbols
        {
            if (strcmp(symbol_table[i].type, "function") == 0)
            {
                fprintf(fp, "warning: function %s declared at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
            else if (symbol_table[i].is_function_argument == 1)
            {
                fprintf(fp, "warning: argument %s declared in function at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
            else
            {
                fprintf(fp, "warning: identifier %s declared at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
        }
    }

    fclose(fp);
}
void yyerror(char *s) { 
    printf("line %d: %s\n", yylineno, s); 
    fprintf(error_output_file, "line %d: %s\n", yylineno, s); 
} 
int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{ 
    quadrupleFilePath = QUAD_FILE;
    quadrupleFilePointer = create_output_file(QUAD_FILE);
    error_output_file = fopen(ERROR_FILE, "w");
    yyin = fopen(argv[1], "r");
    yyparse();
    write_unused_symbols_to_file(UNUSED_SYMBOLS_FILE);
    write_symbol_table_to_file(SYMBOL_TABLE_FILE);
    
    return 0;
}