#include <stdio.h>
#define DIM 80

void visualizza(char s[]);
void MaiuscEx(char s[],char s2[]);
void sort(char s2[]);

int main(){
	char s[]="AqQasSaA",s2[80];
	int i,j;
	j=0;
	i=0;

	visualizza(s);
	MaiuscEx(s,s2);
	sort(s2);
	visualizza(s2);
	return 0;
}

void visualizza(char s[]){
	puts(s);
}

void MaiuscEx(char s[],char s2[]){
	int i,j;
	i=0;
	j=0;
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]>=65 && s[i]<=90){
			s2[j]=s[i];
			j=j+1;
		}
	}

	s2[j]='\0';
}

void sort(char s2[]){
	int box,i,j;
	i=0;
	j=0;
	box=0;

	for(i=0;s2[i+1]!='\0';i++){
		for(j=i+1;s2[j]!='\0';j++){
			if(s2[i]<s2[j]){
				box=s2[i];
				s2[i]=s2[j];
				s2[j]=box;
			}
		}
	}
}