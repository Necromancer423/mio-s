//Gabriele Marra 5Binf
//01/11/2024
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <conio.h>
#include "windows.h"
#include <ctime>
#include "Variabili.cpp"
#include "miefunzioni.cpp"

using namespace std;
	
void create();
int scelta(int nOpz);
void menuPrinc();
void menuGest();
void menuStamp();
void menuIns();
void menu();
void intesta();
void stampContatto(int x, int y);
void insCog(int x, int y);
void insNom(int x, int y);
void insData(int x, int y);
void insNumero(int x, int y);	
void scrittura();
void scambia();
void FileToVet();	
void lettura();
void ricMat();
void ricPos();
void ricCog();
void ricNom();
void modifica();
void cancella();
void stampCron();
void stampAlf();




FILE *archivio, *archApp;	
int totRec, ultMat;	
char nome_file[20]="rubrica.seq";	
char app_file[20]="rubrica.key";
	
int matricola;
char nome[11]="nome1234aa";
char cognome[11]="cognome123";
char data[11]="24/02/5654";
char numero[11]="1234567890";			

//Vettori per il riordino
char vetCog[100][11], vetNom[100][11], vetDat[100][11], vetNum[100][11];


int main()
{	impVideo();
	if (access("rubrica.seq",00)) //controlla se è presente il file della rubrica
   { 	create(); } 		//crea il file
	else //legge numero di contatti e Ultima matricola
	{	archApp=fopen("rubrica.key","r");
		fscanf(archApp, "%d %d", &totRec, &ultMat);
		fclose(archApp);
	}
	
	menu();
	
	
    gotoxy(0,22);
    return 0;
}
 
 void create()
 {	archivio = fopen(nome_file, "w"); 	//crea rubrica.seq
 	archApp = fopen(app_file, "w");		//crea rubrica.key
 	fprintf(archApp, "0 0");
 	_fcloseall();
 }

int scelta(int nOpz)
{	int scelta;
	do{																		//inserimento Scelta
		gotoxy(25, 18);printf("Inserisci la tua scelta:   ");
		fflush(stdin);
		gotoxy(50, 18);scanf("%d", &scelta);
		if(scelta<=0||scelta>nOpz)
		{	gotoxy(20,23);printf("Scelta non accettabile!!");}	
	}while(scelta<=0||scelta>nOpz);
	gotoxy(25, 17);printf("                                            ");
	gotoxy(20,23);printf("                          ");
	return scelta;
}

void menuPrinc()
{	cornice(29,4,54,8);
	gotoxy(30,5);printf("1. Gestione Nominativi");
	gotoxy(30,6);printf("2. Riepiloghi");
	gotoxy(30,7);printf("3. Fine");
}

void menuGest()
{	menuPrinc();
	clear(33,6,60,15);
	cornice(33,6,60,15);
	gotoxy(34,7);printf("1. Inserire contatto");
	gotoxy(34,8);printf("2. Ricerca per matricola");
	gotoxy(34,9);printf("3. Ricerca per posizione");
	gotoxy(34,10);printf("4. Ricerca per cognome");
	gotoxy(34,11);printf("5. Ricerca per Nome");
	gotoxy(34,12);printf("6. Modifica");
	gotoxy(34,13);printf("7. Cancellazione fisica");
	gotoxy(34,14);printf("8. Menu' principale");
	
	switch(scelta(7)){
		case 1: menuIns(); 
				break;
		case 2: ricMat();
				break;
		case 3: ricPos();
				break;
		case 4: ricCog();
				break;
		case 5: ricNom();
				break;
		case 6: modifica();
				break;
		case 7: cancella();
				break;
	
	}
		
}

void menuStamp()
{	menuPrinc();
	clear(33,6,65,10);
	cornice(33,6,65,10);
	gotoxy(34,7);printf("1. Stampa in ordine alfabetico ");
	gotoxy(34,8);printf("2. Stampa in ordine cronologico");
	gotoxy(34,9);printf("3. Menu' principale");
	
	switch(scelta(3)){
		case 1: stampAlf();
				break;
		case 2: stampCron();
				break;
	}
	
}

void menuIns()
{	clear(40,8,70,15);
	cornice(40,8,70,15);
	ultMat++;
	gotoxy(41,10);printf(	"MATRICOLA   : %d", ultMat);
	gotoxy(41,11);printf(	"COGNOME     : ");
	gotoxy(41,12);printf(	"NOME        : ");
	gotoxy(41,13);printf(	"DATA NASCITA: ");
	gotoxy(41,14);printf(	"NUMERO      : ");
	
	
	totRec++;
	insCog(55,11);
	insNom(55,12);
	insData(55,13);
	insNumero(55,14);
	scrittura();
}

 void menu()
{	int opz;
	do{
		clear(0,3,80,21);
		menuPrinc();
		opz=scelta(3);
		switch(opz){
			case 1: menuGest();
					break;
			case 2: menuStamp();
					break;
		}
	}while(opz!=3);
	
}

