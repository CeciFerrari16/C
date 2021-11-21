#include <stdio.h>
/* L’utente inserisce tre numeri interi. 
Il programma deve restituire la differenza tra il più grande e il più piccolo */

int main()
{
    int a, b, c;
    int val_max, val_min, diff;
    printf("Inserisci 3 numeri: ");
    scanf("%d %d %d", &a, &b, &c);

    val_max = a;
    if (val_max < b)
        val_max = b;
    if (val_max < c)
        val_max = c;
    printf("Il maggior numero e' %d \n", val_max);

    val_min = a;
    if (val_min > b)
        val_min = b;
    if (val_min > c)
        val_min = c;
    printf("Il minor numero e' %d \n", val_min);

    diff = val_max - val_min;
    printf("La differenza e' %d", diff);

    return 0;
}
