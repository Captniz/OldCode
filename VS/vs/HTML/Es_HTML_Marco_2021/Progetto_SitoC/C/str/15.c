/*41> emulare la funzione strcat char by char*/
#include<stdio.h>
#include<string.h>
#define DIM 80
void my_strcat(char [], char []);
int main()
{
	char s[DIM],s2[DIM];
	printf("inserire prima stringa: ");
	gets(s);
	fflush(stdin);
	printf("\ninserire seconda stringa: ");
	gets(s2);
	fflush(stdin);
	putchar('\n');
	my_strcat(s,s2);
	puts(s);
}
void my_strcat(char s[DIM], char s2[DIM]){
	int i,j;
	for(i=strlen(s),j=0;s2[j]!='\0';i++,j++){
		s[i]=s2[j];
	}
	s[i]='\0';
}
