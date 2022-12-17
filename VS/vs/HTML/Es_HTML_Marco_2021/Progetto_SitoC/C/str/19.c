/*48&gt; inserire un array di stringhe dimensionato DIM
cercare la stringa se esiste o se non esiste
Esce con Enter
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 5
int main()
{
	char parole[DIM][80];
	char s[20];
	char c;
	int i,flag;
	for(i=0;i&lt;DIM;i++){
		printf("inserire parole: ");
		gets(parole[i]);
		fflush(stdin);
	}
	flag=1;
	while(flag==1){
		printf("inserire parola da ricercare: ");
		gets(s);
		fflush(stdin);
		i=0;
		c=0;
		while(i&lt;DIM && flag==1){
			if(strcmp(parole[i],s)==0){
				printf("parola trovata. \n");
				printf("continuare? (enter to esc space to continue)");
				scanf("%c",&c);
				fflush(stdin);
				if(c==10){
					flag=0;
				}else{
					i=DIM;
				}
			}else{
				i++;
			}	
		}
		if(flag==1 && c!=32){
			printf("parola non trovata. \n");
			printf("continuare? (enter to esc space to continue)");
			scanf("%c",&c);
			fflush(stdin);
			if(c==10){
				flag=0;
			}
		}
	}
	return 0;
}
