/*2- Crie um programa principal que implemente funções
para:

a) Receber por parâmetro um vetor de números
inteiros e um valor N indicando o seu tamanho e
preencher o vetor com valores fornecidos pelo
usuário. 

b) Receber por parâmetro um vetor de números
inteiros e um valor N indicando o seu tamanho e
imprimir os elementos do vetor.

c) Receber um vetor de números inteiros e um valor
N indicando o seu tamanho e retornar a soma de
todos os elementos do vetor.

d) Receber por parâmetro um vetor de números
inteiros e seu tamanho e inverter a ordem dos
elementos do vetor.*/

#include <stdio.h>
#include <locale.h>

void funcaoA(int N[], int tamanho){

    int i = 0;

    while (i < tamanho)
    {
        printf("Digite o %d° valor do vetor: ", i + 1);
        scanf("%d", &N[i]);
        i++;
        
    }
}

void funcaoB(int vetor[], int N){

    int i = 0;

    while (i < N)
    {
        printf("[%d] ", vetor[i]);
        i++;
    }
}

int funcaoC(int vetor[], int N){

    int i = 0;
    int soma = 0;

    while (i < N)
    {
       soma = soma + vetor[i];
       i++;
    }

    return soma;
    
}

void funcaoD(int vetor[], int N){
    int i = N - 1;

    while (i >= 0)
    {
        printf("[%d]", vetor[i]);
        i--;
    }
    
}

int main(){   

    setlocale(LC_ALL, "");
    int N;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &N);

    int vetor[N];

    printf("\n\nFunção de Preenchimento do vetor\n\n");
    funcaoA(vetor, N);

    printf("\n\nFunção de Impressão:\n");
    funcaoB(vetor, N);

    int soma = funcaoC(vetor, N);
    printf("\n\nSoma do Vetor: \n"); funcaoB(vetor,N);
    printf(" = [%d]\n", soma);

    printf("\nFunção do Vetor Inverso:\n");
    funcaoD(vetor, N);
    
    printf(" \n ");

    return 0;
}
