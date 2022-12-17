/*67&gt; puntatori e ricorsione
==========================
Scrivere la funzione ricorsiva:
int count_char(char *str, char c, int) // + facile
int count_char(char *str, char c) // + difficile
che conta il numero di occorrenze del carattere c nella stringa str. 
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
void carica(char []);
void visualizza(char []);
int count_char(char *, char );
int main()
{
	char s[80];
	char c,*str;
	carica(s);
	str=&s[0];
	puts(s);
	printf("inserire un carattere: ");
	scanf("%c",&c);
	fflush(stdin);
	printf("il carattere %c occorre %d volte",c,count_char(str,c));
	return 0;
}
void carica(char s[]){
	printf("inserire una stringa: ");
	gets(s);
	fflush(stdin);
}
int count_char(char *str, char c){
	if(*str == '\0'){
		return 0;
	}else{
		if(*str==c){
			return count_char(str+1,c)+1;
		}else{
			return count_char(str+1,c);
		}
	}
}
