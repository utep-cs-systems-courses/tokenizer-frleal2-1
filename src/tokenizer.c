#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

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

int non_space_char(char c){
  if(c != '\t' && c != '\n' && c != ' '){
    return 1;
  }
  else{
    return 0;
  }
}

char word_start(char *str){
  while(space_char(*str) == 1 ){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  while(non_space_char(*word) == 1 && *word != '\0'){
    word++;
  }
  return word;
}

int count_words(char *str){
  int counter= 0;
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

char **tokenize(char *str){
  short words_num = count_words(str);
  short word_length = 0;

  char** tokens = (char **)malloc((words_num + 1)*sizeof(char*));

  for(short i = 0; i< words_num; i++){
    char *start = word_start(str); // points to the beginning of a word
    char *end = word_terminator(str); //points to the end of same word
    int word_length = (int)(end-start) + 1; //length of each word
    tokens[i] = copy_str(start, word_length); // allocates all memory and copies all words
    str = word_start(end); //makes the sentence start at the beginning of the next word.
  }
  tokens[words_num] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  while(*tokens){
    printf("[%s] ", *tokens);
    tokens++;
  }
}

void free_tokens(char **tokens){
  char** temp = tokens;
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  free(temp);
}


				

