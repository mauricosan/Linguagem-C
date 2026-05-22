#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 40

typedef struct
{
    int codigo, dependentes;
    char nome[tam], cargo[tam];
    float salario;
} funcionarios;

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int j = 0, i;

    printf("Quantos funcionarios deseja preencher?: ");
    scanf("%d", &j);
    getchar(); // limpa o enter

    funcionarios loja[j];

    for (i = 0; i < j ; i++)
    {
        printf("\nDigite o nome da %d pessoa: ", i + 1);
        fgets(loja[i].nome, tam, stdin);

        printf("Digite o codigo da %d pessoa: ", i + 1);
        scanf("%d", &loja[i].codigo);
        getchar();

        printf("Digite o cargo da %d pessoa: ", i + 1);
        fgets(loja[i].cargo, tam, stdin);

        printf("Digite o numero de dependentes da %d pessoa: ", i + 1);
        scanf("%d", &loja[i].dependentes);

        printf("Digite o salario da %d pessoa: ", i + 1);
        scanf("%f", &loja[i].salario);
        getchar();
    }

    printf("\n--- DADOS ORIGINAIS ---\n");

    for(i = 0; i < j; i++)
    {
        printf("\nFuncionario %d\n", i+1);
        printf("Nome: %s", loja[i].nome);
        printf("Codigo: %d\n", loja[i].codigo);
        printf("Cargo: %s", loja[i].cargo);
        printf("Dependentes: %d\n", loja[i].dependentes);
        printf("Salario: %.2f\n", loja[i].salario);
    }

    // ATUALIZAR DADOS
    printf("\n--- ATUALIZAR DADOS ---\n");

    for(i = 0; i < j; i++)
    {
        printf("\nNovo cargo do funcionario %d: ", i+1);
        fgets(loja[i].cargo, tam, stdin);

        printf("Novo salario do funcionario %d: ", i+1);
        scanf("%f", &loja[i].salario);
        getchar();
    }

    printf("\n--- DADOS ATUALIZADOS ---\n");

    for(i = 0; i < j; i++)
    {
        printf("\nFuncionario %d\n", i+1);
        printf("Nome: %s", loja[i].nome);
        printf("Codigo: %d\n", loja[i].codigo);
        printf("Cargo: %s", loja[i].cargo);
        printf("Dependentes: %d\n", loja[i].dependentes);
        printf("Salario: %.2f\n", loja[i].salario);
    }

    return 0;
}