void intesta()
{ 
  	gotoxy(3,3);printf("==================================================================");
  	gotoxy(3,4);printf("|N. |    Cognome   |     Nome     | Data Nascita  |    Numero    |");
  	gotoxy(3,5);printf("==================================================================");
}

void stampContatto(int x, int y)
{	
  	gotoxy(x,y);printf("|%2d |  %10s  |  %10s  |  %10s   |  %10s  |", matricola, cognome, nome, data, numero);
}

void insCog(int x, int y)
{	int err;
	//Lettura cognome
	do{	fflush(stdin);
		err=0;
		strcpy(cognome, " ");
		gotoxy(x,y);printf("               ");
		gotoxy(x,y);scanf("%[^\n]s", &cognome);
		if(strlen(cognome)<3)	
		{	err=1;
			gotoxy(20,23);printf("Cognome minimo di 3 caratteri!!");}
		else
		{	int i=0;
			for(int i=0; i<strlen(cognome)&&err==0;i++) 
			{	if (!((cognome[i] >= 'a' && cognome[i] <= 'z') || 
				      (cognome[i] >= 'A' && cognome[i] <= 'Z') || 
				       cognome[i] == '-' || cognome[i] == '\'' || cognome[i] == ' '))
                { err=1;
                  gotoxy(20,23);printf("Solo lettere oppure ' - / ");
				}
			}
		}
	}while(err);
	UpStr(cognome);
	gotoxy(45,23);printf("                               ");
}	

void insNom(int x, int y)
{	int err=0;
	do{	fflush(stdin);
		err=0;
		strcpy(nome, " ");
		gotoxy(x,y);printf("               ");
		gotoxy(x,y);scanf("%[^\n]s", &nome);
		if(strlen(nome)<3)	
		{	err=1;
			gotoxy(20,23);printf("Nome minimo di 3 caratteri!!");}	
		else
		{	int i=0;
			for(int i=0; i<strlen(nome)&&err==0;i++) 
			{	if (!((nome[i] >= 'a' && nome[i] <= 'z') || 
				      (nome[i] >= 'A' && nome[i] <= 'Z') || 
				       nome[i] == '-' || nome[i] == '\'' || nome[i] == ' '))
                { err=1;
                  gotoxy(20,23);printf("Solo lettere oppure ' - /");
				}
			}
		}
	}while(err);
	UpStr(nome);
	gotoxy(20,23);printf("                            ");
	
}
void insData(int x, int y)
{	
	do{	fflush(stdin);
		strcpy(data, "");
		gotoxy(x,y);printf("               ");
		
		gotoxy(x,y);scanf("%s", &data);
		if(CtrlData(data))	
		{	gotoxy(20,23);printf("Data non accettata usare formato gg/mm/aaaa");}	
	}while(CtrlData(data));
	gotoxy(20,23);printf("                                           ");
}

void insNumero(int x, int y)
{	int err;
	do{	fflush(stdin);
		strcpy(numero, "");
		gotoxy(x,y);printf("               ");
		gotoxy(x,y);scanf("%s", &numero);
		err=0;
		if(strlen(numero)!=10)	
		{	err=1;
			gotoxy(20,23);printf("Numero non valido!!");}
		else{
			for(int i=0; i<10&&err==0; i++)
			{	if(numero[i]<'0'||numero[i]>'9')
				{	err=1;
					gotoxy(20,23);printf("Numero non valido!!");}	
			}
		}
	}while(err);
	gotoxy(20,23);printf("                                           ");
}

void scrittura()
{	archivio=fopen("rubrica.seq", "a");
	archApp=fopen("rubrica.key", "w");
	fprintf(archivio, "%d %s %s %s %s\n", ultMat, cognome, nome, data, numero);
	fprintf(archApp, "%d %d", totRec, ultMat);
	_fcloseall();
}

void lettura()
{	fscanf(archivio, "%d %s %s %s %s\n", &matricola, &cognome, &nome, &data, &numero);
}

void scambia(int i, int j)
{	char vetApp[11];
	strcpy(vetApp, vetCog[i]);
	strcpy(vetCog[i], vetCog[j]);
	strcpy(vetCog[j], vetApp);
	
	strcpy(vetApp, vetNom[i]);
	strcpy(vetNom[i], vetNom[j]);
	strcpy(vetNom[j], vetApp);
	
	strcpy(vetApp, vetDat[i]);
	strcpy(vetDat[i], vetDat[j]);
	strcpy(vetDat[j], vetApp);
	
	strcpy(vetApp, vetNum[i]);
	strcpy(vetNum[i], vetNum[j]);
	strcpy(vetNum[j], vetApp);
}

