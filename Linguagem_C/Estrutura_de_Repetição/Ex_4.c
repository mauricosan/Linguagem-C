#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i = 1;
    int fat = 1;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num < 0) {
        printf("ERRO! Digite um numero maior que 0: ");
        scanf("%d", &num);
    }

    while (i <= num) {
        fat *= i;
        i++;
    }

    printf("Fatorial de %d = %d", num, fat);

    return 0;
}