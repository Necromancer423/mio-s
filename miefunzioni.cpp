// MieFunzioni
void gotoxy(int x,int y){
	COORD coordinate={x,y};
	HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console,coordinate);
}
void StampaTitolo();
void Replica(int CodASCII,int Volte);
void clear(int x1,int y1,int x2,int y2);
void cornice(int x1,int y1,int x2,int y2);
void setcolor(short color);
void colore(char c[]);
void impostaSchermo();


char DwChar(char Car); //!< converte in minuscolo per passaggio per indirizzo.
char UpChar(char Car); //!< converte in maiuscolo per passaggio per indirizzo.
void DwStr(char Str[]); //!< converte una stringa in minuscolo.
void UpStr(char Str[]); //!< converte una stringa in maiuscolo.
int contaCar(char str[], char car);	 //!< Conta le occorrenze di car in str.
int cercaPos(char str[], char car);	 //!< Ritorna la posizione del carattere alla prima occorrenza, 0 se non presente.
void SubStr(char StrI[],int PosI,int NCar,char StrO[]); //!<prende una striga e salva un pezzo in un'altra.
int CtrlData(char Data[]);	//!< controlla una data in formato gg/mm/aaaa.
int dataNum(char Data[]);	//!< metta una data gg/mm/aaaa in int ggmmaaaa.
void scambio(int *num1, int *num2); //!< scambia il valore di due variabili.
int calcProd(int molt, int mult); /*! calcola il prodotto attraverso la somma*/

void impVideo(){
	clear(0,0,79,24);
	gotoxy(1,0);	printf("I.I.S.S G.Salvemini");
	gotoxy(1,1);	printf(" a.s:  2024/2025   ");
	gotoxy(30,0);	printf(" PROGETTO : SCRUTINIO ");
	gotoxy(30,1);	printf("(Con file sequenziali)");
	gotoxy(61,0);	printf("Classe : V B INF.");
	gotoxy(61,1);	printf("Gruppo n. x");
	gotoxy(0,2);
	for(int i=0;i<=79;i++)
	{	printf("%c",205);
	}
	gotoxy(0,22);
	for(int i=0;i<=79;i++)
	{	printf("%c",205);
	}
}

void StampaTitolo()
{ int l=strlen("RUBRICA");
  l=(80-l)/2;
  gotoxy(l,1);	printf("%s","RUBRICA");
}

void Replica(int CodASCII,int Volte)
{ 	for(int i=0;i<Volte;i++)
	{	printf("%c",CodASCII);
	}
}

void clear(int x1,int y1,int x2,int y2)
{   int rig,larg;
    char blank[100]="                                                                                                 ";
    //strcat(blank,"                                                ");
   	if((x1<x2) && (y1<=y2))
    { larg=(x2-x1);
      blank[larg]='\0';
      for(rig=y1;rig<=y2;rig++)
      {	gotoxy(x1,rig);printf("%s",blank);
   	  }
	}	
}
void cornice(int x1,int y1,int x2,int y2)
{ 	gotoxy(x1,y1);	printf("%c",218);				//! Stampo prima il vertice alto sinistro 
	for(int i=(x1+1);i<x2;i++)
	{ 	printf("%c",196);			//! Stampo la prima riga 
	}
	// gotoxy(x2,y1);
	printf("%c",191);			  	//! Stampo il vertice alto destro
	for(int n=(y1+1);n<y2;n++)
	{ 	gotoxy(x1,n); printf("%c",179);  //! Stampo le colonne laterali
		gotoxy(x2,n); printf("%c",179);
	}
	gotoxy(x1,y2);printf("%c",192);	//! Stampo il verice basso sinistro
	for(int i=(x1+1);i<x2;i++)
	{ printf("%c",196);			//! Stampo l'ultima riga
	}
	//gotoxy(x2,y2);
	printf("%c",217);				//! Stampo il vertice basso destro 
}

