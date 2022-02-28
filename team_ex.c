// Gruppo: Gioia Caliceti, Cecilia Ferrari, Xinyu Jiang
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // serve per atoi()

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
int check = -1; //check per vedere se è stato salvato
int MyOut(int);
int Leggi(int);

void Visualizza(int pos)
{
int i=0;
//Leggi(pos);
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
  out = fopen(RUBRICA,"w"); //apertura del file write

  if (out)
    { 
      fprintf(out, "%d ", pos);
      for(int i=0; i < pos; i++){
        fprintf(out, "%d ", archivio[i].id);
        fprintf(out, "%s ", archivio[i].cognome);
        fprintf(out, "%s ", archivio[i].nome);
        fprintf(out, "%d ", archivio[i].numero_tel);
      }
      fclose(out);
      check = 0;
      return 0;
    }
  else
    {
      printf("Errore apertura file");
      return -1;
    }
}

int Leggi(int pos)
{
  FILE *read;
  char tot[N];
  char id[N];
  char cognome[MAXSTR];
  char nome[MAXSTR];
  char numero_tel[MAXSTR];
  int numero_tel_prec;
  read = fopen(RUBRICA,"r");
  
  if (read)
    { 
      fscanf(read, "%s ", tot);
      MyIndex = atoi(tot);
      for(int i=0; i < pos; i++){
        fscanf(read, "%s %s %s %s", id, cognome, nome, numero_tel);
        if(numero_tel_prec != atoi(numero_tel)){
          archivio[i].id = atoi(id);
          strcpy(archivio[i].cognome, cognome);
          strcpy(archivio[i].nome, nome);
          archivio[i].numero_tel = atoi(numero_tel);
          numero_tel_prec = atoi(numero_tel);
        }
      }

      fclose(read);
      return 0;
    }
  else
    {
      printf("Errore apertura file");
      return -1;
    }
}

void Update(int pos){
  FILE *file;
  file = fopen(RUBRICA,"a");
  int c = fgetc(file);
  fclose(file);

  if(c != EOF){
    Leggi(pos);
    Leggi(MyIndex);
  }
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
  check = -1;
	
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

int Delete(int pos)
{ 
  int id;
  printf("Quale contatto desideri eliminare?\n");
  printf("Inserisci l'id:");
  scanf("%d", &id);

  if(id <= pos && id > 0){
    for(int i = 0; i < pos; i++){
      if(id == archivio[i].id){
        archivio[i].id = 0;
        strcpy("", archivio[i].cognome);
        strcpy("", archivio[i].nome);
        archivio[i].numero_tel = 0;
        return 0;
      }
    }
  }else{
    printf("Il contenuto inserito non e' valido\n");
    return -1;
  }
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
    int t;
    for(int i = 0; i < pos; i++){
        for(int v = i+1; v < pos; v++){
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
		 printf("\nNon e' presente il cognome cercato");
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
		 printf("\nNon e' presente il nome cercato");
}

void VisualizzaByTel(int pos)
{ 
	int tel;
	int i=0, trovato=0;
	
	printf("\nQuale telefono cerchi?:");
 	scanf("%d", &tel);
 	
	for (i=0; i<pos; i++){
	 	if(archivio[i].numero_tel == tel){
	 		printf("\n\n     ID: %d ", archivio[i].id);
	 		printf("\nCOGNOME: %s ", archivio[i].cognome);
	 		printf("\n   NOME: %s ", archivio[i].nome);
	 		printf("\n   NUMERO TELEFONO: %d ", archivio[i].numero_tel);
	 		trovato=1;
		}
 	}
 	if (trovato==0) 
		 printf("\nNon e' presente il telefono cercato");
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
    printf("\n9 -> Elimina un contatto");
    printf("\n" );
    printf("\nEffettua una scelta -> " );
    scanf("%d", &selezione );
    }
    while (selezione < -1 || selezione > 9);
  return selezione;
}

int main(void)
{
  int scelta;
  char ans[1];
  Update(MyIndex);//come aggiornamento

  while((scelta=menu_scelta()) != -1){ //corrisponde al while True in py
  switch(scelta){
      case 0: 
              if(check == -1){
                printf("Non hai salvato\n");
                printf("Sei sicuro di volere uscire? y/n\n");
                scanf("%s", ans);
                if(strcmp(ans, "n") == 0){
                  break;
                }else{
                  return 0;
                }
              }else{
                return 0;
              }
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
              Visualizza(MyIndex);
              break;
      case 9:
              Delete(MyIndex);
              printf("Sono passato qui");
              break;
      }
  }             
  return 0;
}