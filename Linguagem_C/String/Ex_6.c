/*6) Faça um programa que leia o nome e o sobrenome
de uma pessoa separadamente. O programa deve
juntar as duas strings em uma só e escrever na tela:
a nova string, o seu número de caracteres, a sua
primeira e a última letra.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");

    char nome[40], sobrenome[40];
    char espaco[2] = {' ', '\0'};
    int i = 0, soma = 0, tamanho = 0;

    printf("Digite um nome: ");
    fgets(nome, 40, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite um sobrenome: ");
    fgets( sobrenome, 40, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    strcat(nome, espaco);    
    strcat(nome, sobrenome);

    while (i < 40 && nome[i] != '\0')
    {
        if (nome[i] != ' ')
        {
            soma = soma + 1;
        }
        i++;
    }

    printf("%s", nome);
    printf("\nPrimeira Letra: %c", nome[0]);
    printf("\nUltima Letra: %c", nome[i - 1]);
    printf("\nQuatidade de letras: %d", soma);
    
    
    return 0;
}
