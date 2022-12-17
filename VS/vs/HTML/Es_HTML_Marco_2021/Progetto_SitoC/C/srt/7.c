/*60&gt; Data una stringa s="Oggi ProVIAMO a VeDere chi Vince" caricata contestualmente 
estrarre solo le maiuscole e ordinarle in una seconda stringa s2 in modo discendente.
visualizzare s.
visualizzare s2.
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 80
void visualizza(char []);
void estrai(char [], char []);
void Sort(char []);
int main()
{
	char s[DIM]={"Oggi ProVIAMO a VeDere chi Vince"},s2[DIM];
	visualizza(s);
	estrai(s,s2);
	Sort(s2);
	visualizza(s2);
	return 0;
}
void visualizza(char s[]){
	puts(s);
}
void estrai(char s[], char s2[]){
	int i,j;
	j=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]&gt;=65 && s[i]&lt;=90){
			s2[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
}
void Sort(char s2[]){
	int i,j;
	int box;
	for(i=0;i&lt;strlen(s2)-1;i++){
		for(j=i+1;j&lt;strlen(s2);j++){
			if(s2[i]&lt;s2[j]){
				box=s2[i];
				s2[i]=s2[j];
				s2[j]=box;
			}
		}
	}
}
