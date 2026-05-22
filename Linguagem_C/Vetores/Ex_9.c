/*Faça um programa que simule um jogo da loto. O computador deve gerar 5
números aleatoriamente entre 50 possíveis (0 a 49), armazenando as dezenas
sorteadas em um vetor (dez_sort) de 5 posições. Em seguida, o usuário deverá ler
um vetor com 10 posições, representando a aposta (conforme o exemplo abaixo).
O programa deve, então, verificar e imprimir uma mensagem mostrando quantos
números o usuário acertou. De acordo com o exemplo abaixo o usuário acertou 4
dezenas.*/

#include <stdio.h>

int main()
{
    int aleatorio[5], sorteio[10];
    int numero = 25;
    int i, j, acertos = 0;

    
    for(i = 0; i < 5; i++)
    {
        numero = numero * 3 + 1;
        aleatorio[i] = numero % 50;
    }

    for (i = 0; i < 10; i++)
    {
        printf("Digite o %d° valor: ", i + 1);
        scanf("%d", &sorteio[i]);
    }
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (sorteio[i] == aleatorio[j])
            {
                acertos++;
            }
        }
    }

    printf("\nVocê acertou %d números!\n", acertos);

    printf("\nNúmeros sorteados:\n");
    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", aleatorio[i]);
    }

    printf("\nSeus números:\n");
    for (i = 0; i < 10; i++)
    {
        printf("[%d] ", sorteio[i]);
    }

    printf("\n");

    return 0;
}