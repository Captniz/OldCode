#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Bubble(int v[], int DIM);
void Insertion(int v[], int DIM);
void Selection(int v[], int DIM);
void Quick(int [],int, int, int DIM);
void scambia(int *, int *);
void vis(int [], int DIM);
void ranload(int [], int DIM, int RANDMAX, int RANDMIN);
int DiffData(int aa, int mm, int gg, int aa2, int mm2, int gg2);
void MergeOrdinated(int a[], int b[], int c[], int DIMa ,int DIMb);

void Bubble(int v[], int DIM){
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
void Insertion(int v[], int DIM){
	int i,j,min;
    for(i=1;i<DIM;i++){
        min=v[i];
        for(j=i-1;(j>=0) && (min<v[j]);j--){
            v[j+1]=v[j];
        }
        v[j+1]=min;
    }
}
void Selection(int v[], int DIM){
	int i,j,imin,temp;
	for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM ; j++){
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
void vis(int v[], int DIM){
    int i;
    for(i=0; i<DIM; i++){
        printf("%d ", v[i]);
    }
    putchar('\n');
}
void ranload(int v[], int DIM, int RANDMAX, int RANDMIN){
    int i;
    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    }
}
void Quick(int v[], int sin, int des, int DIM)
{
    int i, j, media;
    media= (v[sin]+v[des]) / 2; 
    i = sin;
    j = des;

    do {
        while(v[i]<media) {
            i++; 
        }
        while(media<v[j]) {
            j--; 
        }
        if(i<=j){
            scambia(&v[i], &v[j]);
            i++;
            j--;
        }
    }while (j>=i);

    if(sin<j){ 
        Quick(v,sin,j,DIM); 
    }

    if(i<des){
        Quick(v,i,des,DIM); 
    }
}
void scambia(int *a, int *b){
    int box;
    box = *a;
    *a = *b;
    *b = box;
}
int DiffData(int aa, int mm, int gg, int aa2, int mm2, int gg2){
    //*Var
    int ValueMesi[]={0,31,28,31,30,31,30,31,31,30,31,30};
    int i=0,ctr=0;

    //*anni
    aa=aa * 365 + ((aa/4) - ((aa/100)-((aa/100)/10)*8));
    aa2=aa2 * 365 + ((aa2/4) - ((aa2/100)-((aa2/100)/10)*8));

    //*mesi
    for ( i = 0; i < mm; i++){
        ctr+=ValueMesi[i];
    }
    mm=ctr;
    ctr=0;
    for ( i = 0; i < mm2; i++){
        ctr+=ValueMesi[i];
    }
    mm2=ctr;
    ctr=0;
    
    if (gg+mm+aa>gg2+mm2+aa2){
        return ((gg+mm+aa)-(gg2+mm2+aa2));
    }else if (gg+mm+aa<gg2+mm2+aa2){
        return ((gg2+mm2+aa2)-(gg+mm+aa));
    }else{
        return 1;
    }
}
void MergeOrdinated(int a[], int b[], int c[], int DIMa ,int DIMb){
    
    int i=0;
    int ctra=0;
    int ctrb=0;

    while ( ctra!= DIMa && ctrb != DIMb){
        if (a[ctra] <= b[ctrb]){
            c[ctra+ctrb]=a[ctra];
            ctra++;
        }else{
            c[ctra+ctrb]=b[ctrb];
            ctrb++;
        }
    }

    if (ctra==DIMa){
        for ( ctrb=ctrb; ctrb < DIMb; ctrb++){
           c[ctra+ctrb]=b[ctrb]; 
        }
    }else{
        for ( ctra = ctra; ctra < DIMa; ctra++){
           c[ctra+ctrb]=a[ctra]; 
        }
    }
}