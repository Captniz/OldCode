//220126_tardiani_simone_03.c
#include<stdio.h>
#include<string.h>
#define DIM 10
#define L 80

void RichiediStringhe(char v[DIM][L]);

int main(){
	int i,j;
	i=0;
	j=0;
	char v[DIM][L],box[L];
	
	RichiediStringhe(v);
	
	for(i=0;i<DIM-1;i++){
		for(j=i+1;j<DIM;j++){
			if(strlen(v[i])==strlen(v[j])){	
				if(strcmp(v[i],v[j])>0){
					strcpy(box,v[i]);
					strcpy(v[i],v[j]);
					strcpy(v[j],box);	
				}
			} else if(strlen(v[i])>strlen(v[j])){
				strcpy(box,v[i]);
				strcpy(v[i],v[j]);
				strcpy(v[j],box);
			}
		}
	}
	
	putchar('\n');
	
	for(i=0;i<DIM;i++){
		printf("%s%d\n",v[i],strlen(v[i]));
	}
}

void RichiediStringhe(char v[DIM][L]){
	
	int i=0;
	
	for(i=0;i<DIM;i++){
		printf("stringa %d:",i+1);
		gets(v[i]);
		fflush(stdin);
	}
}
