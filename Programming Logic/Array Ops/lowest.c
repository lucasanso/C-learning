//Como encontrar o menor valor dentro de um array?

#include <stdio.h>
int findTheLowest(int *v, int size){    //Iremos precisar do vetor em si e do tamanho dele.
    int first = v[0];                   //Postularemos o 'first' como o primeiro valor do vetor.

    for(int i = 0; i < size; i++){      //Percorreremos o vetor com o finco de determinar um valor que seja menor que o 'first' a cada iteracão.
        if(v[i] < first){
            first = v[i];               //Caso haja um valor menor que o first, first assumirá o valor.
        }
    }

    return first;
}

int main(){
    int vector[] = {8, 2, 1, 4, 3, 5};

    int menor = findTheLowest(vector, 6);

    printf("%d", menor);

    return 0;
}