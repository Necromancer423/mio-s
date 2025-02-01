// Variabili
int GGMese[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char Titolo[60];
int LargVideo=80;
int AltVideo=24;
const char TabErr[6][40] = {"             ",
					 		 "Lunghezaz err.",
							 "Car. Sep. err.",	
							 "Giorno errato",
							 "Mese errato",
							 "Anno errato"
							};
int Err = 0;
const char NomiMese [13][20] = {" ",
								"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Dicembre"};
const char CarSep = '/';
const int AnnoMin = 1900;
const int AnnoMax = 2050;
