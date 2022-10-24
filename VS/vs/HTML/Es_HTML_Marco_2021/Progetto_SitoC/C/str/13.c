/*39> emulare la funzione strcmp char by char*/
#include<stdio.h>
#include<string.h>
#define DIM 80
void my_strcmp(char [], char []);
int main()
{
	char s1[DIM],s2[DIM];
	printf("inserire 1 stringa: ");
	gets(s1);
	fflush(stdin);
	printf("inserire 2 stringa: ");
	gets(s2);
	fflush(stdin);
	my_strcmp(s1,s2);
	return 0;
}
void my_strcmp(char s1[], char s2[]){
	int i,flag,max;
	flag=0;
	if(strlen(s1)>strlen(s2)){
		max=strlen(s1);
	}else{
		max=strlen(s2);
	}
	while(flag==0 && i<max){
		if(s1[i]==s2[i]){
			flag=0;
			i++;
		}else if(s1[i]>s2[i]){
			flag=1;
		}else{
			flag=-1;
		}
	}
	if(flag==0){
		printf("%s = %s",s1,s2);
	}else if(flag>0){
		printf("%s > %s",s1,s2);
	}else{
		printf("%s < %s",s1,s2);
	}
}
