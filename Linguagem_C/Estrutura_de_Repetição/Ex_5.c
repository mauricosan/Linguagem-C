//5- Fazer um programa que leia um conjunto de valores
//correspondentes às notas que alunos obtiveram em
//uma prova. Quando o valor fornecido for um número
//negativo, significa que não existem mais pontos para
//serem lidos. Após isso seu programa deverá:
//a. Escrever quantas notas são maiores ou iguais a
//6.0
//b. Escrever quantas notas são maiores ou iguais a
//4.0 e menores que 6.0
//c. Escrever quantos notas são menores que 4.0

#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota;
    int maiorIgual6 = 0;
    int entre4e6 = 0;
    int menor4 = 0;

    printf("Digite as notas (numero negativo para parar): ");
    scanf("%f", &nota);

    while (nota >= 0) {

        if (nota >= 6.0) {
            maiorIgual6++;
        } 
        else if (nota >= 4.0) {
            entre4e6++;
        } 
        else {
            menor4++;
        }

        printf("Digite a proxima nota: ");
        scanf("%f", &nota);
    }

    printf("Notas maiores ou iguais a 6.0: %d\n", maiorIgual6);
    printf("Notas maiores ou igual á 4.0 e menor que 6.0: %d\n", entre4e6);
    printf("Notas menor que 4.0: %d\n", menor4);

    return 0;
}