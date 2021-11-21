#include <stdio.h>
/* Generare la serie dei quadrati dei primi n numeri naturali (n letto da input).*/

int main()
{
    int n = 0;
    int risultato = 0;

    while(1){
        printf("Inserisci n: ");
        scanf("%d", &n);
        if(n > 0){
            break;
        }
    }

    for (int i = 1; i<= n; i++){
        risultato = i * i;
        printf("%d \n", risultato);
    }

    return 0;
}