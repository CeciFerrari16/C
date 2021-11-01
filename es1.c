#include <stdio.h>
/*Scrivere un programma che calcoli e restituisca in output la somma dei primi n numeri naturali (con n
inserito da tastiera) */

int main()
{
    int n = 0;
    int somma = 0;
    
    while(1){ // corrispondente del while True
        printf("Inserisci n: ");
        scanf("%d", &n);
        if(n > 0){
            break;
        }
    }

    for (int i = 0; i <= n ; i++)
    {
        somma = somma + i;
    }
    
    printf("La somma e' %d", somma);

    return 0;
}