/*5- Faça um programa que crie uma matriz A dedimensão m x n e 
outra matriz B de dimensão n x p.
O programa deverá calcular e apresentar a 
multiplicação de A por B, como segue no exemplo:*/


# include <stdio.h>
# include <stdlib.h>

int main (){
    int m,n,p;
    int i,j,k;

    printf("Digite m e n da matriz A: ");
    scanf("%d %d", &m,&n);

    printf("Digite p da matriz B: ");
    scanf("%d", &p);

    int A[m][n], B[n][p], C[m][p];

    printf("Digite os elementos da matriz A: ");
    for (i = 0; i <m; i++)
    {
        for (j = 0; i < n; j++)
        {
            scanf("%d", &A[i][j]);
        }  
    }

    printf ("Digite os elementos da matriz B: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p ; j++)
        {
            C[i][j] = 0;
        }
    }
    
    //multiplicacao

    for (i = 0; i < m; i++)
    {
        for ( j = 0; j < p; j++)
        {
            for (k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                
            }
        }
    }

    printf("Resultado da matriz A x B: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}