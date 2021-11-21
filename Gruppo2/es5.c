#include <stdio.h>
/* Scrivere un programma che, preso in input un array di dimensione n, 
generi un secondo array che non contenga i duplicati. */

int main()
{
    int n = 0, count = 0;

    printf("Quanti numeri vuoi inserire?");
    scanf("%d", &n);

    int list[n];
    int d[n];

    for(int i = 0; i < n; i++){
        printf("Qual e' il numero in indice %d: ", i);
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < n; i++){
        d[i] = list[i];
    }

    for(int i = 0; i < n; i++){
        for(int a = 0; a < i; a++){
            if(list[a] == list[i]){
                printf("C'e' una coppia uguale di %d \n", list[i]);
                for(int i = 0; i < n; i++){
                    if(list[i] == d[i]){
                        d[i] = d[i + 1];
                    }else if(list[i] == d[i + 1]){
                        d[i] = d[i + 1];
                    }
                }
                count += 1;
            }
        }
    }
    int n1 = n - count; 

    printf("Ecco l'array senza numeri uguali: ");
    for(int i = 0; i < n1; i++) {
        printf("%d, ", d[i]);
    }
    
    return 0;
    // problema se metto 2 coppie di numeri uguali di seguito
}