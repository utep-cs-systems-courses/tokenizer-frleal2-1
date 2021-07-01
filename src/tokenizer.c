#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

/*Evaluates weather a character is valid*/
int space_char(char c){
  switch(c){
    case '\n':
    case '\t':
    case ' ':
      return 1;
    default:
      return 0;
  }
}

/*Evaluates weather a character is invalid*/
int non_space_char(char c){
  if(c != '\t' && c != ' ' && c != '\n'){
     return 1;
  }
  else{
    return 0;
  }  
}

/*Function to find the start of a word*/

char *word_start(char *str){
  while(space_char(*str) == 1){
    str++;
  }  
  return str;
}

/*Function to find the end of a word*/
char *word_terminator(char *word){
  while(non_space_char(*word) == 1 && *word != '\0'){
    word++;
  }
  return word;
}

/*Function to find the number of words there is in a sentence or sentence*/
int count_words(char *str){
  int counter = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    counter++;
  }
  return counter;
  
}

char *copy_str(char *inStr, short len){
  char *tokens = (char *)malloc(sizeof(char) * (len + 1));
  
  int i = 0;
  while(i < len && inStr[i] != '\0'){
    tokens[i] = inStr[i];
    i++;
  }
  tokens[len] = '\0';
  return tokens;
}

char** tokenize(char* str){
  short words_num = count_words(str);
  short word_leng =0;
  char** tokens = (char**) malloc((words_num+1)*sizeof(char*));//we allocate memory for the number of pointers needed
  printf("memory allocated");
  for(short i=0;i<words_num;i++){ //we will calculate length of each string and allocate memory for each
    
    char *start = word_start(str); //pointer at the beginning of a word.
    
    char *end = word_terminator(str);  //pointer at the end of a word.
    
    int word_leng = (int)(end - start) + 1; //This computes the lenght of each word.
    printf("word  length calculated");
    
    tokens[i] = copy_str(start, word_leng); //allocates the memory for all the words and copies each word into a token.
    
    printf("tokenized");l
      
    str = word_start(end);  //Makes the sentence start at the beggining of the next word.
    
    //tokens[i][word_leng] = '\0';
    
  }
  tokens[words_num] = '\0';
  return tokens;
}

/* Function that prints all tokens*/
void print_tokens(char** tokens){
  while(*tokens){
    printf("[%s]   ", *tokens);
    tokens++;
  }
}

/*Function that frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
  char** temp = tokens;
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  free(temp);
}

/*Function that tokenizes the string that is passed on to the argument into an array of tokens*/

