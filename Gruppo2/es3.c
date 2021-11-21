#include <stdio.h>
/* Scrivere una funzione che presi in input 2 numeri a e b, calcoli a^b.*/

int main()
{
    int n1 = 0, n2 = 0;

    printf("Inserisci n1: ");
    scanf("%d", &n1);

    printf("Inserisci n2: ");
    scanf("%d", &n2);

    int risultato = n1;

    for(int i = 1; i < n2; i++){
        n1 = risultato * n1;
    }
    printf("%d \n", n1);

    return 0;
}