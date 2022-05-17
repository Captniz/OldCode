#include<stdio.h>

#define DIM 10

void Bubble(int v[DIM]);
void Insertion(int v[DIM]);
void Selection(int v[DIM]);

int main()
{

    return 0;
}

void Bubble(int v[DIM]){
    int i,flag,temp,x,dim;
    dim=DIM;
    do{
		flag=0;
		for(i=0;i<dim-1;i++){
			if(v[i]>v[i+1]){
				temp=v[i];
				v[i]=v[i+1];
				v[i+1]=temp;
				flag=1;
				x=i+1;
			}
        }
		dim=x;
	}while(flag==1);
}

void Insertion(int v[DIM]){
	int i,j,min;
    for(i=1;i<DIM;i++){
        min=v[i];
        for(j=i-1;(j>=0) && (min<v[j]);j--){
            v[j+1]=v[j];
        }
        v[j+1]=min;
    }
}

void Selection(int v[DIM]){
	int i,j,imin,temp;
	for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM;j++){
			if(v[imin]>v[j]){
				imin=j;
			}
		}
		if(i!=imin){
            temp=v[i];
            v[i]=v[imin];
            v[imin]=temp;
		}
	}
}