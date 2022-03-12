//Tardiani Simone
/*
Prendo in input due stringhe senza lettere maiuscole, di cui la seconda è più corta o di uguale
lunghezza rispetto alla prima.

Il programma restituisce:
"SI" quando tutte i char di s2 sono compresi in s1 almeno una volta, 
"NO" se accade il contrario.

Inoltre il programma copia s1 in una stringa aggiuntiva s3, tuttavia tutti i char contenuti in s2 
diventano maiuscoli nella stringa s3
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 51

//Creo i prototipi delle funzioni
int Islonger(char s1[DIM],char s2[DIM]);
int IsLower(char s[DIM]);
int IsIn(char s1[DIM],char s2[DIM]);
void ToUpperx(char s3[DIM], char s1[DIM],char s2[DIM]);

int main(){
	char s1[DIM],s2[DIM],s3[DIM];
	
	do{
		printf("Stringa 1:");	//Prendo in input le stringhe
		gets(s1);
		fflush(stdin);
		printf("\nStringa 2:");
		gets(s2);
		fflush(stdin); 			//Uso fflush al posto di while(getchar()!='\n'); poichè mi dava un errore (loop)
	}while(Islonger(s1,s2) || IsLower(s1) || IsLower(s2));	//Continuo a chiedere le stringhe finchè non rispettano i parametri
															
	if(IsIn(s1,s2)){			//Controllo se tutti i char di S2 sono compresi in S1
		printf("\nSI");
	}else{
		printf("\nNO");
	}
	
	ToUpperx(s3,s1,s2);			//Porto S1 in S3 con le lettere maiuscole quando sono contenute anche in S2
	
	printf("\n%s",s3);			//Stampo S3
	return 0;
}

int Islonger(char s1[DIM],char s2[DIM]){
	if(strlen(s1)>=strlen(s2)){		//Se:
		return 0;					//S1>=S2	= 0 
	}								//S1<S2		= 1 
	return 1;					
}

int IsLower(char s[DIM]){
	int i=0;						
	for(i=0;s[i]!='\0';i++){		//Ciclo fino a fine stringa
		if(s[i]>=65 && s[i]<=90){	//Se: 
			return 1;				//i char sono lettere maiuscole		= 1
		}							//i char non sono lettere maiuscole	= 0
	}
	return 0;
}

int IsIn(char s1[DIM],char s2[DIM]){
	int i,j,flag;
	i=0;
	j=0;
	flag=1;
	
	for(i=0;s2[i]!='\0';i++){		//Ciclo fino a fine stringa s2	
		flag=1;
		for(j=0;s1[j]!='\0';j++){	//Ciclo fino a fine stringa s1
			if(s2[i]==s1[j]){		//Se trova almeno una volta la lettera di s2 in s1 -> flag=0
				flag=0;
			}
		}
		if(flag){					//Se flag=1 non è stato trovato un char di s2, quindi -> return 0
			return 0;
		}
	}
	
	return 1;						//Se il ciclo finisce tutti i char -> return 1
}

void ToUpperx(char s3[DIM], char s1[DIM],char s2[DIM]){
	int i,j;
	i=0;
	j=0;
	
	for(i=0;s1[i]!='\0';i++){		//Ciclo fino a fine stringa s1
		s3[i]=s1[i];				//Copia s1 in s3
	}
	s3[i]='\0';						//Mette il terminatore a s3
	
	for(i=0;s2[i]!='\0';i++){		//Ciclo fino a fine stringa s2
		for(j=0;s3[j]!='\0';j++){	//Ciclo fino a fine stringa s3
			if(s2[i]==s3[j]){		//Se un char di s2 è uguale un char s3 portalo a maiuscolo
				s3[j]=s3[j]-32;		//Porto a maiuscolo il char
			}
		}
	}
}
