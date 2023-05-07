#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
 List* list=createList();
 State* current_state = n->state;
 int current_row = current_state->row;
 int current_col = current_state->col;
 
 // Aplicar acción 1: Insertar un número en la celda
 for(int num=1; num<=9; num++){
     State* new_state = clone_state(current_state);
     if(insert_number(new_state, current_row, current_col, num)){
         Node* new_node = create_node(new_state, n);
         addNode(list, new_node);
     } else {
         free_state(new_state);
     }
 }
 
 // Aplicar acción 2: Eliminar número de la celda
 State* new_state = clone_state(current_state);
 if(delete_number(new_state, current_row, current_col)){
     Node* new_node = create_node(new_state, n);
     addNode(list, new_node);
 } else {
     free_state(new_state);
 }
 
 // Aplicar acción 3: Intercambiar fila
 for(int i=0; i<9; i++){
     if(i != current_row){
         State* new_state = clone_state(current_state);
         if(swap_row(new_state, current_row, i)){
             Node* new_node = create_node(new_state, n);
             addNode(list, new_node);
         } else {
             free_state(new_state);
         }
     }
 }
 
 // Aplicar acción 4: Intercambiar columna
 for(int i=0; i<9; i++){
     if(i != current_col){
         State* new_state = clone_state(current_state);
         if(swap_col(new_state, current_col, i)){
             Node* new_node = create_node(new_state, n);
             addNode(list, new_node);
         } else {
             free_state(new_state);
         }
     }
 }
   
   return list;
}

int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/