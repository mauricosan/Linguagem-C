/*Faça um programa em C que crie um vetor com 500 números inteiros gerados aleatoriamente. Em seguida,
o programa deverá solicitar um valor do usuário a ser
buscado no vetor e verificar se o mesmo pertence ou não ao vetor, imprimindo a mensagem ao usuário. O programa deverá implementar duas funções de buscano vetor: sequencial e binária. Para realizar a busca binária, você deverá criar o seu próprio algoritmo de ordenação.
Obs: compare o número de comparações realizadas por
cada estratégia para encontrar o elemento procurado.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 500

void randomNumbers(int vector[], int size){
    int i;

    srand(time(NULL));

    for (i = 0; i < size ; i++)
    {
        vector[i] = rand() % 500;
    }
}

void ordering(int vector[], int size){
    int i, j;
    int aux;

    for (i = 0; i < size; i++){
        for (j = 0; j < size - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            } 
        }
    }
}

int search(int vector[], int value, int start, int end){
    int quite;
    if (start > end){
        return - 1;
    }

    quite = (start + end) / 2;

    if (value == vector[quite])
    {
        return quite;
    }
    
    if (value > vector[quite])
    {
        return search(vector, value, start, end);
    }

    return search(vector, value, start, end - 1);
}

int main() {

    int vector[TAM];
    int number;
    int result;
    int i;

    randomNumbers(vector, TAM);

    ordering(vector, TAM);

    for(i = 0; i < TAM; i++){
        printf("%d ", vector[i]);
    }

    printf("\ndigite o numero que deseja buscar: ");
    scanf("%d", &number);

    result = search(vector, number, 0, TAM - 1);

    if(result != -1){
        printf("\nnumero encontrado na posicao %d", result);
    } else {
        printf("\numero nao encontrado");
    }

    return 0;
}
