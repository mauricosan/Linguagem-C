/*7) Faça um programa que leia um nome completo e o
imprima de duas formas: com todas as letras em
minúsculas e com todas as letras em maiúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char nome[50];
    char minusculas[50];
    char maiusculas [50];
    
    printf("Digite seu nome completo:");
    fgets(nome,50,stdin);

    nome[strcspn(nome,"\n")] = '\0';

    strcat(maiusculas, nome);
    strlwr(minusculas);

    strcat(minusculas, nome);
    strupr(maiusculas);

    printf("\nNome Maisculo: %s ", maiusculas);
    printf("\nNome Minusculo: %s ", minusculas);

    return 0;
}