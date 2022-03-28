/* Esempio di programma base da completare
per il test statistico dell'algoritmo 
di ordinamento per selezione */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include <math.h> 
#define N 10000 // N Massimo Numero Elementi 

int V[N]; // Vettore di interi per il test

const int test=-1; // Flag, se test = -1 scrive gli scambi

void Visualizza(int n) {
    if (test > -1){
        for (int i=0; i<n; i++ ){
            printf("%d ", V[i]); 
        }
    }
}

void InsRnd(int n){ // elem
    int i,MyRand;
    srand(time(0)); // casuale 
    for (int i=0; i<=n; i++ ){
        MyRand=rand() % n;  //Se commentata questa istruzione e include <time.h> allora risultato pseudo 
        //rand funzione restituisce intero casuale compreso tra 0 e il max 
        V[i] = MyRand; }
// Inserisce nel vettore V e B numeri casuali da 1 a n
}

void Scambia(int a, int b){
    int i,tmp;
    if (test > -1) printf("(Scambio %d else %d)", V[a],V[b]);
    tmp=V[a]; 
    V[a]=V[b]; 
    V[b]=tmp;
}


void OrdinaSel(int n) { // Ordinamento per selezione 
    int x, y, i_min;
    int temp;
    for(x = 0; x < n - 1; x++){
        i_min = x;
        for(y = x + 1; y < n; y++)
            if(V[y] < V[i_min])
                i_min = y;
        if(x != i_min){
            Scambia(i_min, x);
            if(test > -1){
                Visualizza(n);}
        }
    }
}

void OrdinaBubble(int n) { // Ordinamento Bubble 
    int x, y, i_min; 
    int temp; 
    for (x = 0; x < n; x++){
        for (y = x + 1; y < n; y++){
            if (V[x] > V[y]){
                Scambia(x, y);
                if (test > -1){
                    Visualizza(n); }
            }
        }
    }
}

int main() {
    int elem;
    double tempSel = 0.0;
    printf ("Inserire elementi test max[%d] " ,N);
    scanf("%d",&elem);
    InsRnd(elem);

    if(test > -1){
        printf("\nVettore[%d] inserito Random\n",elem);
        Visualizza(elem);
    }

    clock_t begin = clock(); // Inizio misurazione tempo
    //printf("\nOrdinamento bubble\n");
    OrdinaBubble(elem);   //funzione da cronometrare
    //printf("\nOrdinamento selezione");
    //OrdinaSel(elem);
    clock_t end = clock();// Fine Misurazione tempo impiegato da OrdinaSel

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    tempSel += (double)(end - begin) / CLOCKS_PER_SEC;

    if(test > -1){
        printf("\nVettore[%d] ordinato\n",elem);
        Visualizza(elem); 
    }

    printf("\n%d;%f", elem, tempSel); // Visualizzare il tempo impiegato (tempSel)
    return 0;
}
