/* 6 - Faça um programa que solicite do usuário 10 valores inteiros em ordem crescente (faça a
verificação para garantir que a entrada esteja ordenada) e armazene em um vetor. Em seguida, o
programa deverá perguntar ao usuário qual valor ele deseja remover do vetor e proceder com a
remoção do elemento. O programa deverá imprimir o vetor antes e após a remoção do elemento.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz_principal[10];

    printf("Digite o 1° número da matriz: ");;
    scanf("%d", &matriz_principal[0]);

    int i = 1;

    while (i < 10)
    {
        printf("Digite o %d° número da matriz: ", i + 1);
        scanf("%d", &matriz_principal[i]);

        if (matriz_principal[i] > matriz_principal[i-1])
        {
            i++; 
        }
        else {
            printf("ERRO!O número seguinte deve ser maior que o número anterior! \n");
        }
    }

    i = 0;
    printf("\nMatriz Principal: \n");
    while (i < 10)
    {
        printf("%d ", matriz_principal[i]);;
        i ++;
    }

    int valor;

    printf("\nDigite o valor que deseja remover:\n");
    scanf("%d", &valor);

    char confirm;

    printf ("Deseja remover o valor %d?(s/n): ",valor);
    scanf(" %c", &confirm);


    while (confirm != 's' && confirm != 'n')
    {
        printf("\nERRO! Digite 's' para sim ou 'n' para não.\n");
        printf ("Deseja remover o valor %d?(s/n): ",valor);
        scanf(" %c", &confirm);
    }
    
    if (confirm == 's')
    {
    int posicao = -1; 

    while (i < 10)
    {
        if (matriz_principal[i] == valor && posicao == -1) 
        {
            posicao = i;
        }
        i++;
    }

     if (posicao == -1) 
    {
         printf("Valor não encontrado.\n");
    }
    else

    i = posicao;
    {
        while (i < 9)
        {
            matriz_principal[posicao] = matriz_principal[posicao + 1];
            i++;
        }
    }

    printf("Vetor Atualizado:\n");
    i = 0;
    while (i < 9)
    {
        printf("%d ", matriz_principal[i]);
        i++;
    }
    }
    else
    {
    return 0;
    }
}