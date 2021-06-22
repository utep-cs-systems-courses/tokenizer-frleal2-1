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

