#include <stdio.h>
/* Dato un numero intero n, scrivere un algoritmo che scriva quali e quanti fattori primi ha */

int main()
{   
    int n, r = 0, count = 0;

    while(1){ 
        printf("Inserisci n: ");
        scanf("%d", &n);
        if(n > 0){
            break;
        }
    }

    printf("I suoi fattori primi sono: ");
    for(int i = 2; i <= n;){
        if(n%i == 0){
            printf("%d ",i);
            n = n / i;
            count += 1;
        } else{
            i += 1;
        }
    }

    printf("\nSono %d fattori primi", count);

    return 0;
}
