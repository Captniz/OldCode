#include <stdio.h>
#include <string.h>
int main(){
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	char qwert[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	int n,i,j,flag=0;
	fscanf(in,"%d",&n);
	char v[n];
	fscanf(in,"%s",&v);
	for(i=0;i<n;i++){
		for(j=0;j<26 && flag==0;j++){
			if(v[i]==qwert[j]){
				v[i]=qwert[j+1];
				flag++;
			}
		}
		flag=0;
	}
	for(i=0;i<n;i++){
		printf("%c",v[i]);
	}
	fclose(in);
	fclose(out);
	return 0;
}
