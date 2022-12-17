/*54&gt; Data una stringa s caricata contestualmente (contenente solo lettere e spazi per ipotesi)
eliminare gli spazi e caricare in una seconda stringa s2
convertire s2 tutto in minuscole
ordinare s2 in modo crescente
visualizzare s2
es: s="vADo al maRe"
s2="vADoalmaRe"
s2="vadoalmare"
s2="aaadelmorv"
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 80
void space(char [DIM]);
void conv(char [DIM]);
void sort(char [DIM]);
int main(){
	char s[DIM]={"vADo aL maRe"};
	puts(s);
	space(s);
	puts(s);
	conv(s);
	puts(s);
	sort(s);
	puts(s);
	return 0;
}
void space(char s[DIM]){
	int i,j;
	for(i=0;i&lt;strlen(s);i++){
		if(s[i]==32){
			for(j=i;j&lt;strlen(s);j++)
				s[j]=s[j+1];			
		}
	}
}
void conv(char s[DIM]){
	int i;
	for(i=0;s[i]!='\0';i++){
		if(s[i]&gt;=65 && s[i]&lt;=90){
			s[i]=s[i]+32;
		}
	}
}
void sort(char s[DIM]){
	int i,j,box,flag;
	do{
		flag=0;
		for(i=0;i&lt;strlen(s)-1;i++){
			if(s[i]&gt;s[i+1]){
				box=s[i];
				s[i]=s[i+1];
				s[i+1]=box;
				flag=1;
			}
		}
	}while(flag==1);
}
