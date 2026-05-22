/*Classificação de Notas: Você tem as seguintes notas de 10 alunos: 78, 92, 85, 67, 88,
90, 72, 95, 82, 79. Ullize o bubble sort para ordenar as notas em ordem crescente e
escreva a sequência final*/

#include <stdio.h>

void orderingBubble(int *vector, int n){
    int i, j, aux;
    int k = 1;

    for (i = n - 1; i > 0 && k; i--){
        k = 0;
        for (j = 0; j < i; j++){
            if (vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1]; 
                vector[j+1] = aux;

                k = 1;
            }
        }  
    } 
}

int main()
{
    int i;
    int cont = 10;
    int vector[] = {78, 92, 85, 67, 88, 90, 72, 95, 82, 79};

    printf("\n");

    printf("Vetor Inicial:\n");

    for (i = 0; i < cont; i++){
        printf("[%d] ", vector[i]);
    }

    printf("\n");

    orderingBubble(vector, cont);
    printf("\nVetor Ordenado:\n");

    for (i = 0; i < cont; i++){
        printf("[%d] ", vector[i]);
    }

    printf("\n");
    printf("\n");

    return 0;
}
