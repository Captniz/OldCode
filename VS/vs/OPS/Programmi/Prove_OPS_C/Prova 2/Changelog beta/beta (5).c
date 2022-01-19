#include <stdio.h>
int main(){
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int ng,i,j,k=0,flag=0,c=0;
	fscanf(in,"%d",&ng);
	fflush(stdin);
	int v[ng];
	for(i=0;i<ng;i++){
		fscanf(in,"%d",&v[i]);
		fflush(stdin);
	}
		
	for(i=0;i<ng && c<2;i++){
		for(j=(i+1);j<ng;j++){
			if(v[i]==v[j]){
				v[j]=0;
				flag=1;
			}
		}
		if(flag==0){
			v[i]=0;
		}else{
			c++;
		}
		flag=0;
	}
	if(c>1){
		fprintf(out,"YES",c);
	}else{
		fprintf(out,"NO");
	}
	return 0;
}
