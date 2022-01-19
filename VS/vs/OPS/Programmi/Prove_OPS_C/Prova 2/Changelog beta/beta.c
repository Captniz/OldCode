#include <stdio.h>

void main(){
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int ng,i,j,flag=0,c=0;
	fscanf(in,"%d",&ng);
	int v[ng];
	for(i=0;i<ng;i++)
		fscanf(in,"%d",&v[i]);
	for(i=0;i<ng;i++){
		for(j=(i+1);j<ng;j++){
			if(v[i]==v[j]){
				v[j]=0;
				v[j]=v[ng-1];
				ng--;
				flag=1;
			}
		}
		if(flag==0)
			v[i]=0;
		flag=0;
	}
	for(i=0;i<ng;i++){
		if(v[i])
			c++;
	}
	if(c>1)
		fprintf(out,"YES",c);
	else
		fprintf(out,"NO");
}
