#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j;
    // Iterar sobre todas las casillas del tablero
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            // Si la casilla está vacía
            if(n->sudo[i][j]==0){
                int k;
                // Intentar colocar un número en la casilla vacía
                for(k=1;k<=9;k++){
                    if(is_valid(n, i, j, k)){ // Si la colocación es válida
                        Node* new_node = copy(n);
                        new_node->sudo[i][j] = k; // Actualizar el tablero con el nuevo número
                        pushBack(list, new_node); // Agregar el nuevo nodo a la lista de adyacentes
                    }
                }
                return list; // Como sólo se puede colocar un número en una casilla, se devuelve la lista en este punto
            }
        }
    }
    return list; // En caso de que el tablero ya esté completo, se devuelve la lista vacía
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