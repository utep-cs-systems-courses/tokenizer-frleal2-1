#include <stdio.h>

void read_input();

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
    printf('#');
    scanf("%s", com);

    if(com[0] == '/'){
      if(com[1] == 'e'){
	break;
      }
      else if(com[1] == 't'){
	printf("Entering tokenizing mode\n");
	tokenizing_mode();
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
    printf("Enter string to tokenize all words or /e to quit or /l# for history access:");
    scanf(" %99[^\n]s", com);
    if(com[0] == '/'){
      if(com[1] == 'e'){
	break;
      }
      else if(com[1] == 'l'){
	printf("Searching for ID %d \n", com[2] - '0');
	//here we find id of history annd get tokens.
      }
      else{
	printf("Command not recognized.\n");
      }
    }
    else{
      //here we tokenize the string
    }
  }
}

      
