/*45&gt; Progettare e realizzare una funzione che effettui il controllo di validit� (data entry) 
della data immessa nella forma gg/mm/aaaa.
1 se valida
0 se non valida
*/
#include&lt;stdio.h&gt;
int controllo_data();
int main()
{
	int ctr;
	ctr=controllo_data();
	if(ctr==0){
		printf("data non valida");
	}else{
		printf("data valida");
	}
	return 0;
}
int controllo_data(){
	int gg,mm,aa,bis;
	bis=0;
	printf("inserire il giorno: ");
	scanf("%d",&gg);	
	fflush(stdin);
	printf("inserire il mese: ");
	scanf("%d",&mm);
	fflush(stdin);
	printf("inserire l'anno: ");
	scanf("%d",&aa);
	fflush(stdin);
	if(gg&lt;=0 || mm&lt;=0 || mm&gt;12 || aa&lt;=0){
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
			if(gg&gt;31){
				return 0;
			}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(gg&gt;30){
				return 0;
			}
		break;
		case 2:
			if(bis==1){
				if(gg&gt;29){
					return 0;
				}
			}else{
				if(gg&gt;28){
					return 0;
				}
			}
		break;
	}
	if(aa&lt;=0){
		return 0;
	}
	return 1;
}