void FileToVet()
{	archivio=fopen("Rubrica.seq", "r");
	int i=0;
	while(i<totRec)
	{	lettura();
		//if(feof(archivio)) break;
		strcpy(vetCog[i], cognome);
		strcpy(vetNom[i], nome);
		strcpy(vetDat[i], data);
		strcpy(vetNum[i], numero);
		i++;
	}
	_fcloseall();
}

void ricMat()
{	int flag=0, i=0;
	int nMat;
	//stampa menu
	clear(35,8,62,16);
	cornice(35,8,62,16);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Numero matricola:    ");
		gotoxy(53,9);scanf("%d", &nMat);
	}while(nMat<=0||nMat>ultMat);
	//ricerca matricola nel file
	archivio=fopen("rubrica.seq", "r");	
	while(i<totRec&&flag==0)
	{	lettura();
		if(matricola==nMat)
		{	flag=1;
		}
		i++;
		//gotoxy(0,5+1);cout<<matricola<<"  "<<cognome<<"  ";
		//getch();
	}
	_fcloseall();
	if(flag==1)	
	{	clear(0,3,80,21);
		intesta();
		stampContatto(3,6);
	}else
	{ 	gotoxy(37,13);printf("Matricola non in elenco");
	}
		
	getch();
}

void ricPos()
{	int i=1;
	int pos;
	//stampa menu
	clear(35,8,62,16);
	cornice(35,8,62,16);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Posizione:    ");
		gotoxy(47,9);scanf("%d", &pos);
	}while(pos<=0||pos>totRec);
	//ricerca matricola nel file
	archivio=fopen("rubrica.seq", "r");	
	while(i<=pos)
	{	lettura();
		if(i==pos)
		{	clear(0,3,80,21);
			intesta();
			stampContatto(3,6);
		}
		i++;
	}
	_fcloseall();
	getch();
}

void ricCog()
{	int flag=0,i=0;
	char cog[11];
	//stampa menu
	clear(35,8,64,16);
	cornice(35,8,64,16);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Cognome:            ");
		gotoxy(45,9);scanf("%[^\n]s", &cog);
		if(strlen(cog)<3)
		{	gotoxy(20,23);printf("Cognome minimo di 3 caratteri!");}
	}while(strlen(cog)<3);
	gotoxy(20,23);printf("                              ");
	//ricerca matricola nel file
	UpStr(cog);
	archivio=fopen("rubrica.seq", "r");	
	while(!feof(archivio))
	{	lettura();
		if(strcmp(cog,cognome)== 0)
		{	if(flag==0)
			{	clear(0,3,80,21);
				intesta();
			}
			stampContatto(3,6+flag);
			flag++;
		}
		i++;
		//gotoxy(0,5+1);cout<<matricola<<"  "<<cognome<<"  ";
		//getch();
	}
	_fcloseall();
	if(flag==0)	
	{	gotoxy(37,13);printf("Cognome non in elenco");
	}
	gotoxy(20,23);printf("                             ");
	getch();
}

void ricNom()
{	int flag=0,i=0;
	char nom[11];
	//stampa menu
	clear(35,8,64,16);
	cornice(35,8,64,16);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Nome:              ");
		gotoxy(43,9);scanf("%[^\n]s", &nom);
		if(strlen(nom)<3)
		{	gotoxy(20,23);printf("nome minimo di 3 caratteri!");}
	}while(strlen(nom)<3);
	gotoxy(20,23);printf("                               ");
	//ricerca matricola nel file
	UpStr(nom);
	archivio=fopen("rubrica.seq", "r");	
	while(!feof(archivio))
	{	lettura();
		if(strcmp(nom,nome)== 0)
		{	if(flag==0)
			{	clear(0,3,80,21);
				intesta();
			}
			stampContatto(3,6+flag);
			flag++;
		}
		i++;
		//gotoxy(0,5+1);cout<<matricola<<"  "<<cognome<<"  ";
		//getch();
	}
	_fcloseall();
	if(flag==0)	
	{	gotoxy(37,13);printf("nome non in elenco");
	}
	gotoxy(20,23);printf("                           ");
	getch();
}

