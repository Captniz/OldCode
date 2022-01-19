#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	FILE *num=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int i,c=-1,j,f=0;
	unsigned int n=0,s=0;
	char l[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	while(fgetc(num)!=EOF){
		c++;
	}
	char v[c];
	fclose(num);
	FILE *in=fopen("input.txt","r");
	fscanf(in,"%s",&v[0]);
	for(i=0;i<c;i++){
		for(j=0;j<26 && f==0;j++){
			if(v[(c-i)-1]==l[j]){
				n=(pow(26,i)*(j+1));
				s=s+(n%1000000007);
			}		
		}
		f=0;
		n=0;
	}
	s=(s%1000000007);
	fprintf(out,"%u",s-1);
	fclose(in);
	fclose(out);
	
}
