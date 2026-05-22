//3- Faça um programa para mostrar a tabuada dos
//números de 1 a 10.

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int x = 1; 
    while (x < 11)
    {
        int y = 0;
        while (y < 11)
        {
            printf("%d x %d = %d\n", x,y,x*=y);
            y ++;
        }
        x++;
        printf("\n");
    }

    system("pause");
    return 0;
}