void colore(char c[])
{
	if(strcmp(c,"ROSSO") == 0)
		setcolor(12|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	if(strcmp(c,"NERO") == 0)
		setcolor(0|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	if(strcmp(c,"GRIGIO") == 0)
		setcolor(8|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	if(strcmp(c,"GIALLO") == 0)
		setcolor(15);
	if(strcmp(c,"SFONDOVERDE") == 0)
		setcolor(0|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	if(strcmp(c,"SFONDOROSSO") == 0)
		setcolor(0|BACKGROUND_RED|BACKGROUND_INTENSITY);
}
void setcolor(short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}
void impostaSchermo()
{	colore("NERO");
	impVideo();
	clear(0,6,79,20);
	colore("NERO");
}

/**
 * @brief Converte un carattere maiuscolo in minuscolo.
 * @param Car Carattere maiuscolo da convertire.
 * @return Carattere minuscolo corrispondente.
 */
char DwChar(char Car) 
{	int distanza='A'-'a';
	if((Car >= 'A')&&(Car <= 'Z'))
	{	Car = Car - distanza;}
	return Car;
}
/**
 * @brief Converte un carattere minuscolo in maiuscolo.
 * @param Car Carattere minuscolo da convertire.
 * @return Carattere maiuscolo corrispondente.
 */
char UpChar(char Car)
{	int distanza='A'-'a';
	if((Car >= 'a')&&(Car <= 'z'))
	{	Car = Car + distanza;}
	return Car;
}
/**
 * @brief Converte una stringa in caratteri minuscoli.
 * @param Str Stringa da convertire.
 */
void DwStr(char Str[])
{
	int i = 0;
	while(Str[i]!='\0')
	{	Str[i]=DwChar(Str[i]);
		i++;
	}
}
/**
 * @brief Converte una stringa in caratteri maiuscoli.
 * @param Str Stringa da convertire.
 */
void UpStr(char Str[])
{
	int i = 0;
	while(Str[i]!='\0')
	{	Str[i]=UpChar(Str[i]);
		i++;
	}
}
/**
 * @brief Conta il numero di occorrenze di un carattere in una stringa.
 * @param str Stringa in cui cercare il carattere.
 * @param car Carattere da cercare.
 * @return Numero di occorrenze del carattere nella stringa.
 */
int contaCar(char str[], char car)
{	int occor = 0, lung, i;
	lung = strlen(str); // strlen() Restituisce il numero di caratteri della stringa
	car = DwChar(car);
	for(i = 0; i < lung; i++)
	{	if(DwChar(str[i]) == car)
		{	occor++; }
	}
	return occor;
}
/**
 * @brief Cerca la posizione di un carattere in una stringa.
 * @param str Stringa in cui cercare il carattere.
 * @param car Carattere da cercare.
 * @return Posizione del carattere nella stringa
 */
int cercaPos(char str[], char car)
{	int pos = 0, lung, i;
	lung = strlen(str); // strlen() Restituisce il numero di caratteri della stringa
	car = DwChar(car);
	i = 0;
	while(i < lung && pos == 0)
	{	if(DwChar(str[i]) == car )
		{	pos = i + 1; }
		i++;	
	}
	return pos;
}
/**
 * @brief Estrae una sottostringa da una stringa.
 * @param StrI Stringa di partenza.
 * @param PosI Posizione iniziale della sottostringa.
 * @param NCar Numero di caratteri da estrarre.
 * @param StrO Stringa risultante.
 */
void SubStr(char StrI[],int PosI,int NCar,char StrO[])
{	if(PosI> strlen(StrI) )	PosI = strlen(StrI)-1;
	if(NCar <1)	NCar=1;
	if(NCar >(strlen(StrI)-PosI+1))	NCar=(strlen(StrI)-PosI+1);
	int i,j=0;
	for(i=0;i<NCar;i++)
	{	StrO[j]=StrI[PosI];
		j++;
		PosI++;
	}
	StrO[j]='\0';
}
/**
 * @brief Controlla se una stringa è una data valida.
 * @param Data Stringa da controllare.
 * @return 0 se data valida o codice d'errore da 1 a 5
 */
int CtrlData(char Data[])
{	int Lung, err = 0;
	char Appo[5];
	int GG, MM, AA;
	if(strlen(Data) != 10)
	{ 	err = 1;
	}
	else
	{	if(Data[2] != '/' || Data[5] != '/')
		{	err = 2;
		}
		else
		{	SubStr(Data, 6, 4, Appo);
			AA = atoi(Appo);
			if(AA < 1900 || AA > 2025)
			{	err = 5;
			}
			else
			{
				// Controllo se l'anno e' bisestile
				if(AA % 4 == 0) {
					GGMese[2] = 29;
				}
				else
				{
					GGMese[2] = 28;
				}
				
				SubStr(Data, 3, 2, Appo);
				MM = atoi(Appo);
				if(MM < 1 || MM > 12)
				{	err = 4;
				}
				else
				{	SubStr(Data, 0, 2, Appo);
					GG = atoi(Appo);
					if(GG < 1 || GG > GGMese[MM])
					{	err = 3;
					}
				}
			}
			
			
		}
	}
	return err;
}
/**
 * @brief mette per numero intero una stringa data.
 * @param Data Stringa data da cui estrarre.
 * @return Numero intero prelevato dalla data.
 */
int dataNum(char Data[])
{	int G,M,A,RIS;
	char strAPP[5];
	SubStr(Data, 0, 2, strAPP);
	G=atoi(strAPP);
	SubStr(Data, 3, 2, strAPP);
	M=atoi(strAPP);
	SubStr(Data, 6, 4, strAPP);
	A=atoi(strAPP);
	RIS=(A*10000+M*100+G);
	return RIS;
	
}
/**
 * @brief Scambia i valori di due variabili intere.
 * @param num1 Primo numero intero.
 * @param num2 Secondo numero intero.
 */
void scambio(int *num1, int *num2)
{	int APP=*num1;
	*num1=*num2;
	*num2=APP;
	gotoxy(10,10);printf("%d, %d", *num1, *num2);
}
/**
 * @brief Calcola il prodotto di due numeri interi utilizzando la somma.
 * @param num1 Primo numero intero.
 * @param num2 Secondo numero intero.
 * @return Il prodotto dei due numeri interi.
 */
int calcProd(int num1, int num2)
{	int APP=0;
	if(num2>num1) //effettua lo scmbio se necessario
	{ scambio(&num1, &num2);
	}
	for(;num2>0;num2--)
   	{	APP=APP+num1; }
   	return APP;
}
