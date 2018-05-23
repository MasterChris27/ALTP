#include "interpreteur.h"

Instruction listInstr[1024];
int indexInst = 0;

//int registers[12];  /* R0 - R11  ....we are only using the first 2*/
int r1,r2;
int memory[1024];     // are we using only int-s ? 
                      //maybe we should make it later for all type of data 

int recursivity[8];    // for how deep we can go in order to return
int indexRecursivity=0;

void add_instruction(char* operation, int a, int b){
	printf("instr added\n");
	Instruction new_inst;        
	strcpy(new_inst.operation, operation);
	new_inst.a = a;
	new_inst.b = b;

	listInstr[indexInst] = new_inst;

	indexInst++;
	
}

int get_memory_value(int tableIndex){
return memory[tableIndex];            // get the value stored at address tableIndex
}

int get_last_inst(void){
	return(indexInst-1);   // index is all the time 1 step forward
}

void printInst(int Index){
	printf("Inst %s a %d b %d \n", listInstr[Index].operation, listInstr[Index].a, listInstr[Index].b); 
}

void execute_all_instructions(){
	for(int i=0; i<indexInst; i++){
	instructionExecute(i);
	printInst(i);         
	}

}





void ExecInstr(int index) {

   switch(listInstr[index].operation) {

		case "ADD" :      // add r1 r2
            r1+=r2;
			break;
		case "SUB" :      //sub r1 r2   --- r1-r2
			r1-=r2;
			break;
		case "MUL" :      //mul r1 r2
			r1*=r2;
			break;
		case "DIV" :      // div r1 r2    --- r1/r2
			r1/=r2;
			break;
		case "STORE" :    // store a b   storing at @a the value of b(register)
           if(listInstr[index].b==1) {//means we use register 1
		   		memory[listInstr[index].a] =r1 ; //this is suposed to be the table
           		//tab_symboles[listInstr[index].a]=r1
				}
			else if(listInstr[index].b=2) {    
				memory[listInstr[index].a] =r2 ; //this is suposed to be the table
           		//tab_symboles[listInstr[index].a]=r2
				}	
			break;
		case "LOAD" :   //load a b  loading register(a) with value from address b

			 if(listInstr[index].a==1) {//means we use register 1
		   		r1=memory[listInstr[index].b] ; //this is suposed to be the table
           		//tab_symboles[listInstr[index].a]=r1
				}
			else if(listInstr[index].a=2) {    
				r2=memory[listInstr[index].b]; //this is suposed to be the table
           		//tab_symboles[listInstr[index].a]=r2
				}	
			break;
		case "AFC" : // I think this1 is allready solved by load as we create a temp variable 
                     //each time we can pass the address and do the "afc" by load
			
			break;
                     //KINDA USELESS FOR ME . WE CAN SOLVE IT WITH ONLY 2 CASES
		case "EQU" :  //EQU a b , if a==b then r1=1 else 0             
			if(r1==r2)         
				r1=1;
			else
				r1=0;
			break;
		case "INF" :
			if(r1<r2)         
				r1=1;
			else
				r1=0;
			break;
		case "INFE" :
			if(r1<=r2)         
				r1=1;
			else
				r1=0;
			break;
		case "SUP" :
			if(r1>r2)         
				r1=1;
			else
				r1=0;
			break;
		case "SUPE" :             
			if(r1>=r2)         
				r1=1;
			else
				r1=0;
			break;

                       //UNTIL HERE  WE CAN HAVE ONLY 2 CASES OF COMPARISON > ==

		case "JMP" :  // jmp a jmp at index a
			//recursivity[indexRecursivity]=indexInst; //  perror here for overflow	
			indexInst=a; // check if need to do a-1		
			break;
		case "JMPC" :  //jmpc a b , if r1= 1   if true/false jump . must make choice !!!!!!!
			if(listInstr[index].a=1)
				indexInst=listInstr[index].b;
			//else we are thinking of how we are connecting if !
		
			break;
		default :

		    // we add some type of error here




     }




}






















void instructionExecute(int index){

	if(strcmp(listInstr[index].operation, "ADD") == 0){
		//registers[ listInstr[index].a ] += registers[listInstr[index].b]; 
		r1+=r2;


	} else if(strcmp(listInstr[index].operation, "SUB") == 0){
		//registers[listInstr[index].a] -= registers[listInstr[index].b] ;
		r1-=r2;


	} else if(strcmp(listInstr[index].operation, "MUL") == 0){
		//registers[listInstr[index].a] *= registers[listInstr[index].b] ;
		r1*=r2;

	} else if(strcmp(listInstr[index].operation, "DIV") == 0){
		/*if( registers[listInstr[index].b] != 0 ){
			registers[listInstr[index].a] /= registers[listInstr[index].b] ;
		}else{
			//registers[listInstr[index].a] = 0;
		}
         */
		r1/=r2;


	} else if(strcmp(listInstr[index].operation, "STORE") == 0){
		//memory[listInstr[index].a] = registers[listInstr[index].b];
       


	} else if(strcmp(listInstr[index].operation, "LOAD") == 0){
		registers[listInstr[index].a] = memory[listInstr[index].b];



	} else if(strcmp(listInstr[index].operation, "AFC") == 0){
		registers[listInstr[index].a] = listInstr[index].b;



	} else if(strcmp(listInstr[index].operation, "EQU") == 0){
		if(registers[listInstr[index].a] == registers[listInstr[index].b]){
			registers[listInstr[index].a] = 1;
		} else{
			registers[listInstr[index].a] = 0;
		}



	} else if(strcmp(listInstr[index].operation, "INF") == 0){
		if(registers[listInstr[index].a] < registers[listInstr[index].b]){
			registers[listInstr[index].a] = 1;
		} else{
			registers[listInstr[index].a] = 0;
		}



	} else if(strcmp(listInstr[index].operation, "INFE") == 0){
		if(registers[listInstr[index].a] <= registers[listInstr[index].b]){
			registers[listInstr[index].a] = 1;
		} else{
			registers[listInstr[index].a] = 0;
		}



	} else if(strcmp(listInstr[index].operation, "SUP") == 0){
		if(registers[listInstr[index].a] > registers[listInstr[index].b]){
			registers[listInstr[index].a] = 1;
		} else{
			registers[listInstr[index].a] = 0;
		}



	} else if(strcmp(listInstr[index].operation, "SUPE") == 0){
		if(registers[listInstr[index].a] >= registers[listInstr[index].b]){
			registers[listInstr[index].a] = 1;
		} else{
			registers[listInstr[index].a] = 0;
		}
	} else if(strcmp(listInstr[index].operation, "JMP") == 0){
		index = registers[listInstr[index].a];



	} else if(strcmp(listInstr[index].operation, "JMPC") == 0){
		if(registers[listInstr[index].b] == 0){
			index= registers[listInstr[index].a];
		}
	} 

}


/*
void main(){

}
*/



