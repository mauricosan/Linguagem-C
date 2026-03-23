//2- Faça um programa que receba um número inteiro
//maior que 1 e verifique se o número é primo. Considere que um número primo é divisível apenas por
//1 e por ele mesmo.
//Obs: Faça três versões do programa, uma para
//cada estrutura de repetição (for, while e do- while).

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i = 2, primo = 1;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while (num <= 1) {
        printf("ERRO! O numero deve ser maior que 1.\n");
        printf("Digite um numero: ");
        scanf("%d", &num);
    }

    while (i < num) {
        if (num % i == 0) {
            primo = 0;
        }
        i++;
    }

    if (primo == 1)
        printf(" O número é primo.");
    else
        printf("O numero nao é primo");

    return 0;
}