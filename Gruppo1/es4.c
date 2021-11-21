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
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < n; i++){
        for(int a = 0; a < i; a++){
            if(list[a] == list[i]){
                printf("C'e' una coppia uguale di %d \n", list[i]);
            }
        }
    }
    return 0;
}
