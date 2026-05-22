/*4) Faça um programa que leia um nome e imprima as
4 primeiras letras.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    char nome[40];
    int i;

    printf("Digite um nome:");
    fgets(nome,40,stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < 4 && nome[i] != '\0'; i++)
    {
        printf("%c", nome[i]);
    }
    
    return 0;
}
