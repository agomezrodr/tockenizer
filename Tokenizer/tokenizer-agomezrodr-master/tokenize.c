
//Adrian Gomez Rodriguez
//CS3432
//Lab T-Th from 7:30 to 8:50
//TA: Daniel Cervantes


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int string_length(char* word);
char is_valid_character(char c);
int find_word_end(char* c);
int find_word_start(char* c);
int count_words(char* c);
void print_tokens(char** c);

int main(void){
  char c [] = "The cake is good";
  printf("The string length is %d \n", string_length(c));
  printf("The index is a valid character %c \n", is_valid_character(c));
  printf("The last index of the word is %d \n", find_word_end(c));
  printf("The first index of the word is %d \n", find_word_start(c));
  printf("The number of words in the string is %d \n", count_words(c));
  print_tokens(c);
  return 0;
}

//Second milestone
// Get the lenght of c
int string_length(char* word){
  if(word != '\0'){
    return strlen(word);
  }else{
    return 0;
  }
}
//find if the character is valid
char is_valid_character(char c){
  while( c != '/0'){
    if(c== ' ' || c== '\t'){
      return '0';
    }else{
      return '1';
    }
  }
}

//find the las index of the sentence
int find_word_end(char* c){
  static int index;
  for ( index = 0; index < strlen(c); index++){
    index++;
    if(is_valid_character(c[index]) ==0){
      index--;
    }
  }
  return index-1;
}
//find the first index of the sentence
int find_word_start(char* c){
  int index;
  for( index = 0; index < strlen(c); index++){
    if(is_valid_character(c[index]) == '1')
      return index;
  }
  return 0;
}

//find how many word are on the sentence
int count_words(char* c){
  char x = ' ';
  int words = 0;
  while(*c){
    if(isspace(x) && !isspace(*c)){
      ++words;
    }
    x = *c++;
  }
  return words;
}
//print each of the words of the sentence on each line
void print_tokens(char** c){
  static char space[] = " \t\f\r\v\n";
  char *token;
  for(token = strtok(c, space);
      token != NULL; token = strtok(NULL, space)){
    printf(" next token is %s\n", token);
  }
}
void free_tokens(char** tokens){
  char **freeTokens = tokens;
  while(*freeTokens != NULL){
    free(*freeTokens);
    *freeTokens = NULL;
    freeTokens++;
  }
  free(tokens);
}

char** tokenizer(char* c){
  char *p;
  p =(char *) malloc(strlen(c)+1);
  if(p != NULL)
    strcpy(p, c);
  return p;
}
