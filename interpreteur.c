#include "interpreteur.h"

Instruction instr[1024];
int indexInst = 0;

int registers[12];  /* R0 - R11 */
int memory[1024];


void add_instruction(char* operation, int a, int b){
	printf("instr added\n");
	Instruction new_inst;
	strcpy(new_inst.operation, operation);
	new_inst.a = a;
	new_inst.b = b;

	instr[indexInst] = new_inst;

	indexInst++;
	
}

int get_memory_value(int tableIndex){
return memory[tableIndex];
}

int get_last_inst(void){
	return(indexInst-1);
}

void printInst(int Index){
	printf("Inst %s a %d b %d \n", instr[Index].operation, instr[Index].a, instr[Index].b); 
}

void execute_all_instructions(){
	for(int i=0; i<indexInst; i++){
	printInst(i);
	instructionExecute(i);
	}

}

void instructionExecute(int instructionIndex){

	if(strcmp(instr[instructionIndex].operation, "ADD") == 0){
		registers[instr[instructionIndex].a] += registers[instr[instructionIndex].b] ;


	} else if(strcmp(instr[instructionIndex].operation, "SUB") == 0){
		registers[instr[instructionIndex].a] -= registers[instr[instructionIndex].b] ;


	} else if(strcmp(instr[instructionIndex].operation, "MUL") == 0){
		registers[instr[instructionIndex].a] *= registers[instr[instructionIndex].b] ;


	} else if(strcmp(instr[instructionIndex].operation, "DIV") == 0){
		if( registers[instr[instructionIndex].b] != 0 ){
			registers[instr[instructionIndex].a] /= registers[instr[instructionIndex].b] ;
		}else{
			registers[instr[instructionIndex].a] = 0;
		}



	} else if(strcmp(instr[instructionIndex].operation, "STORE") == 0){
		memory[instr[instructionIndex].a] = registers[instr[instructionIndex].b];



	} else if(strcmp(instr[instructionIndex].operation, "LOAD") == 0){
		registers[instr[instructionIndex].a] = memory[instr[instructionIndex].b];



	} else if(strcmp(instr[instructionIndex].operation, "AFC") == 0){
		registers[instr[instructionIndex].a] = instr[instructionIndex].b;



	} else if(strcmp(instr[instructionIndex].operation, "EQU") == 0){
		if(registers[instr[instructionIndex].a] == registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = 0;
		}



	} else if(strcmp(instr[instructionIndex].operation, "INF") == 0){
		if(registers[instr[instructionIndex].a] < registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = 0;
		}



	} else if(strcmp(instr[instructionIndex].operation, "INFE") == 0){
		if(registers[instr[instructionIndex].a] <= registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = 0;
		}



	} else if(strcmp(instr[instructionIndex].operation, "SUP") == 0){
		if(registers[instr[instructionIndex].a] > registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = 0;
		}



	} else if(strcmp(instr[instructionIndex].operation, "SUPE") == 0){
		if(registers[instr[instructionIndex].a] >= registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = 0;
		}
	} else if(strcmp(instr[instructionIndex].operation, "JMP") == 0){
		instructionIndex = registers[instr[instructionIndex].a];



	} else if(strcmp(instr[instructionIndex].operation, "JMPC") == 0){
		if(registers[instr[instructionIndex].b] == 0){
			instructionIndex= registers[instr[instructionIndex].a];
		}
	} 

}


/*
void main(){

}
*/



