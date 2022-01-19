//211103_002_tardiani_simone.c
/*la funzione max3 riceve in ingresso tre valori interi a, b, c e restituisce il massimo dei 3.
Testare nel main la funzione (inserire a, b, c da tastiera).*/

#include<stdio.h>

int max3(int a,int b,int c);
int InNum();

int main(){
	printf("%d",max3(InNum(),InNum(),InNum()));
	return 0;
}

int InNum(){
	
	int a=0;
	
	printf("Numero:");
	scanf("%d",&a);
	
	return a;	
}

int max3(int a,int b,int c){
	
	if(a>b){
		if(a>c){
			return a;
		}
	}else{
		if(b>c){
			return b;
		}else{
			return c;
		}
	}
}
