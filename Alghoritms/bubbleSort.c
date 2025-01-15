//Ordenacão em Bolha! Nela comparamos elementos 2 a 2 (bolha) e sempre trocando caso o primeiro valor for maior que o segundo.

#include <stdio.h>

void swap(int *a, int *b){                      	//Precisaremos do endereco dos dois inteiros que serão trocados de lugar.
    int n = *a;
    *a = *b;
    *b = n;
}

void bubbleSort(int *v, int size){
    for(int i = 0; i < size - 1; i++){              //Iremos percorrer apenas sizeVector - 1 pois estamos comparando elementos 2 a 2, logo a última iteracão é redundante.
        for(int j = 0; j < size - i - 1; j++){      //Aqui decrementamos i quando tivermos comparado para que não sejam feitas comparacoes desncessarias. +desempenho.
            if(v[j] > v[j+1]){
                swap(&v[j], &v[j+1]);
            }
        }
    }
}

int main(){
    int vector[] = {9, 7, 8, 6, 5, 4, 3, 2, 1};     //OBS: Esse é o pior caso para a ordenacão crescente do Bubble!

    printf("Vector elements before sorting with Bubble: \n");

    for(int i = 0; i < 9; i++){
        printf("%d ", vector[i]);
    }
    puts("\n");

    bubbleSort(vector, 9);

    printf("Elements have been sorted!\n");

    for(int i = 0; i < 9; i++){
        printf("%d ", vector[i]);
    }

    puts("\n");

    return 0;
}