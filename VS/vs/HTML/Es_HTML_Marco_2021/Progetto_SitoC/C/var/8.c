/*46> Una volta controllato che due date sono valide trovare la differenza in giorni tra le due date.
(Potrebbe risultare utile stabilire prima quale delle due date è maggiore).
*/
#include <stdio.h>
int max_data();
int controllo_data();
int main(){
	max_data();
	return 0;
}
int max_data(){
	int ctrgg=0,aamax,aamin,ggmax,ggmin,ctrbis=0,i,gg,mm,aa,gg2,mm2,aa2,err=0;
	int ggmese[12]={31,28,31,30,31,30,31,31,30,31,30,31},mmmax,mmmin;
	//prima data
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
	//aamax
	if(aa!=aa2){
		if(aa>aa2){
			aamax=aa;
			aamin=aa2;
			mmmax=mm;
			mmmin=mm2;
			ggmax=gg;
			ggmin=gg2;
	}else{
		if(aa<aa2){
			aamax=aa2;
			aamin=aa;
			mmmax=mm2;
			mmmin=mm;
			ggmax=gg2;
			ggmin=gg;			
		}
	}
	}
	//mese max
	if(aa==aa2){
		if(mm>mm2){
			mmmax=mm;
			mmmin=mm2;
			ggmax=gg;
			ggmin=gg2;
		}else{
			if(mm<mm2){
				mmmax=mm2;
				mmmin=mm;
				ggmax=gg2;
				ggmin=gg;
			}
		}
	}
	//ggmax
	if(aa==aa2 && mm==mm2){
		if(gg>gg2){
			ggmax=gg;
			ggmin=gg2;
		}else{
			ggmax=gg2;
			ggmin=gg;
		}
	}
	//counter anni e bisestili
	if(aa==aa2 && mm!=mm2){
		if(mmmin<=2 && mmmax>=2){
			if(aa%4!=0){
			}else{
				if(i%100==0){
					if(i%400==0){
						ctrbis++;
					}	
				}
			}
		}
		
	}
	ctrgg=ctrgg+ctrbis;
	if(aa!=aa2){
		for(i=aamin+1;i<aamax;i++){
			if(i%4!=0){
			}else{
				if(i%100==0){
					if(i%400==0){
						ctrbis++;
					}	
				}else{
					ctrbis++;
				}
			}
			ctrgg=ctrgg+365;
		}
		ctrgg=ctrgg+ctrbis;
	}
	//counter mesi
	if(aa==aa2){
		for(i=mmmin;i<mmmax-1;i++){
			ctrgg=ctrgg+ggmese[i];
		}
	}else{
		for(i=mmmin;i<12;i++){
			ctrgg=ctrgg+ggmese[i];
		}
		for(i=0;i<mmmax-1;i++){
			ctrgg=ctrgg+ggmese[i];
		}
	}
	//counter giorni
	if(aa==aa2 && mm==mm2 && gg==gg2){
	}else{
		ctrgg=ctrgg+(ggmese[mmmin-1]-ggmin);
		ctrgg=ctrgg+ggmax;
	}
	if(aa!=aa2){
		if(mmmin<=2){
			if(aa%4!=0){
				}else{
					if(i%100==0){
						if(i%400==0){
							ctrgg++;
						}	
					}else{
						ctrgg++;	
					}
				}
		}
		if(mmmax>2){
			if(aa%4!=0){
				}else{
					if(i%100==0){
						if(i%400==0){
							ctrgg++;
						}	
					}else{
						ctrgg++;
					}
				}
		}
	}
	
	printf("\nI giorni di differenza sono: %d",ctrgg);
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
