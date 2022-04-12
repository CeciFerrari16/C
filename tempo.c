/* Esempio di programma base da completare
per il test statistico dell'algoritmo 
di ordinamento per selezione 
Gruppo: Gioia Caliceti, Cecilia Ferrari, Xinyu Jiang*/

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

int Salva(char *f, int elem, double tempSel){
    FILE *out;
    out = fopen(f,"a+"); //apertura del file write
    
    if (out){ 
        fprintf(out, "\n%d;%f", elem, tempSel); 
        fclose(out);
        return 0;
    }
    else
    {
       printf("Errore apertura file");
       return -1;
    }
}

void Scambia(int a, int b){
    int i,tmp;
    if (test > -1) printf("\n(Scambio %d else %d)", V[a],V[b]);
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
                //Visualizza(n);
                }
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
    double tempSels = 0, tempSelb = 0;
    
    for(elem = 1000;elem < N; elem += 1000){
        InsRnd(elem);
    
        //printf("\nVettore[%d] inserito Random ",elem);
        //Visualizza(elem);
    
        clock_t begins = clock(); // Inizio misurazione tempo
        printf("\nOrdinamento selezione");
        OrdinaSel(elem);
        clock_t ends = clock();// Fine Misurazione tempo impiegato da OrdinaSel
        
        tempSels += (double)(ends - begins) / CLOCKS_PER_SEC;
        Salva("SEL.txt", elem, tempSels);
        
        //printf("\nVettore[%d] ordinato ",elem);
        //Visualizza(elem); 
    }
    
    for(elem = 1000;elem < N; elem += 1000){
        InsRnd(elem);
        
        clock_t beginb = clock();
        printf("\nOrdinamento bubble");
        OrdinaBubble(elem);
        clock_t endb = clock();
        
        tempSelb += (double)(endb - beginb) / CLOCKS_PER_SEC;
        Salva("BUB.txt", elem, tempSelb);
        
        //printf("\n%d;%f", elem, tempSel); // Visualizzare il tempo impiegato (tempSel)
    }
    return 0;
}
