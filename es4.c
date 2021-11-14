#include <stdio.h>
/* Ricevuti in input n numeri, dire se c’è almeno una coppia di numeri uguali e mostrarli */

int main()
{
    int n = 0, a = 0;
    printf("Quanti numeri vuoi inserire?");
    scanf("%d", &n);

    int list[n];

    for(int i = 0; i < n; i++){
        printf("Qual e' il numero in indice %d: ", i);
        scanf("%d", &a);
    }

    for(int b = 0; b > n; b++){
        for(int a = 0; a > b; a++){
            if(list[a] == list[b]){
                printf("C'è una coppia uguale di %d \n", list[b]);
            }
        }
        a = 0;
    }
    return 0;
}