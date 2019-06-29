
//Adrian Gomez Rodriguez
//CS3432
//Lab T-Th from 7:30 to 8:50
//TA: Daniel Cervantes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "history.h"

//int main(void){
// char* x = "The cake is good";
// init_history();
// is_History_Empty(x);
//  free_history(List);
//add_history(List, x);
//print_history(List);
//}

// initialize the linked list to keep the history.
List* init_history(){
  List* list;
  list = (List*) malloc(sizeof(List*));
  list->root == NULL;
  return list;
}

// check if there is something in the history.
bool is_History_Empty(List* list){
  struct s_Item* count = list->root;
  if(list->count == 0){
    return true;
  }
  return false;
}

// add to history
void add_history(List* list, char* str){ 
  List* h = (List*) malloc(sizeof(List*));
  h->list = str;
  if(is_History_Empty(list)){
    h->next = NULL;
    list ->root = h;
  }else{
    h->next = list->root;
    list->root = h;
  }
  list->id++;  
}

//print history
void print_history(List* list){
  int i = 1;
   while(!list->root == NULL){
    List *x = list ->root;
    //  printf("[%d] %s \n", x->str);
    list->root = list->root->next;
    i++;
  }
}
// free items from the history.
void free_history(List* list){
  while(!is_History_Empty(list)){
    List *x = list->root;
    list->id--;
    list->root = list->root->next;
    free(x);
  }
  free(list);
}
