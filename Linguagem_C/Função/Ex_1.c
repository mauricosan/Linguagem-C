/* 1- Faça uma função chamada calcularSerie() que
calcule e apresente os primeiros 8 termos da série a
seguir.

Soma = 100/0! + 99/1! + 98/2! + 97/3! + ...

A função deverá chamar outra função que receba um
inteiro >= 0 como parâmetro e retorne o seu fatorial,
para calcular cada termo da série. A função deverá
apresentar cada termo da série, calcular a soma total
dos termos e retornar a soma, para ser impressa pelo
programa principal */

#include <stdio.h>
#include <stdlib.h>

int calcularfat(int n){

    int fat = 1, i = 1;
    while (i <= n )
    {
        fat = fat * i;
        i++;
    }

    return fat;

    }

float calcularserie(int N){
    float soma = 0;
    int i = 0;

    while (i < N)
    {
        float termo = (100 - i) / (float) calcularfat(i);
        printf("%.2f\n", termo);

        soma = soma + termo;
        i++;

    }
    return soma;
}

int main(){

    float resultado = calcularserie(8);
    printf("Soma total = %.2f\n", resultado);

    return 0;
}