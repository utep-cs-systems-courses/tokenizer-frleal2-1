#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

void read_input();
void tokenize_mode();

int main(){
  printf("Welcome to Felipe's tokenizer \n");
  printf("/e: will exit the program.\n");
  printf("/t: will enter the tokenizing mode.\n");
  printf("/h: will print HELP\n");
  read_input();
}

void read_input(){ //This is the basic UI for the program. it will give options for input reading.

  char com[100];
  
  while(1){
    printf("#");
    scanf("%s", com);

    if(com[0] == '/'){
      if(com[1] == 'e'){
	break;
      }
      else if(com[1] == 't'){
	printf("Entering tokenizing mode\n");
	tokenize_mode();
      }
      else if(com[1] == 'h'){
	printf("/e: will exit the progrma.\n");
	printf("/t: will enter the tokenizing mode.\n");
	printf("/h will print HELP.\n");
      }
      else{
	printf("Command not recognized.\n");
      }
    }
    else{
      printf("%s \n", com);
    }
  }
}

void tokenize_mode(){

  char com[100];
  List * history = init_history();
  char ** tokens;

  while(1){
    printf("Enter string to tokenize all words or /e to quit or /l# for history access:\n");
    // printf("sca
    scanf(" %99[^\n]s", com);
    // printf("scanning\n");
    if(com[0] == '/'){
      if(com[1] == 'e'){
	break;
      }
      else if(com[1] == 'l'){
	printf("Searching for ID %d \n", com[2] - '0');
	tokens = tokenize(get_history(history, com[2] - '0'));
	print_tokens(tokens);
      }
      else{
	printf("Command not recognized.\n");
      }
    }
    else{
      //printf("tokenizing");
      tokens = tokenize(com);
      //printf("done");
      print_tokens(tokens);
      add_history(history,com);
      free_tokens(tokens);
    }
    printf("\n");
  }
}

      
