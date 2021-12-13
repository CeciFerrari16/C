#include <stdio.h>
/* Scrivere un programma che, preso in input un array di dimensione n, 
generi un secondo array che non contenga i duplicati. */

int main()
{
    int n, count = 0, n1;

    printf("Quanti numeri vuoi inserire?");
    scanf("%d", &n);

    int list[n];
    int d[n];

    for(int i = 0; i < n; i++){
        printf("Qual e' il numero maggiore di 0 in indice %d: ", i);
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < n; i++){
        d[i] = -1;
    }

    for(int i = 0; i < n ; i++){
        n1 = 0;
        for(int a = i + 1; a < n; a++){
            //printf("La coppia: %d e %d \n", list[i], list[a]);
            if(list[i] == list[a]){
                for(int j = 0; j < n; j++){
                    if(count == 0 && d[j] == -1){
                        d[j] = list[i];
                        count += 1;
                    }
                }
                list[a] = -1;
                count = 0;
                n1 = 1;
            }
        }
        if(n1 == 0){
            for(int j = 0; j < n; j++){
                if(count == 0 && d[j] == -1){
                    d[j] = list[i];
                    count += 1;
                }
            }count = 0;
        }
    }
    printf("Ecco l'array senza numeri uguali: ");
    for(int i = 0; i < n; i++){
        if(d[i] >= 0){
            printf("%d, ", d[i]);
        }
    }
    
    return 0;
}