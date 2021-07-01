#include "history.h"
#include "stdlib.h"
#include "stdio.h"

List* init_history(){
  List* history;
  history = (List*)malloc(sizeof(List));