void modifica()
{	int nMat, flag=0;
	
	//stampa menu
	clear(35,8,70,14);
	cornice(35,8,70,14);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Numero matricola:    ");
		gotoxy(53,9);scanf("%d", &nMat);
	}while(nMat<=0||nMat>ultMat);
	//Modifica File
	archivio=fopen("Rubrica.seq", "r");
	archApp= fopen("FileApp.seq", "w");
	for(int i=0; i<totRec; i++)
	{	lettura();
		if(matricola==nMat)
		{	clear(36,9,64,13);
			gotoxy(37,9);printf(	"MATRICOLA   : %d", matricola);
			gotoxy(37,10);printf(	"COGNOME     : %s", cognome);
			gotoxy(37,11);printf(	"NOME        : %s", nome);
			gotoxy(37,12);printf(	"DATA NASCITA: %s", data);
			gotoxy(37,13);printf(	"NUMERO      : %s", numero);
			insCog(51,10);
			insNom(51,11);
			insData(51,12);
			insNumero(51,13);
			flag=1;
		}
		fprintf(archApp, "%d %s %s %s %s\n", matricola, cognome, nome, data, numero);
	}
	_fcloseall();
	//sostituzione file
	remove("Rubrica.seq");
	rename("FileApp.seq", "Rubrica.seq");
	
	if(flag==0)
	{ gotoxy(37,12);printf("Matricola non in elenco");
	}
	
}

void cancella()
{	int nMat, flag=0;
	char risp;
	totRec=0;
	
	//stampa menu
	clear(35,8,70,14);
	cornice(35,8,70,14);
	//acquisizione numero di matricola
	do{	fflush(stdin);
		gotoxy(36,9);printf("Numero matricola:    ");
		gotoxy(53,9);scanf("%d", &nMat);
	}while(nMat<=0||nMat>ultMat);
	//Modifica File
	archivio=fopen("Rubrica.seq", "r");
	archApp= fopen("FileApp.seq", "w");
	while(fscanf(archivio, "%d %s %s %s %s", &matricola, cognome, nome, data, numero) == 5)
	{	if(matricola==nMat)
		{	clear(36,9,64,13);
			gotoxy(37,9);printf(	"MATRICOLA   : %d", matricola);
			gotoxy(37,10);printf(	"COGNOME     : %s", cognome);
			gotoxy(37,11);printf(	"NOME        : %s", nome);
			gotoxy(37,12);printf(	"DATA NASCITA: %s", data);
			gotoxy(37,13);printf(	"NUMERO      : %s", numero);
			
			do{
				gotoxy(20,19);printf("Sicuro di vole cancellare il contatto? (s/n):      ");
				gotoxy(66,19);scanf("%c", &risp);
				risp=UpChar(risp);
				
			}while(risp!='S'&&risp!='N');
			
			if(risp=='N')//mando avanti la lettura
			{	fprintf(archApp, "%d %s %s %s %s\n", matricola, cognome, nome, data, numero);
				totRec++;
			}
			flag=1;
		}else{
			fprintf(archApp, "%d %s %s %s %s\n", matricola, cognome, nome, data, numero);
			totRec++;
		}		
		FILE *app=fopen("rubrica.key", "w");
		fprintf(app, "%d %d", totRec, ultMat);
	}
	_fcloseall();
	//sostituzione file
	remove("Rubrica.seq");
	rename("FileApp.seq", "Rubrica.seq");
	
	if(flag==0)
	{ gotoxy(37,12);printf("Matricola non in elenco");
	}
	
}

void stampCron()
{	FileToVet();
	int r=0, maxR=10;
	clear(0,3,80,21);
	intesta();
	if(totRec!=0)
	{	for(int i=0; i<totRec; i++)
		{	if(r==maxR)
			{	r=0;
				getch();
				clear(0,6,80,21);
			}
			gotoxy(3,6+r);printf("|%2d |  %10s  |  %10s  |  %10s   |  %10s  |", i+1 , vetCog[i], vetNom[i], vetDat[i], vetNum[i]);
			r++;
		}
		getch();
	}
}

void ordAlf()
{	FileToVet();

	char cogn1[60],cogn2[60];
	for(int i=0;i<totRec-1;i++)
	{ 	for(int j=i+1;j<totRec;j++)
		{	strcpy(cogn1,vetCog[i]);strcat(cogn1,vetNom[i]);//unione fra nome e cognome
	      	strcpy(cogn2,vetCog[j]);strcat(cogn2,vetNom[j]);
	      	if(strcmp(cogn1,cogn2)>0) scambia(i,j);//confronto e richiamo funzione
	    }
	}
	
}

void stampAlf()
{	int r=0, maxR=10;
	clear(0,3,80,21);
	intesta();
	ordAlf();
	if(totRec!=0)
	{	for(int i=0; i<totRec; i++)
		{	if(r==maxR)
			{	r=0;
				getch();
				clear(0,6,80,21);
			}
			gotoxy(3,6+r);printf("|%2d |  %10s  |  %10s  |  %10s   |  %10s  |", i+1 , vetCog[i], vetNom[i], vetDat[i], vetNum[i]);
			r++;
		}
		getch();
	}
}








