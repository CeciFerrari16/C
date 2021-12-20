#include <stdio.h>
#include <string.h>

#define N 8
#define MAXSTR 15

typedef struct {
	int id;
  	char cognome[MAXSTR];
	char nome[MAXSTR];
	int numero_tel;
} s_arch;


s_arch archivio[N]={ // define 6 
	{1,"Rossi", "Mario", 123456789},
	{2,"Verdi", "Ugo", 987654321},
	{3,"Gagliardi", "Giovanni", 135798642},
	{4,"Plutone", "Pippo", 246897531},
};

int MyIndex=4;
//indico il numero di elementi allocati nel vettore archivio


void Visualizza(int pos)
{ int i=0;
while(i<pos){	
 	printf("\n\n     ID:%d", archivio[i].id);
 	printf("\n COGNOME:%s ", archivio[i].cognome);
	printf("\n    NOME:%s ", archivio[i].nome);
	printf("\n    NUMERO TELEFONO:%d ", archivio[i].numero_tel);
	i++;}}

int Insert(int pos)
{
	char invio;
	char c;
	if(pos>=N) {
		printf("\n\nHai raggiunto il limite massimo di elementi ");
		
	scanf("%c", &invio);
	return(pos);
	}
	archivio[pos].id = pos + 1;
	
	printf("\nNuovo Rcd n. %d:", pos);
	printf("\nCOGNOME:");
	scanf("%s",archivio[pos].cognome);
	printf("   NOME:");
	scanf("%s",archivio[pos].nome);
	printf("   NUMERO TELEFONO:");
	scanf("%d", &archivio[pos].numero_tel);
	pos++;
	return(pos);
}

void VisualizzaByCognome(int pos)
{ 
	char cognome[MAXSTR];
	int i=0, trovato=0;
	
	printf("\nQuale cognome cerchi?:");
 	scanf("%s", cognome);
 	
	for (i=0; i<pos; i++){
	 	if(strcmp(archivio[i].cognome,cognome)==0) {
	 		printf("\n\n     ID: %d ", archivio[i].id);
	 		printf("\nCOGNOME: %s ", archivio[i].cognome);
	 		printf("\n   NOME: %s ", archivio[i].nome);
	 		printf("\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
	 		trovato=1;
		 }
 	}
 	if (trovato==0) 
		 printf("\nNon e' presente il cognome cercato:");
}

void VisualizzaByNome(int pos)
{ 
	char nome[MAXSTR];
	int i=0, trovato=0;
	
	printf("\nQuale nome cerchi?:");
 	scanf("%s", nome);
 	
	for (i=0; i<pos; i++){
	 	if(strcmp(archivio[i].nome,nome)==0) {
	 		printf("\n\n     ID: %d ", archivio[i].id);
	 		printf("\nCOGNOME: %s ", archivio[i].cognome);
	 		printf("\n   NOME: %s ", archivio[i].nome);
	 		printf("\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
	 		trovato=1;
		 }
 	}
 	if (trovato==0) 
		 printf("\nNon e' presente il nome cercato:");
}

void VisualizzaByTel(int pos)
{ 
	int tel;
	int i=0, trovato=0;
	
	printf("\nQuale telefono cerchi?:");
 	scanf("%d", tel);
 	
	for (i=0; i<pos; i++){
	 	if(archivio[i].numero_tel == tel) {
	 		printf("\n\n     ID: %d ", archivio[i].id);
	 		printf("\nCOGNOME: %s ", archivio[i].cognome);
	 		printf("\n   NOME: %s ", archivio[i].nome);
	 		printf("\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
	 		trovato=1;
		 }
 	}
 	if (trovato==0) 
		 printf("\nNon e' presente il telefono cercato:");
}

int menu_scelta(void)
{
  int selezione = 0;
  do
    {
    printf("\n" );
    printf("\n0 -> Esci");
    printf("\n1 -> Visualizza Archivio" );
    printf("\n2 -> Inserisci");
    printf("\n3 -> Ricerca da cognome");
    printf("\n4 -> Ricerca da nome");
    printf("\n5 -> Ricerca da telefono");
    printf("\n" );
    printf("\nEffettua una scelta -> " );
    scanf("%d", &selezione );
    }
    while (selezione < 0 || selezione > 3);
  return selezione;
}

int main(void)
{
    int scelta;
    
    while((scelta=menu_scelta())!=0){
    switch(scelta){
        case 1: 
               Visualizza(MyIndex);
               break;
        case 2:
               MyIndex=Insert(MyIndex);
               break;
        case 3:
               VisualizzaByCognome(MyIndex);
               break;
        case 4:
               VisualizzaByNome(MyIndex);
               break;
        case 5:
               VisualizzaByTel(MyIndex);
               break;
            }
    }             
    return 0;
}
