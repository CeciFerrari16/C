#include <stdio.h>
#include <stdbool.h>
/* Scrivere una funzione che trovi e restituisca il massimo di un array di interi.*/

int main()
{
    bool check;
    int n, count = 0;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    int list[n];

    for(int i = 0; i < n; i++){
        printf("Qual e' il numero in indice %d: ", i);
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < n; i++){
        for(int a = 0; a < n; a++){
            if(list[i] > list[a]){
                count += 1;
            }
        }
        // printf("%d ", count);
        if(count == n - 1){
            printf("Il numero massimo di tutto l'array e' %d", list[i]);
        }
        count = 0;
    }
    return 0;
}