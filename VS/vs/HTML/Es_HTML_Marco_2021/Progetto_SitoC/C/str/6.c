/*32&gt; data una stringa s1, copiare in una stringa s2 mettendo le vocali alla fine 
(sia MAIUSCOLE che minuscole! - ovviamente la lunghezza di s2 � uguale a quella di s)
es: "Mio nonno" -&gt; "M nnniooo"
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
int carica_cons(char [], char [], char [], int);
void carica_voc(char [], char [], char [], int);
void visualizza(char []);
int main()
{
	int i,k;
	char s[]={'M','i','o',' ','n','o','n','n','o','\0'};
	char s2[strlen(s)];
	char v[]={'a','e','i','o','u','A','E','I','O','U','\0'};
	puts(s);
	k=0;
	k=carica_cons(s,v,s2,k);
	carica_voc(s,v,s2,k);
	putchar('\n');
	visualizza(s2);
	return 0;
}
int carica_cons(char s[], char v[], char s2[], int k){
	int i,j,flag;
	for(i=0;i&lt;strlen(s);i++){
		flag=0;
		j=0;
		do{
			if(s[i]==v[j]){
				flag=1;
			}
			j++;
		}while(j&lt;strlen(v));
		if(flag==0){
			s2[k]=s[i];
			k++;
		}
	}
	return k;
}
void carica_voc(char s[], char v[], char s2[], int k){
	int i,j;
	for(i=0;i&lt;strlen(s);i++){
		j=0;
		do{
			if(s[i]==v[j]){
				s2[k]=s[i];
				k++;
			}
			j++;
		}while(j&lt;strlen(v));
	}
	s2[k]='\0';
}
void visualizza(char s2[]){
	putchar('\n');
	puts(s2);
}
