#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

FILE *create_output_file(char *path)
{
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
        printf("Error: Unable to create file at path: %s\n", path);
        exit(0);
    }
    return file;
}

void set_output_file_path(char *filePath, FILE *file)
{
    quadrupleFilePath = filePath;
    quadrupleFilePointer = file;
}

void write_identifier_quadruple(char *symbol, char *actionType)
{
    fprintf(quadrupleFilePointer, "\t%s %s\n", actionType, symbol);
}

void push_end_label(int ifEndLabel)
{
    loopEndStack[++loop_end_stack_index] = ifEndLabel;
}

void push_if_end_label(int loopEndLabel)
{
    ifEndStack[++if_end_stack_index] = loopEndLabel;
}

void jump_to_end_of_loop()
{
    fprintf(quadrupleFilePointer, "\tjmp end_loop_%d\n", loopEndStack[loop_end_stack_index]);
}

void jump_to_end_of_if()
{
    fprintf(quadrupleFilePointer, "\tjmp end_if_%d\n", ifEndStack[if_end_stack_index]);
}

void pop_end_label()
{
    if (loop_end_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No end label to add. Segmentation Fault\n");
        return;
    }
    int loopEndLabel = loopEndStack[loop_end_stack_index--];
    fprintf(quadrupleFilePointer, "end_loop_%d:\n", loopEndLabel);
}

void pop_if_end_label()
{
    if (if_end_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No end label to add. Segmentation Fault\n");
        return;
    }
    int ifEndLabel = ifEndStack[if_end_stack_index--];
    fprintf(quadrupleFilePointer, "end_if_%d:\n", ifEndLabel);
}

void push_start_label(int loopStartLabel, char *label)
{
    loopStartStack[++loop_start_stack_index] = loopStartLabel;
    fprintf(quadrupleFilePointer, "start_%s_%d:\n", label, loopStartLabel);
}

void jump_to_start_of_loop(char *label)
{
    fprintf(quadrupleFilePointer, "\tjmp start_%s_%d\n", label, loopStartStack[loop_start_stack_index]);
}

void pop_start_label()
{
    if (loop_start_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No start label to add. Segmentation Fault\n");
        return;
    }
    loop_start_stack_index--;
}

void jump_if_false(int falseLabelCounter)
{
    fprintf(quadrupleFilePointer, "\tjf false_label_%d\n", falseLabelCounter);
    falseLabelStack[false_label_stack_index++] = falseLabelCounter;
}

void pop_last_false_label()
{
    if (false_label_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No end label to add. Segmentation Fault\n");
        return;
    }

    fprintf(quadrupleFilePointer, "false_label_%d:\n", falseLabelStack[--false_label_stack_index]);
}

void push_switch_identifier(char *identifier)
{
    switchIdentifierStack[++switch_identifier_stack_index] = identifier;
}

void push_case_value()
{
    if (switch_identifier_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No last identifier to peek. Segmentation Fault\n");
        return;
    }

    fprintf(quadrupleFilePointer, "\tpush %s\n", switchIdentifierStack[switch_identifier_stack_index]);
}

void pop_switch_identifier()
{
    if (switch_identifier_stack_index < 0)
    {
        fprintf(quadrupleFilePointer, "Error: No last identifier to pop. Segmentation Fault\n");
        return;
    }
    switch_identifier_stack_index--;
}
