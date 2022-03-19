/*
Implementare in C il seguente algoritmo ricorsivo:
• m, se m = n
• MCD (m-n , n) , se m>n
• MCD( m , n-m), se m<n
*/

#include<stdio.h>

int mcd (int m, int n);

int main(){
	int m,n;
	m=0;
	n=0;
	
	printf("m:");
	scanf("%d",&m);
	printf("\nn:");
	scanf("%d",&n);
	
	printf("\n\nRisultato:%d",mcd(m,n));
	
	return 0;
}

int mcd (int m, int n){
	
	if(m==n){
		return m;
	}else if(m>n){
		return mcd((m-n),n);
	}else{
		return mcd(m,(n-m));
	}
}
