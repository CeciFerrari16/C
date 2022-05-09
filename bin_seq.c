#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include <math.h> 
#define N 100 // N Massimo Numero Elementi 

int V[N];// Vettore di interi per il test
int WANTED;

void Incremento(int min, int inc){
    for(int i=0; i < N; i++){
        V[i] = min + inc*i;
    }
}

void Visualizza(int n) {
    for (int i=0; i<n; i++ ){
        printf("%d ", V[i]); 
    }
}

int Ricerca(int WANTED, int inf, int sup){
    int MEDIO;
    while(1){
        MEDIO = lround((inf + sup)/2);
        printf("\ninf: %d\nsup: %d\n medio: %ld", inf, sup, MEDIO);

        if(WANTED < V[inf] || WANTED > V[sup]){
            printf("\nIl numero %d non e' presente nel vettore", WANTED);
            return 1;
        }else if((sup - inf) <= 3){
            for(int i = inf; i <= sup; i++){
                if(WANTED == V[i]){
                    printf("\nIl numero %d ha indice %d", WANTED, i);
                    return 0;
                }
            }
            printf("\nIl numero %d non e' presente nel vettore", WANTED);
            return 1;
        }else if(WANTED == V[MEDIO]){
            printf("\nIl numero %d ha indice %ld", WANTED, MEDIO);
            return 0;
        }else if(WANTED < V[MEDIO]){
            sup = MEDIO - 1;
        }else if(WANTED > V[MEDIO]){
            inf = MEDIO + 1;
        }
    }
}

int Salva(char o[8], int elem, double tempSel){
    FILE *out;
    out = fopen("OUT.txt","a+"); //apertura del file write
    
    if (out){ 
        fprintf(out, "\n%s %d;%f", o, elem, tempSel); 
        fclose(out);
        return 0;
    }
    else
    {
       printf("Errore apertura file");
       return -1;
    }
}

void Tempo(int elem, int n){
    double tempSel = 0;
    printf("\nOrdinamento selezione");
    //OrdinaSel(elem);

    clock_t begins = clock(); // Inizio misurazione tempo
    //Visualizza(elem);
    //RicercaSel(elem);
    clock_t ends = clock();// Fine Misurazione tempo impiegato da OrdinaSel
    
    tempSel += (double)(ends - begins) / CLOCKS_PER_SEC;
    Salva("SEL:", elem, tempSel);
}

int main(){
    Incremento(0,2);
    printf("\nInserire un numero naturale da cercare:");
    scanf("%d", &WANTED);
    
    Ricerca(WANTED, 0, N-1);
    
    printf("\n");
}