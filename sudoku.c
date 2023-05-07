#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List* get_adj_nodes(Node* n) {
    List* list = createList();
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (n->sudo[i][j] == 0) {
                for (int k = 1; k < 10; k++) {
                    Node* nuevo = createNode();
                    *nuevo = *n;
                    nuevo->sudo[i][j] = k;
                    if (is_valid(nuevo)) {
                        pushBack(list, nuevo);
                    } else {
                        free(nuevo);
                    }
                }
                return list;
            }
        }
    }
    
    return list;
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