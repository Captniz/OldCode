#include <stdio.h>
int main(){
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int ng,i,j,k=0,g,flag=0,m,c=0;
	srand(time(NULL));
	fscanf(in,"%d",&ng);
	fflush(stdin);
	int v[ng];
	for(i=0;i<ng;i++)
		fscanf(in,"%d",&v[i]);
		
	for(i=0;i<ng;i++){
		for(j=(i+1);j<ng;j++){
			if(v[i]==v[j]){
				v[j]=0;
				flag=1;
			}
		}
		if(flag==0){
			v[i]=0;
		}
	}
	for(i=0;i<ng;i++){
		if(v[i]!=0){
			c++;
		}
	}
	if(c>1){
		fprintf(out,"YES");
	}else if(c<=1){
		fprintf(out,"NO");
	}
	return 0;
}
