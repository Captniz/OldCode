/*44&gt; Data una stringa s1 e una stringa s2, la funzione 
int cerca(char [], char [])
retistuisce l'indice d'inizio se s2 � contenuta in s1
altrimenti ritorna 0.
(appena s2 � contenuta in s1 inutile procedere nella ricerca)
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 80
int cerca(char [], char []);
int main()
{
	char s[DIM],s2[DIM];
	int ctr;
	printf("inserire prima stringa: ");
	gets(s);
	printf("inserire seconda stringa: ");
	gets(s2);
	ctr=cerca(s,s2);
	if(ctr==0){
		printf("la seconda stringa non e' contenuta nella prima");
	}else{
		printf("la seconda stringa e' contenuta nella prima nella posizione %d",ctr-1);
	}
	return 0;
}
int cerca(char s[], char s2[]){
	int i,j,k,flag;
	i=0;
	j=0;
	flag=0;
	while(i&lt;strlen(s) && flag==0){
		k=i;
		flag=1;
		j=0;
		while(j&lt;strlen(s2) && flag==1){
			if(s[k]==s2[j]){
				j++;
				k++;
			}else{
				flag=0;
			}
		}
		i++;
	}
	if(flag==0){
		return 0;
	}else{
		return i;
	}
}
