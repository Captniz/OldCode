/*211126_047b_Chiodini_Fabio.c
Dire quale data è maggiore tra 2 date
partendo dall'anno se a1 = a2 allora confronto mese1 con mese2 ... etc.
*/
#include<stdio.h>
int controllo_data(int, int, int);
int data_maggiore();
int main()
{
	int ctr;
	ctr=data_maggiore();
	if(ctr==0){
		printf("la prima data e' maggiore");
	}else{
		if(ctr==1){
			printf("la seconda data e' maggiore");
		}else{
			if(ctr==2){
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
	int aa,mm,gg,aa2,mm2,gg2,ctr;
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
	if(aa>aa2){
		return 0;
	}else{
		if(aa<aa2){
			return 1;
		}else{
			if(mm>mm2){
				return 0;
			}else{
				if(mm<mm2){
					return 1;
				}else{
					if(gg>gg2){
						return 0;
					}else{
						if(gg<gg2){
							return 1;
						}else{
							return 2;
						}
					}
				}
			}
		}
	}
}
