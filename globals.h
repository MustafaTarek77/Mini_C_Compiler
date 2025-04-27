#define QUAD_FILE "./output/quadruples.txt"
#define ERROR_FILE "./output/errors.txt"
#define UNUSED_SYMBOLS_FILE "./output/warnings.txt"
#define SYMBOL_TABLE_FILE "./output/symbol_table.txt"

#define MAX_SYMBOLS 2000
#define MAX_FUNC_ARGS 100
#define MAX_LABELS 500

typedef struct symbol
{
    int id, scope_level, declaration_line;
    bool is_function_parameter, is_used, is_initialized, is_assigned_to_func, scope_ended;
    char *identifier, *type, *ident_data_type;
    int function_arguments[MAX_FUNC_ARGS];
    int curr_function_arg_count;

} symbol;

typedef struct Node
{
    char *type;  
} Node;

// global variables for label tracking
int false_label_counter = 0;   
int false_label_stack_index = -1;
int falseLabelStack[MAX_LABELS];     

int loop_start_counter = 0;     
int loop_start_stack_index = -1;
int loopStartStack[MAX_LABELS];      

int loop_end_counter = 0;       
int loop_end_stack_index = -1;
int loopEndStack[MAX_LABELS];       

int if_end_counter = 0;      
int if_end_stack_index = -1;
int ifEndStack[MAX_LABELS];      

int switch_identifier_stack_index = -1;
char *switchIdentifierStack[MAX_LABELS];  

char *quadrupleFilePath = NULL;
FILE *quadrupleFilePointer = NULL;