/*A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre salário, sexo, idade e numero de filhos.

 Crie um registro capaz de armazenar os dados de um habitante e defina um vetor com capacidade para até 20 habitantes.

 Crie um programa para ler os dados de cada habitante,calcular e mostrar: – A média de salários da população; – O número médio de filhos; – O maior salário e o menor salário; – O percentual de mulheres com salário superior a R$1.500,00. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{   
    float salario;
    char sexo;
    int idade, filhos;
} Registro;

int main(){   
    int i = 0, j;
    float somaSalario = 0, mediaSalario = 0;
    int somaFilhos = 0;
    float mediaFilhos = 0;
    int contMulheres = 0;
    float percentualMulheres = 0;
    float maiorSalario = 0, menorSalario = 0;

    printf("Deseja preencher os dados de quantos habitantes?: ");
    scanf("%d", &j);

    Registro habitantes[j];

    while (i < j){   
        printf("Digite o salario do %dº habitante: ", i + 1);
        scanf("%f", &habitantes[i].salario);

        printf("Digite o sexo do %dº habitante (F/M): ", i + 1);
        scanf(" %c", &habitantes[i].sexo);

        while (habitantes[i].sexo != 'F' && habitantes[i].sexo != 'M'){
            printf("ERRO! Digite 'F' ou 'M': ");
            scanf(" %c", &habitantes[i].sexo);
        }

        printf("Digite a idade do %dº habitante: ", i + 1);
        scanf("%d", &habitantes[i].idade);

        printf("Digite o numero de filhos do %dº habitante: ", i + 1);
        scanf("%d", &habitantes[i].filhos);

        i++;
    }

    maiorSalario = habitantes[0].salario;
    menorSalario = habitantes[0].salario;

    for (i = 0; i < j; i++){
        somaSalario += habitantes[i].salario;
        somaFilhos += habitantes[i].filhos;

        if (habitantes[i].salario > maiorSalario){
            maiorSalario = habitantes[i].salario;
        }

        if (habitantes[i].salario < menorSalario){
            menorSalario = habitantes[i].salario;
        }

        if (habitantes[i].sexo == 'F' && habitantes[i].salario > 1500){
            contMulheres++;
        }
    }

    mediaSalario = somaSalario / j;
    mediaFilhos = (float)somaFilhos / j;
    percentualMulheres = (contMulheres * 100.0) / j;

    printf("\n------ RESULTADOS ------\n");
    printf("Media de salarios: %.2f\n", mediaSalario);
    printf("Media de filhos: %.2f\n", mediaFilhos);
    printf("Maior salario: %.2f\n", maiorSalario);
    printf("Menor salario: %.2f\n", menorSalario);
    printf("Percentual de mulheres com salario > 1500: %.2f%%\n", percentualMulheres);

    return 0;
}



