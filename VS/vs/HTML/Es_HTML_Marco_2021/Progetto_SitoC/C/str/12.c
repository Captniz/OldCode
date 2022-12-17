/*38&gt; emulare la funzione strncpy char by char*/

#include&lt;string.h&gt;
#include&lt;stdio.h&gt;
#define DIM 80

void my_strncpy(char [], char [], int );

int main(){
	char s1[DIM],s2[DIM];
	int n;
	printf("stringa: ");
	gets(s1);
	fflush(stdin);
	do{
		printf("numero: ");
		scanf("%d",&n);
		fflush(stdin);
	}while(n&gt;strlen(s1) || n&lt;0);
	my_strncpy(s1,s2,n);
	return 0;
}

void my_strncpy(char s1[DIM], char s2[DIM], int n){
	int i;
	for(i=0;i&lt;n;i++){
		s2[i]=s1[i];
	}
	s2[n]='\0';
	puts(s2);
}
