#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 25

int bm = 0;

/*
0 ADD
1 MUL
2 SUB
3 COP
4 AFC
5 LOAD
6 STORE
7 EQU
*/








typedef struct instruction {
  char* code[16];
  int a;
  int b;
} instruction;

int counter=0;


instruction instructions[4096];


/*
void initialize_instructions(){

strcpy(instructions[0].op, "ADD");
strcpy(instructions[1].op, "MUL");
strcpy(instructions[3].op, "SUB");
strcpy(instructions[4].op, "COP");
strcpy(instructions[5].op, "AFC");
strcpy(instructions[6].op, "LOAD");
strcpy(instructions[7].op, "STORE");
strcpy(instructions[8].op, "EQU");
/* ADD MORE 
}
*/






/* ADD all the functions that we are going to write then 
start thinking how we can concatenate 2 strings/index
gonan use the table from the course about which instruction is at wich number of OP
                  0 = store r1 , 1 store r2

*/



void LOAD(int index){

instructions[counter+2].code[16-13] = "x1"; //load in r2
instructions[counter+2].code[12-0] = index; //load in r2
}


void ADD(int index_a, int index_b){

instructions[counter+1].code = strcconcatenate(0000,indexA+memory_start); //store in r1



instructions[counter+2].code[16-13] = "x2"; //add value of r1 and r2 and put it in adress
instructions[counter+2].code[12-0] = "x234"; //addres as arg of add



}

if(strcmp(instr[indexInst].op, "MULT") == 0){
		registers[instr[indexInst].a] = registers[tab_instr[indexInst].a]*registers[instr[indexInst].b] ;
	}




void;}
