/*50&gt;Dato un array v dimensionato DIM=10 
ordinare gli elementi limitatamente alla posizione del max e del min.
Se il min precede il max ordinamento crescente 
altrimenti decrescente.
ES: 1 5 3 9 8 5 
    ^     ^
    1 3 5 9 8 

ES: 2 9 3 7 8 1
      ^       ^
    2 9 8 7 3 1
*/

#include&lt;stdio.h&gt;
#define DIM 10
void visualizza(int []);
int pmax(int []);
int pmin(int []);
void ordina(int [],int ,int );



int main(){
	int v[DIM]={5,3,1,6,7,8,9,2,4,10};
	int max,min;
	visualizza(v);
	max=pmax(v);
	min=pmin(v);
	ordina(v,max,min);
	visualizza(v);
	return 0;
}
void visualizza(int v[]){
	int i;
	for(i=0;i&lt;DIM;i++){
		printf("%d ",v[i]);
	}
	putchar('\n');
}
int pmax(int v[]){
	int i,max,pmax;
	max=v[0];
	for(i=0;i&lt;DIM;i++){
		if(v[i]&gt;max){
			max=v[i];
			pmax=i;
		}
	}
	printf("%d\n",max);
	printf("posizione %d\n",pmax);
	return pmax;
}
int pmin(int v[]){
	int i,min,pmin;
	min=v[0];
	for(i=0;i&lt;DIM;i++){
		if(v[i]&lt;min){
			min=v[i];
			pmin=i;
		}
	}
	printf("%d\n",min);
	printf("posizione %d\n",pmin);
	return pmin;
}
void ordina(int v[],int max,int min){
	int i,j,box;
		if(min&lt;max){
			for(i=min;i&lt;max;i++){
				for(j=min;j&lt;max;j++){
					if(v[i]&lt;v[j]){
						box=v[i];
						v[i]=v[j];
						v[j]=box;
					}
				}
			}
		}else{
			if(min&gt;max){
			for(i=max;i&lt;min;i++){
				for(j=max;j&lt;min;j++){
					if(v[i]&gt;v[j]){
						box=v[i];
						v[i]=v[j];
						v[j]=box;
					}
				}
			}
		}
	}
}
