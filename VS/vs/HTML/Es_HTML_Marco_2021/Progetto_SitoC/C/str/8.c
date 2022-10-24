/*034> Inserire esternamente una stringa.
Restituire con una funzione le vocali.
--------
int vocali(char [])
*/
#include<stdio.h>
#include<string.h>
#define DIM 80

void stringa(char []);
int vocali(char []);
int main(){
	char s[DIM];
	int c;
	stringa(&s[0]);
	c=vocali(&s[0]);
	printf("numero vocali = %d",c);
	return 0;
}
void stringa(char s[DIM]){
	printf("inserisci stringa: ");
	gets(s);
	fflush(stdin);
}
int vocali(char s[]){
	int c,i;
	c=0;
	for(i=0;i<strlen(s);i++){		
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
			c++;
		}
	}
	return c;
}
