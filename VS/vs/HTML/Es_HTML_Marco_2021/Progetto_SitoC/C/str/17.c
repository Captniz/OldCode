/*43&gt; Data una stringa s contare quante cifre ci sono.*/
#include&lt;string.h&gt;
#include&lt;stdio.h&gt;
#define DIM 80
int main(){
	char s[DIM],i;
	int c;
	c=0;
	printf("inserisci una stringa: ");
	gets(s);
	fflush(stdin);
	for(i=0;i&lt;strlen(s);i++){
		if(s[i]&gt;=48 && s[i]&lt;=57){
			c++;
		}
	}
	printf("n di cifre = %d",c);
	return 0;
}

