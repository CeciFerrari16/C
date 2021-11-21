#include <stdio.h>
/*  L’utente inserisce un numero naturale in input. Il programma deve stabilire se il numero è PRIMO */

int main()
{   
    int n, r, c = 0;

    while(1){ 
        printf("Inserisci n: ");
        scanf("%d", &n);
        if(n > 1){
            break;
        }
    }

    for(int i = 1; i <= n; i++){
        r = n%i;
        if(r == 0){
            c += 1;
        }
    }

    if(c <= 2){
        printf("Il numero e' un numero primo");
    } else {
        printf("Il numero NON e' un numero primo");
    }

    return 0;
}
