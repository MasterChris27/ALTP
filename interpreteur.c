#include "interpreteur.h"

Instruction instr[1024];
int indexInst = 0;
int currentInst=0;
int reg_start=4;
int registers[12];  /* R0 - R11 */
int recursivity_register[8];
int recursivity_depth=0;
int memory[1024];


void queue_instruction(char* operation, int a, int b){
	Instruction new_inst;
	strcpy(new_inst.operation, operation);
	new_inst.a = a;
	new_inst.b = b;

	instr[indexInst] = new_inst;
	indexInst++;
	
}



void printAllInst(){
	int i=0;
	while(i<indexInst){
	printInst(i);
	i++;
	//printf("main %d\n\n",i);
}	

}

void edit_instruction(int pos, char* op , int a, int b) {   
	strcpy(instr[pos].operation, op);
	instr[pos].a = a;
	instr[pos].b = b;
}

int get_latest_inst(){
	if(indexInst>0)
	return(indexInst-1);
else 
	return indexInst;
}

int get_reg_index_depth(int i){
return reg_start +i;
}

int get_reg_val(int i){
return registers[i];
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
	printf("currentInst: %d\n", currentInst);
	instructionExecute(currentInst);
	}

}

void instructionExecute(int i){

	if(strcmp(instr[i].operation, "ADD") == 0){
		registers[instr[i].a] += registers[instr[i].b] ;


	} else if(strcmp(instr[i].operation, "SUB") == 0){
		registers[instr[i].a] -= registers[instr[i].b] ;


	} else if(strcmp(instr[i].operation, "MUL") == 0){
		registers[instr[i].a] *= registers[instr[i].b] ;


	} else if(strcmp(instr[i].operation, "DIV") == 0){
		if( registers[instr[i].b] != 0 ){
			registers[instr[i].a] /= registers[instr[i].b] ;
		}else{
			registers[instr[i].a] = 0;
		}

	

	} else if(strcmp(instr[i].operation, "STORE") == 0){
		memory[instr[i].a] = registers[instr[i].b];

	



	} else if(strcmp(instr[i].operation, "LOAD") == 0){
		registers[instr[i].a] = memory[instr[i].b];

	



	} else if(strcmp(instr[i].operation, "AFC") == 0){
		registers[instr[i].a] = instr[i].b;



	} else if(strcmp(instr[i].operation, "EQU") == 0){
		if(registers[instr[i].a] == registers[instr[i].b]){
			registers[instr[i].a] = 1; // equality betw our values
		} else{
			registers[instr[i].a] = -1; // not equality
		}



	} else if(strcmp(instr[i].operation, "INF") == 0){
		if(registers[instr[i].a] < registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}



	} else if(strcmp(instr[i].operation, "INFE") == 0){
		//printf("registers[instr[i].a]: %d\n", registers[instr[i].a]);
		//printf("registers[instr[i].b]: %d\n", registers[instr[i].b]);
		if(registers[instr[i].a] <= registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}

	//printf("result: %d\n", registers[instr[i].a]);
	} else if(strcmp(instr[i].operation, "SUP") == 0){
		if(registers[instr[i].a] > registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}



	} else if(strcmp(instr[i].operation, "SUPE") == 0){
		if(registers[instr[i].a] >= registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}
	} else if(strcmp(instr[i].operation, "JMP") == 0){
		currentInst = instr[i].a;



	} else if(strcmp(instr[i].operation, "JMPC") == 0){
		//printf("jump cond: %d\n",registers[instr[i].b]);
		if(registers[instr[i].b] == -1){ //so to say: Condition is not Ok.			
			currentInst= instr[i].a;
		}
	} else if(strcmp(instr[i].operation, "CALL") == 0){	
		
			currentInst= instr[i].a; // jump at designated address
		        recursivity_register[recursivity_depth]=instr[i].b; // storing the return address
			recursivity_depth++;
	} else if(strcmp(instr[i].operation, "RET") == 0){	
		
			recursivity_depth--;
			currentInst= recursivity_register[recursivity_depth]; // jump at designated address
	} 

}


/*
void main(){

}
*/



