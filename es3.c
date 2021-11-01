#include <stdio.h>
/*  Ricevuti in input 3 numeri, dire se c’è almeno una coppia di numeri uguali e mostrarli */

int main()
{
    int a, b, c, count = 0;
    printf("Inserisci 3 numeri: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a == b && a == c){
        printf("I numeri sono tutti uguali \n");
        count = 2;
    } else if(a == b){
        printf("%d e %d sono uguali \n", a, b);
        count ++;
    } else if(a == c){
        printf("%d e %d sono uguali \n", a, c);
        count ++;
    } else if(c == b){
        printf("%d e %d sono uguali \n", c, b);
        count ++;
    } else{
        printf("I numeri sono tutti diversi \n");
    }

    printf("Le coppie uguali di numeri sono %d", count);

    return 0;
}