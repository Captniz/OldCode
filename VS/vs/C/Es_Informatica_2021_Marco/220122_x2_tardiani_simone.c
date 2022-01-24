//!con function

#include <stdio.h>
#define DIM 80
void visualizza(char s[]);
void MaiuscEx(char s[],char s2[]);
void sort(char s2[]);
int main(){
	char s[]="Oggi ProVIAMO a VeDere chi Vince",s2[80];
	int i,j;
	j=0;
	//azzero s2
	for(i=0;i<DIM;i++)
		s2[i]='\0';
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
	for(i=0;s[i]!='\0';i++){
		if(s[i]>=65 && s[i]<=90){
			s2[j]=s[i];
			j++;
		}
	}
}
void sort(char s2[]){
	int box,i,j;
	for(i=0;s2[i]!='\0';i++){
		for(j=i+1;s2[j]!='\0';j++){
			if(s2[i]<s2[j]){
				box=s2[i];
				s2[i]=s2[j];
				s2[j]=box;
			}
		}
	}
}
/*
#include<stdio.h>
#include<string.h>

void carica(char s[]);
void visualizza(char s[]);
void TrovaMaiuscole(char s[], char s2[]);
void sort(char s2[]);
int main(int argc, char const *argv[]){
    
    char s[]={},s2[80];
    carica(s);
    visualizza(s);
    TrovaMaiuscole(s,s2)
    return 0;
}

void carica(char s[]){
    s[]={"Oggi ProVIAMO a VeDere chi vince"};
}


void visualizza(char s[]){
    puts(s);
}


void TrovaMaiuscole(char s[], char s2[]){

    int i,j;
    j=0;
    i=0;

    for ( i = 0; s[i] != '\0'; i++){
        if (s[i]>=65 || s[i]<=90){
            s2[j]=s[i];
            j++;
        }
        
    }
    
}
void sort(char s[]){
    int i,j;
    for(i=0;i<str
}

*/