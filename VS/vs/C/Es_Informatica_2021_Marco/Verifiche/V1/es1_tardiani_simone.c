//es1_tardiani_simone.txt

#include<stdio.h>

int main(){
	int v[]={69,52,53,54,55},i;
	i=0;
	
	for(i=0;i<(sizeof(v)/sizeof(v[0]));i++){
		printf("%3c",v[i]);
	}
	return 0;
}
