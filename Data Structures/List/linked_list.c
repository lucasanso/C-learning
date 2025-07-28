#include <stdio.h>
#include <stdlib.h>

typedef struct bx{
    int n;
    struct bx *ant;
    struct bx *prox;
}CAIXA;

void imprimeLista(CAIXA *lista){
    if(lista == NULL){
        printf("A lista está vazia.\n");
    }
    while(lista != NULL){
        printf("%d ", lista->n);
        lista = lista->prox;
    }
}

void insere_no_comeco (CAIXA **lista, int n){
    CAIXA *new = malloc(sizeof(CAIXA));
    if(!new){
        printf("An error was ocorred.\n");
        return; 
    }
    new->ant = NULL;
    new->n = n;
    
    if(*lista == NULL){
        new->prox = NULL;
        *lista = new;
    } else {
        new->prox = *lista;
        (*lista)->ant = new;
        *lista = new;
    }
}

void insere_no_fim(CAIXA **lista, int n){
    CAIXA *new = malloc(sizeof(CAIXA));

    if(!new){
        printf("An error was ocorred.\n");
        return;
    }

    new->prox = NULL;
    new->n = n;

    if(*lista == NULL){
        new->ant = NULL;
        *lista = new;
    } else {
        CAIXA *aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = new;
        new->ant = aux; //correção, não estava atualizando o ponteiro legal aqui.
    }
}

void remover_do_inicio(CAIXA **lista){ //dois caso, lista vazia e mais de um elemento.
    if(*lista == NULL){
        printf("Não há mais elementos a serem removidos.\n");
        return;
    } else {
        CAIXA *aux = *lista;
        printf("Elemento %d removido da lista.\n", (*lista)->n);
        *lista = (*lista)->prox;
        if(*lista != NULL){
            (*lista)->ant = NULL;
        }
        free(aux);
    }
}

void remover_do_final(CAIXA **lista){   //há os três casos, lista vazia, elemento único e múltiplos elementos.
    if(*lista == NULL){
        printf("Não há mais elementos a serem removidos.\n");
        return;
    } else {
        CAIXA *aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        if(aux->ant == NULL){
            *lista = NULL;
            free(aux);
        } else {
            CAIXA *ref = aux->ant;
            ref->prox = NULL;
            free(aux);
        }
    }
}

void remover_arbitrario(CAIXA **lista, int el){ //lista vazia, elemento único e mais de um elemento (entre elementos).
    if(*lista == NULL){
        printf("Não há elementos a serem removidos.\n");
        return;
    } else {
        CAIXA *aux = *lista;
        while(aux->prox != NULL){
            if(aux->n == el){
                printf("Elemento encontrado.\n");
                break;
            } else {
                aux = aux->prox;
            }
        }
        if(aux->n != el){
            printf("Elemento não encontrado.\n");
        } else {
            CAIXA *ref = aux, *ref2 = aux;
            if(ref->ant == NULL){
                remover_do_inicio(lista);
            } else if(ref2->prox == NULL){
                remover_do_final(lista);
            } else if(aux->ant == NULL && aux->prox == NULL) {
                *lista = NULL;
                free(aux);
            } else {
                ref = aux->ant;
                ref2 = aux->prox;
                ref->prox = ref2;
                ref2->ant = ref;

                free(aux);
            }
        }
    }
}

void menu(){
    printf("Seja bem-vindo a lista do Luquinhas.\n\n1 - Insere elemento no início.\n2 - Insere elemento no final.\n3 - Imprime lista.\n");
    printf("4 - Remover elemento do início.\n5 - Remover elemento do final.\n6 - Remover elemento escolhido.\n0 - Sair.\n\n");
}

int main(){
    CAIXA *lista = NULL; 
    int op;
    menu();
    while(scanf("%d", &op)){
        int elemento;
        menu();
        switch(op){
            case 1:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &elemento);
                insere_no_comeco(&lista, elemento);
                printf("Número %d adicionado na lista.\n", elemento);
                menu();
                break;
            case 2:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &elemento);
                insere_no_fim(&lista, elemento);
                printf("Número %d adicionado na lista.\n", elemento);
                menu();
                break;
            case 3:
                printf("Números adicionados na lista:\n\n");
                imprimeLista(lista);
                printf("\n\n");
                menu();
                break;
            case 4:
                remover_do_inicio(&lista);
                break;
            case 5:
                remover_do_final(&lista);
                break;
            case 6:
                printf("Digite o elemento que deseja remover.\n");
                scanf("%d", &elemento);
                remover_arbitrario(&lista, elemento);
                menu();
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}
