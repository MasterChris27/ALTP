#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///features
// add_symbol 	ok
// return_val - give name and profondeur - get val -- removed
// delete_symbol - give name and profondeur - remove symbol   removed
// delete_symbol - remove last symbol
// find symbol - give name, and profondeur, get table index
// get_last_address
// symbol_initialise - give address, mark var as initialised

int global_id = 0;


int add_symbol(char* name, char* type,  int initialise, int profondeur) { 


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

	
	
    tempTable = tempTable->next;
  }
}

  
  //if(check_sym(name,profondeur)) add the function here if going to implement one
  entry* new = malloc(sizeof(entry));
  new->name = malloc(sizeof(name));
  new->type = malloc(sizeof(type));
  new->name = name;
  new->type = type;
  new->id = global_id;
  global_id++;
  new->initialise = initialise;
  new->next = tab_symbols;
  new->profondeur = profondeur;
  tab_symbols = new;
  //print_table();
  // add more here

  return 1;
}

void symbol_initialise(int index) {
entry* current = tab_symbols;


  while(current != NULL)
  {
		if(current->id == index)
		{
		current->initialise = 1;
		break;
		}
  current = current->next;
  }
}

/*int return_val(char* nameArg, int profondeur) {

   entry* current = tab_symbols;


 while(current != NULL){
    if((current->name != NULL) && (strcmp(current->name,nameArg) == 0))
	{
		if((current->profondeur == profondeur))
		{
			printf("Found the element\n");
			return current->value;
		
	 	}
	} else
	{
	current = current->next;
	}
  
	
  }
  return -1;



}*/

/*int delete_symbol_name(char* nameArg, int profArg) {
  entry* current = tab_symbols;
  entry* previous = tab_symbols;


  while(current != NULL){
    if((strcmp(current->name,nameArg) == 0) && (current->profondeur == profArg))
	{
		printf("Found the element, removing\n");
		global_id--;
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
*/

char* get_variable_name(int tableIndex){
   	entry* current = tab_symbols;
	for(int i = 0; i<global_id-tableIndex-1; i++){
	current = current->next;
	}
	return current->name;
}

 int find_symbol(char* nameArg, int profondeur){

   entry* current = tab_symbols;
   int index = 0;

 while(current != NULL){
    if((current->name != NULL) && (strcmp(current->name,nameArg) == 0))
	{
		if((current->profondeur == profondeur))
		{
			return current->id;
		
	 	}
	} else
	{
	current = current->next;
    index++;
	}
  
	
  }
  return -1;



}

void add_temporary_symbol() {

add_symbol(NULL, "int", 0, 0);
}

/*

int delete_all_current_profondeur(){

 entry* current = tab_symbols;
 int curr_prof = current->profondeur;

 while(current != NULL){
		if((current->profondeur == curr_prof)){
			printf("Found the element\n");
			entry* tmp = tab_symbols;
			tab_symbols = tab_symbols->next;	
			free(tmp);
			global_id--;
	 	}else{
			current = current->next;
    		index++;
			}	
  	}

return 1
}
*/

int delete_symbol() {
entry* tmp = tab_symbols;
tab_symbols = tab_symbols->next;	
free(tmp);
global_id--;
return 1;
}

//************************************ get_last_address() ok

int get_last_index(){

  return global_id-1;
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
  print_table();
// delete_symbol("a",1);
add_temporary_symbol();
// printf("%d\n", find_symbol("b"));

 //if(delete_symbol("b",1)==-1)
//	printf("err at deleting\n");

  print_table();
}
*/

