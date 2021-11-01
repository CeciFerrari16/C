#include <stdio.h>
/* Scrivere una funzione che stampi la serie di Fibonacci per i primi n numeri interi (n inserito
dall’utente) */

int main()
{
    int n = 0;
    int a = 0;
    int b = 1;
    int c = 0;
    
    while(1){ 
        printf("Inserisci n: ");
        scanf("%d", &n);
        if(n > 0){
            break;
        }
    }

    while(a + b <= n){
        c = a + b;
        a = b; 
        b = c;
        printf("%d ", c);
    }

    return 0;
}