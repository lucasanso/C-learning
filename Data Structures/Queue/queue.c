#include <stdio.h>
#include <stdlib.h>

//lógica: first-in first-out. operações de imserção e remoção somente.

typedef struct cx{
    int num;
    struct cx *ant;
}Queue;

void imprimirFila(Queue *fila){
    while(fila != NULL){
        printf("%d ", fila->num);
        fila = fila->ant;
    }
}

void insereFila(Queue **fila, int n){ //sempre início
    Queue *new = malloc(sizeof(Queue));
    if(!new){
        printf("Erro.\n");
        return;
    }
    new->num = n;
    new->ant = NULL;
    if(*fila == NULL){
        *fila = new;
    } else {
        Queue *aux = *fila;
        while(aux->ant != NULL){
            aux = aux->ant;
        }
        aux->ant = new;
    }
}

void removerFila(Queue **fila){ //sempre início
    if(*fila == NULL){
        printf("A fila está vazia.\n");
    }
    Queue *aux = *fila;
    *fila = (*fila)->ant;
    free(aux);
}



int main(){
    Queue *filosa = NULL;

    insereFila(&filosa, 10);
    insereFila(&filosa, 15);
    insereFila(&filosa, 20);
    removerFila(&filosa);
    imprimirFila(filosa);

    return 0;
}
