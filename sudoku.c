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
  int i, j, k, p;
  int a[9]={0};
  
  // validación de filas
  for(i=0; i<9; i++){
    memset(a, 0, sizeof(a)); // reseteo del arreglo, está función inicializa todo en 0
    for(j=0; j<9; j++){
      if(n->sudo[i][j]!=0){
        if(a[(n->sudo[i][j]-1)]==0){
          a[(n->sudo[i][j]-1)]=1;
        }
        else return 0;
      }
    }
  }
  
  // validación de columnas
  for(j=0; j<9; j++){
    memset(a, 0, sizeof(a)); 
    for(i=0; i<9; i++){
      if(n->sudo[i][j]!=0){
        if(a[(n->sudo[i][j]-1)]==0){
          a[(n->sudo[i][j]-1)]=1;
        }
        else return 0;
      }
    }
  }
  
  // validación de submatrices
  for(k=0; k<9; k++){
    memset(a, 0, sizeof(a)); 
    for(p=0; p<9; p++){
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;
      if(n->sudo[i][j]!=0){
        if(a[(n->sudo[i][j]-1)]==0){
          a[(n->sudo[i][j]-1)]=1;
        }
        else return 0;
      }
    }
  }
  
  return 1;
}



List* get_adj_nodes(Node* n){
  List* list = createList();
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (n->sudo[i][j] == 0){
        for (int k = 1; k < 10; k++){
          Node* nuevo = createNode();
          *nuevo = *n;
          nuevo->sudo[i][j] = k;
          if (is_valid(nuevo)){
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


int is_final(Node* n){  
  for (int i = 0; i < 9; i++){
    for (int j= 0; j < 9; j++){
      if (n->sudo[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack *S=createStack();
  push(S,initial);
  while (get_size(S)!=0){
    Node *n=top(S);
    pop(S);
    if (is_final(n)) return n;
    List * adj=get_adj_nodes(n),
    node * aux=first (adj);
    while(aux){
      push(S,aux);
      aux=next(adj);
    }
  }
  *cont++;
  free(n);
  free(initial);
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