/*5) Faça um programa que leia um nome e escreva o
número de letras que ele possui.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");

    char nome[40];
    int i = 0, soma = 0;

    printf("Escreva um nome: ");
    fgets(nome, 40, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int tamanho = strlen(nome);

    while (i < tamanho)
    {
        if ( nome != ' ')
        {  
            soma++;
        }
        i++;
    }

    printf("Total de letras: %d", soma);
    
    return 0;
}

