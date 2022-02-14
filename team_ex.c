#include <stdio.h>
#include <string.h>

#define N 10
#define MAXSTR 15
#define RUBRICA "AGENDA.txt"

typedef struct {
	int id;
  	char cognome[MAXSTR];
	char nome[MAXSTR];
	int numero_tel;
} s_arch;


s_arch archivio[N]={ // define 10 
	{1,"Rossi", "Mario", 123456789},
	{2,"Verdi", "Ugo", 987654321},
	{3,"Gadioli", "Giovanni", 135798642},
	{4,"Plutone", "Pippo", 246897531},
};

int MyIndex=4;
//indico il numero di elementi allocati nel vettore archivio
int MyOut(int);
int Leggi(int);

void Visualizza(int pos)
{
int i=0;
while(i<pos)
{	
 	printf("\n\n     ID:%d", archivio[i].id);
 	printf("\n COGNOME:%s ", archivio[i].cognome);
	printf("\n    NOME:%s ", archivio[i].nome);
	printf("\n    NUMERO TELEFONO:%d ", archivio[i].numero_tel);
	i++;
	}
}

int MyOut(int pos)
{
  FILE *out;
  out = fopen(RUBRICA,"w+"); //apertura del file write
  for(int i=0; i < pos; i++){
    if (out)
      {
        fprintf(out, "\n\n     ID: %d ", archivio[i].id);
        fprintf(out, "\nCOGNOME: %s ", archivio[i].cognome);
        fprintf(out, "\n   NOME: %s ", archivio[i].nome);
        fprintf(out, "\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
        
        printf("Sono passato di quii");
        return 0;
        }
    else
      {
        printf("Errore apertura file");
        return -1;
      }
  }fclose(out);
}

int Leggi(int pos)
{
  FILE *read;
  read = fopen(RUBRICA,"r");
  for(int i=0; i < pos; i++){
    if (read)
      { 
        printf("\n\n     ID: %d ", archivio[i].id);
        fscanf(read, "%d", &archivio[i].id);
        printf("\nCOGNOME:");
        fscanf(read, "%s",archivio[i].cognome);
        printf("   NOME:");
        fscanf(read, "%s",archivio[i].nome);
        printf("   NUMERO TELEFONO:");
        fscanf(read, "%d", &archivio[i].numero_tel);

        printf("\n\n     ID: %d ", archivio[i].id);
        printf("\nCOGNOME: %s ", archivio[i].cognome);
        printf("\n   NOME: %s ", archivio[i].nome);
        printf("\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
        return 0;
      }
    else
      {
        printf("Errore apertura file");
        return -1;
      }
  }fclose(read);
}

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
	
	printf("\nNuovo Rcd n. %d:", pos + 1);
	printf("\nCOGNOME:");
	scanf("%s",archivio[pos].cognome);
	printf("   NOME:");
	scanf("%s",archivio[pos].nome);
	printf("   NUMERO TELEFONO:");
	scanf("%d", &archivio[pos].numero_tel);
	pos++;
	return(pos);
}

void Scambia(int i, int j)
{
  s_arch tmp;
  
  tmp.id = archivio[i].id;
  archivio[i].id = archivio[j].id;
  archivio[j].id = tmp.id;
  
  strcpy(tmp.cognome, archivio[i].cognome);
  strcpy(archivio[i].cognome, archivio[j].cognome);
  strcpy(archivio[j].cognome, tmp.cognome);
  
  strcpy(tmp.nome, archivio[i].nome);
  strcpy(archivio[i].nome, archivio[j].nome);
  strcpy(archivio[j].nome, tmp.nome);
  
  tmp.numero_tel = archivio[i].numero_tel;
  archivio[i].numero_tel = archivio[j].numero_tel;
  archivio[j].numero_tel = tmp.numero_tel;
}

void SortByCognome(int pos)
{   
    //int list[pos];
    int t;
    for(int i = 0; i < pos; i++){
        for(int v = i+1; v < pos; v++){
			//printf("%d\n", strcmp(archivio[i].cognome, archivio[v].cognome));
    	    if(strcmp(archivio[i].cognome, archivio[v].cognome) > 0){
    	        Scambia(i, v);
    	    }
        }
	}
	Visualizza(MyIndex);
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
 	scanf("%d", &tel);
 	
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
    printf("\n3 -> Ordina per cognome");
    printf("\n4 -> Ricerca da cognome");
    printf("\n5 -> Ricerca da nome");
    printf("\n6 -> Ricerca da telefono");
    printf("\n7 -> Salva");
    printf("\n8 -> Leggi");
    printf("\n" );
    printf("\nEffettua una scelta -> " );
    scanf("%d", &selezione );
    }
    while (selezione < 0 || selezione > 8);
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
                SortByCognome(MyIndex);
                break;
        case 4:
                VisualizzaByCognome(MyIndex);
                break;
        case 5:
                VisualizzaByNome(MyIndex);
                break;
        case 6:
                VisualizzaByTel(MyIndex);
                break;
        case 7:
                MyOut(MyIndex);
                break;
        case 8:
                Leggi(MyIndex);
                break;
        }
    }             
    return 0;
}
