#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Instruction{
	char operation[16];
	int a;
	int b;
} Instruction;


void add_instruction(char* operation, int a, int b);

void instructionExecute(int instructionIndex);

int get_last_inst(void);

void printInst(int Index);

void execute_all_instructions();

int get_memory_value(int tableIndex);
