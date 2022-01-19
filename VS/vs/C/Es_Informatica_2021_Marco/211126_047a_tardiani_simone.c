/*211126_047a_Chiodini_Fabio.c
quale data è maggiore tra 2 date 
riconducendo le 2 date all'anno 0
*/
#include<stdio.h>
int controllo_data(int, int, int);
int data_maggiore();
int main()
{
	int ctr;
	ctr=data_maggiore();
	if(ctr==1){
		printf("la prima data e' maggiore");
	}else{
		if(ctr==2){
			printf("la seconda data e' maggiore");
		}else{
			if(ctr==0){
				printf("le due date sono uguali");
			}
		}
	}
	return 0;
}
//Controllo data
int controllo_data(int gg, int mm, int aa){
	int bis;
	bis=0;
	if(gg<=0 || mm<=0 || mm>12 || aa<=0){
		return 0;
	}
	//anno bisestile
	if(aa%100==0 && aa%400==0){
		bis=1;
	}else{
		if(aa%4==0 && aa%100!=0){
			bis=1;
		}
	}
	//controllo giorni nei mesi
	switch (mm){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(gg>31){
				return 0;
			}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(gg>30){
				return 0;
			}
		break;
		case 2:
			if(bis==1){
				if(gg>29){
					return 0;
				}
			}else{
				if(gg>28){
					return 0;
				}
			}
		break;
	}
	return 1;
}
//verifica data maggiore
int data_maggiore(){
	int aa,mm,gg,aa2,mm2,gg2,ctr,ctr2,i;
	int ggmese[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	//prima data
	int err=0;
	while(err==0){
		printf("Inserire prima data:\n");
		do{
			printf("Inserisci il giorno: ");
			scanf("%d",&gg);
			while(getchar()!='\n');
		}while(gg<0);
		do{
			printf("Inserisci il mese: ");
			scanf("%d",&mm);
			while(getchar()!='\n');
		}while(mm<0);
		do{
			printf("Inserisci l'anno: ");
			scanf("%d",&aa);
			while(getchar()!='\n');
			}while(aa<0);
		err=controllo_data(gg,mm,aa);
	}
	//seconda data
	err=0;
	putchar('\n');
	while(err==0){
		printf("Inserire seconda data:\n");
		do{
			printf("Inserisci il giorno: ");
			scanf("%d",&gg2);
			while(getchar()!='\n');
		}while(gg2<0);
		do{
			printf("Inserisci il mese: ");
			scanf("%d",&mm2);
			while(getchar()!='\n');
		}while(mm2<0);
		do{
			printf("Inserisci l'anno: ");
			scanf("%d",&aa2);
			while(getchar()!='\n');
			}while(aa2<0);
		err=controllo_data(gg2,mm2,aa2);
	}
	ctr=ctr2=0;
	//somma prima data
	for(i=aa-1;i>0;i--){
		ctr=ctr+365;
		if(i%4==0){
			if(i%100==0){
				if(i%400==0){
					ctr++;
				}
			}else{
				ctr++;
			}
		}
	}
	printf("\nconta anni: %d",ctr);
	for(i=mm-1;i>0;i--){
		ctr=ctr+ggmese[i-1];
	}
	if(mm>2){
		if(aa%4==0){
			if(aa%100==0){
				if(aa%400==0){
					ctr++;
				}
			}else{
				ctr++;
			}
		}
	}
	ctr=ctr+gg;
	//somma seconda data
	for(i=aa2-1;i>0;i--){
		ctr2=ctr2+365;
		if(i%4==0){
			if(i%100==0){
				if(i%400==0){
					ctr2++;
				}
			}else{
				ctr2++;
			}
		}
	}
	printf("\nconta anni: %d",ctr2);
	for(i=mm2-1;i>0;i--){
		ctr2=ctr2+ggmese[i-1];
	}
	if(mm2>2){
		if(aa2%4==0){
			if(aa2%100==0){
				if(aa2%400==0){
					ctr2++;
				}
			}else{
				ctr2++;
			}
		}
	}
	ctr2=ctr2+gg2;
	printf("\n%d",ctr);
	printf("\n%d\n",ctr2);
	if(ctr>ctr2){
		return 1;
	}else{
		if(ctr<ctr2){
			return 2;
		}else{
			return 0;
		}
	}
	
}
