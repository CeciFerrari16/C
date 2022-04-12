/* Confronto algoritmi di ricerca
Gruppo: Gioia Caliceti, Cecilia Ferrari, Xinyu Jiang*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include <math.h> 
#define N 10000 // N Massimo Numero Elementi 

int V[N];// Vettore di interi per il test
int num = 8;

void Visualizza(int n) {
    for (int i=0; i<n; i++ ){
        printf("%d ", V[i]); 
    }
}

int Ricerca(int elem){
    int count = 0;
    for(int i=0; i < elem; i++){
        if(V[i] == num){
            count += 1;
            printf("\nLa posizione e' %d", i);
        }
    }
    if(count == 0){
        printf("\nIl numero non e' presente nel vettore");
        return -1;
    }
}

int RicercaSel(int elem){
    int count = 0;
    for(int i=0; i < elem; i++){
        if(V[i] == num){
            count += 1;
            printf("\nLa posizione e' %d", i);
        }else if(V[i] > num && count == 0){
            printf("\nIl numero non e' presente nel vettore");
            return -1;
        }else if(V[i] > num){
            return 0;
        }
    }
}

void InsRnd(int n){ // elem
    int i, MyRand;
    srand(time(0)); // casuale 
    for(int i=0; i<=n; i++ ){
        MyRand=rand() % n;
        V[i] = MyRand; }
}

void Scambia(int a, int b){
    int i,tmp;

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
    printf("\nVettore[%d] inserito Random", elem);
    if(n == 0){
        double tempSel = 0;
        //printf("\nOrdinamento selezione");
        OrdinaSel(elem);

        clock_t begins = clock(); // Inizio misurazione tempo
        printf("\nVettore:");
        Visualizza(elem);
        RicercaSel(elem);
        clock_t ends = clock();// Fine Misurazione tempo impiegato da OrdinaSel
        
        tempSel += (double)(ends - begins) / CLOCKS_PER_SEC;
        Salva("SEL:", elem, tempSel);
        
    }else if(n == 1){
        double temp = 0;
        //printf("Vettore non ordinato\n");

        clock_t begin = clock(); // Inizio misurazione tempo
        printf("\nVettore:");
        Visualizza(elem);
        Ricerca(elem);
        clock_t end = clock();// Fine Misurazione tempo impiegato da OrdinaSel
        
        temp += (double)(end - begin) / CLOCKS_PER_SEC;
        Salva("N.O.:", elem, temp);
    }
}

int main(){
    for(int elem = 1000;elem < N; elem += 1000){
        InsRnd(elem);
        Tempo(elem, 1);
        Tempo(elem, 0);
        printf("\n");
    }
}
