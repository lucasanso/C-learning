//Como encontrar o maior elemento de um vetor?

int findTheHigher(int *v, int size){    //Será necessário o vetor e o tamanho como parâmetros.
    int first = v[0];                   //Postularemos 'first' como o primeiro elemento do vetor.

    for(int i = 0; i < size; i++){
        if(v[i] > first){               //Se existir um elemento do vetor maior que 'first', 'first' receberá esse valor.
            first = v[i];
        }
    }

    return first;
}

#include <stdio.h>

int main(){
    int vector[] = {5, 2, 1, 3, 9, 11, 99, 192};

    printf("%d", findTheHigher(vector, 8));
    return 0;
}

