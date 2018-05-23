#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///features
// add_symbol
// return_val - give name and profondeur - get val
// delete_symbol - give name and profondeur - remove symbol
// delete_symbol_address - give address and remove symbol
// address space (space btween addresses in table) = 128
// find symbol - give name, and profondeur, get address
// get_last_address
// symbol_initialise - give address, mark var as initialised


int add_symbol(char* name, char* type,  int value, int initialise, int profondeur) { 

	int i=0;
  entry* tempTable = tab_symbols;


	//printf(tempTable->name);
if(name!=NULL){  
	while(tempTable != NULL) {
    if(strcmp(tempTable->name,name) == 0 ){    //case var name already exists
      if(tempTable->profondeur == profondeur){		
	     printf("Error: Variable name in same profondeur already exists\n");
	return -1;
      }
		
    }

	
	i++;
    tempTable = tempTable->next;
  }
}


  //if(check_sym(name,profondeur)) add the function here if going to implement one
  entry* new = malloc(sizeof(entry));
  new->name = malloc(sizeof(name));
  new->type = malloc(sizeof(type));
  new->name = name;
  new->type = type;
  new->id = i;
  new->initialise = initialise;
  new->next = tab_symbols;
  new->profondeur = profondeur;
  tab_symbols = new;
  print_table();
  // add more here

  return 1;
}

void symbol_initialise(int address) {
entry* current = tab_symbols;


  while(current != NULL)
  {
		if(&(*current) == address)
		{
		current->initialise = 1;
		}
  current = current->next;
  }
}

int return_val(char* name, int profondeur) {
	entry* tempTable = tab_symbols;
	while(tempTable != NULL) {
		if(strcmp(tempTable->name,name) == 0 )
		{  
		if(tempTable->profondeur == profondeur) {
		return tempTable->value;
		}
		}
	}
	return -1;
}	

int delete_symbol(char* nameArg, int profArg) {
  entry* current = tab_symbols;
  entry* previous = tab_symbols;


  while(current != NULL){
    if((strcmp(current->name,nameArg) == 0) && (current->profondeur == profArg))
	{
		printf("Found the element, removing\n");
		if(current != tab_symbols){
			previous->next = current->next;
			free(current);
			print_table();
			return 1;
		} else {
			tab_symbols = tab_symbols->next;
			return 1;
		}

	printf("Var %s\n",current->name);
	} else{
	printf("Var %s\n",current->name);
	previous = current;
	current = current->next;
	}
	
  }
  return -1;
}


 int* find_symbol(char* nameArg, int profondeur){
printf("find syn table started\n");
   entry* current = tab_symbols;

 printf("&&& &1\n");
 while(current != NULL){
    if((current->name != NULL) && (strcmp(current->name,nameArg) == 0))
	{
		if((current->profondeur == profondeur))
		{
			printf("Found the element\n");
			return &(*current);
		
	 	}
	} else
	{
	current = current->next;
	}
  
	
  }
  return -1;



}

void add_temporary_symbol() {

add_symbol(NULL, "int", NULL, 0, 0);
}

int delete_symbol_address(int address) {
printf("test"); 
 entry* current = tab_symbols;
  entry* previous = tab_symbols;


  while(current != NULL)
  {
	printf("current address currentNEXT %d\n", &(*(current->next)));
	printf("current address currentNEXT %d\n", &(*(current->next->next)));
	printf("current address prev %d\n", &(*previous));
    if(current == address)
	{
		printf("Found the element, removing\n");

		if(current != tab_symbols){
			previous->next = current->next;
			free(current);
			return 1;
		} else {
			entry* tmp = tab_symbols;
			tab_symbols = tab_symbols->next;	
			free(tmp);
			return 1;
		}

	
	} else{
	
	previous = current;
	current = current->next;
	}
	
  }
  return -1;



}

//************************************ get_last_address() ok

int get_last_address(){
printf("Last address in Table function\n");
  return &(*tab_symbols);
}

//************************************

//************************************ print_table() ok 

void print_table(){ //possibly add table as in param
  entry* temporaryTable = tab_symbols;
  printf("| ID name type initialise profondeur|\n");
  while(temporaryTable != NULL){
    printf("\n| %d %s %s %d %d |\n", temporaryTable->id, temporaryTable->name, temporaryTable->type, temporaryTable->initialise, temporaryTable->profondeur);
    temporaryTable = temporaryTable->next;
  } 

//************************************

}

/*
int main() {

printf("entered main\n");
  add_symbol("a", "int", 1, 0, 1);
  add_symbol("a", "int", 1, 0, 2);
  add_symbol("b", "int", 2, 0, 1);
  add_symbol("c", "int", 3, 1, 1);
  add_symbol("d", "int", 4, 0, 1);
  add_symbol("a", "int", 1, 0, 2);
  print_table();
// delete_symbol("a",1);
add_temporary_symbol();
add_temporary_symbol();
printf("%d\n", get_last_address());
// printf("%d\n", find_symbol("b"));

 //if(delete_symbol("b",1)==-1)
//	printf("err at deleting\n");

  print_table();
}
*/

