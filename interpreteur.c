


#include "interpreteur.h"

Instruction instr[1024];
int indexInst = 0;
int currentInst=0;
int registers[12];  /* R0 - R11 */
int memory[1024];


void queue_instruction(char* operation, int a, int b){
	Instruction new_inst;
	strcpy(new_inst.operation, operation);
	new_inst.a = a;
	new_inst.b = b;

	instr[indexInst] = new_inst;
	indexInst++;
	
}

void edit_instruction(int pos, char* op , int a, int b) {   
	

	strcpy(instr[pos].operation, op);
	instr[pos].a = a;
	instr[pos].b = b;

}

int get_latest_inst(){
	return(indexInst-1);
}

int get_register_value(int tableIndex){
return registers[tableIndex];
}


int get_memory_value(int tableIndex){
return memory[tableIndex];
}


void printInst(int Index){
	printf("Inst %s a %d b %d \n", instr[Index].operation, instr[Index].a, instr[Index].b); 
}

void execute_all_instructions(){

     for(currentInst; currentInst<indexInst; currentInst++){
	printInst(currentInst);
	instructionExecute(currentInst);
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
			registers[instr[instructionIndex].a] = 1; // equality betw our values
		} else{
			registers[instr[instructionIndex].a] = -1; // not equality
		}



	} else if(strcmp(instr[instructionIndex].operation, "INF") == 0){
		if(registers[instr[instructionIndex].a] < registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = -1;
		}



	} else if(strcmp(instr[instructionIndex].operation, "INFE") == 0){
		if(registers[instr[instructionIndex].a] <= registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = -1;
		}



	} else if(strcmp(instr[instructionIndex].operation, "SUP") == 0){
		if(registers[instr[instructionIndex].a] > registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = -1;
		}



	} else if(strcmp(instr[instructionIndex].operation, "SUPE") == 0){
		if(registers[instr[instructionIndex].a] >= registers[instr[instructionIndex].b]){
			registers[instr[instructionIndex].a] = 1;
		} else{
			registers[instr[instructionIndex].a] = -1;
		}
	} else if(strcmp(instr[instructionIndex].operation, "JMP") == 0){
		currentInst = registers[instr[instructionIndex].a];



	} else if(strcmp(instr[instructionIndex].operation, "JMPC") == 0){

			printf("R10: %d\n",registers[instr[instructionIndex].b]);
			printf("instr[instructionIndex].a: %d\n",instr[instructionIndex].a);
		if(registers[instr[instructionIndex].b] == -1){ //so to say: Condition is not Ok.
			
			currentInst= instr[instructionIndex].a;
			printf("nu är vi på: %d\n",indexInst);
		}
	} 

}


/*
void main(){

}
*/



