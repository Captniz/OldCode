/*83&gt; Gestione di un'anagrafica "anagrafica.dat"
(cognome, nome, indirizzo,eta)
1. Inserimento 
2. Modifica
3. Cancellazione 
4. Ricerca 
5. Visualizzazione  
0. Fine
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;string.h&gt;
#define DIM 100
struct persone{
	char cognome[30];
	char nome[30];
	char indirizzo[30];
	int eta;
};
int inserimento(FILE *fp);
int contanominativo(FILE *fp);
void visualizzazione(FILE *);
void copia(struct persone [], int , FILE *);
void ricerca(FILE *);
void modifica(struct persone [], int );
void cancellazione(FILE *);
int conta_eta(int);
void copia_file(struct persone [], FILE *);
int main(){
	struct persone v[DIM];
	FILE *fp;
	char nome_file[30];
	int dim,scelta;
	printf("inserire nome file: ");
	gets(nome_file);
	fflush(stdin);
	while(1){
		printf("\n1. Inserimento");
		printf("\n2. Modifica");
		printf("\n3. Cancellazione");
		printf("\n4. Ricerca");
		printf("\n5. Visualizzazione");
		printf("\n0. Uscita");
		printf("\nscelta: ");
		scanf("%d",&scelta);
		fflush(stdin);
		switch(scelta){
		case 1:
			fp=fopen(nome_file,"a");
			if(fp==NULL){
				perror("Errore");
				exit(1);
			}
			dim=inserimento(fp);
			fclose(fp);
			break;
		case 2:
			fp=fopen(nome_file,"r");
			if(fp==NULL){
				perror("Errore");
				exit(1);
			}
			dim=contanominativo(fp);
			fseek(fp,0,0);
			copia_file(v,fp);
			modifica(v,dim);
			fclose(fp);
			fp=fopen(nome_file,"w");
			copia(v,dim,fp);
			fclose(fp);
			break;
		case 3:
			fp=fopen(nome_file,"r+");
			if(fp==NULL){
				perror("Errore");
				exit(1);
			}
			cancellazione(fp);
			fclose(fp);
			break;
		case 4:
			fp=fopen(nome_file,"r");
			if(fp==NULL){
				perror("Errore");
				exit(1);
			}
			ricerca(fp);
			fclose(fp);
			break;
		case 5:
			fp=fopen(nome_file,"r");
			if(fp==NULL){
				perror("Errore");
				exit(1);
			}
			visualizzazione(fp);
			fclose(fp);
			break;
		case 0:
			return 0;
			break;
		default:
			printf("Errore nella scelta");
			break;
		}
	}
}
int contanominativo(FILE *fp){
	int ctr;
	ctr=0;
	char nome[30],cognome[30],indirizzo[30];
	int eta;
	while(fscanf(fp,"%s%s%s%d",nome,cognome,indirizzo,&eta)!=EOF){
		ctr++;
	}
	return ctr;
}
int inserimento(FILE *fp){
	int i,flag,eta;
	char cognome[30],nome[30],indirizzo[30];
	char c;
	flag=1;
	while(flag){
		printf("\ninserire cognome: ");
		gets(cognome);
		fflush(stdin);
		printf("\ninserire nome: ");
		gets(nome);
		fflush(stdin);
		printf("\ninserire indirizzo: ");
		gets(indirizzo);
		fflush(stdin);
		printf("\ninserire eta': ");
		scanf("%d",&eta);
		fflush(stdin);
		i++;
		fprintf(fp,"%s %s %s %d\n",cognome,nome,indirizzo,eta);
		printf("\n\ninserire altro nominativo? (y/n)");
		scanf("%c",&c);
		fflush(stdin);
		if(c=='n'){
			flag=0;
		}
	}
	return i;
}
void copia(struct persone v[DIM], int dim, FILE *fp){
	int i;
	for(i=0;i&lt;dim;i++){
		fprintf(fp,"%s %s %s %d\n",v[i].cognome,v[i].nome,v[i].indirizzo,v[i].eta);
	}
}
void visualizzazione(FILE *fp){
	char nome[30],cognome[30],indirizzo[30];
	int eta;
	while(fscanf(fp,"%s%s%s%d",cognome,nome,indirizzo,&eta)!=EOF){
		printf("\ncognome: %s",cognome);
		printf("\nnome: %s",nome);
		printf("\nindirizzo: %s",indirizzo);
		printf("\neta': %d",eta);
		putchar('\n');
		putchar('\n');
	}
}
void ricerca(FILE *fp){
	int i;
	char nome[30],cognome[30],indirizzo[30];
	char cognome_ric[30],nome_ric[30];
	int eta;
	char c='y';
	while(c=='y'){
		printf("inserire cognome: ");
		gets(cognome_ric);
		fflush(stdin);
		printf("inserire nome: ");
		gets(nome_ric);
		fflush(stdin);
		while(fscanf(fp,"%s%s%s%d",cognome,nome,indirizzo,&eta)!=EOF){
			if((strcmp(cognome_ric,cognome)==0) && (strcmp(nome_ric,nome)==0)){
				printf("nominativo trovato:\n");
				printf("\ncognome: %s",cognome);
				printf("\nnome: %s",nome);
				printf("\nindirizzo: %s",indirizzo);
				printf("\neta': %d",eta);
				putchar('\n');
				putchar('\n');
			}
		}
		fseek(fp,0,0);
		printf("ricercare un altro nominativo (y/n)? ");
		scanf("%c",&c);
		fflush(stdin);
	}
}
void modifica(struct persone v[DIM], int dim){
	int i;
	char nome[30],cognome[30];
	char c='y';
	while(c=='y'){
		printf("\ninserire cognome: ");
		gets(cognome);
		fflush(stdin);
		printf("\ninserire nome: ");
		gets(nome);
		fflush(stdin);
		for(i=0;i&lt;dim;i++){
			if((strcmp(cognome,v[i].cognome)==0) && (strcmp(nome,v[i].nome)==0)){
				printf("\nnominativo trovato\n");
				printf("\ninserire nuovo indirizzo: ");
				gets(v[i].indirizzo);
				fflush(stdin);
				printf("\ninserire nuova eta': ");
				scanf("%d",&v[i].eta);
				fflush(stdin);
			}
		}
		printf("\n\nmodificare altro nominativo (y/n): ");
		scanf("%c",&c);
		fflush(stdin);
	}
}
void cancellazione(FILE *fp){
	int i;
	char nome[30],cognome[30],indirizzo[30];
	char cognome_ric[30],nome_ric[30];
	int eta;
	int len,n,pos,posfin,temp;
	char c='y';
	char buffer[1000];
	int ctr;
	while(c=='y'){
		printf("inserire cognome: ");
		gets(cognome_ric);
		fflush(stdin);
		printf("inserire nome: ");
		gets(nome_ric);
		fflush(stdin);
		fseek(fp,0,0);
		while(fscanf(fp,"%s%s%s%d",cognome,nome,indirizzo,&eta)!=EOF){
			if((strcmp(cognome_ric,cognome)==0) && (strcmp(nome_ric,nome)==0)){
				n=ftell(fp);
				temp=fread(buffer,1,1000,fp);
				ctr=conta_eta(eta);
				len=n-(strlen(cognome)+strlen(nome)+strlen(indirizzo)+ctr+3+2);
				fseek(fp,len,0);
				if(temp!=1){
					fwrite(buffer,1,strlen(buffer),fp);
					pos=ftell(fp);
					fseek(fp,0,1);
				}
			}
		}
		printf("\ncancellazione avvenuta");
		fseek(fp,0,2);
		posfin=ftell(fp);
		fseek(fp,pos,0);
		for(i=pos;i&lt;posfin;i++){
			fputc(' ',fp);
		}
		printf("\nricercare un altro nominativo (y/n)? ");
		scanf("%c",&c);
		fflush(stdin);
	}
}
int conta_eta(int eta){
	int ctr;
	ctr=1;
	while(eta&gt;0){
		eta=eta/10;
		ctr++;
	}
	return ctr;
}
void copia_file(struct persone v[DIM], FILE *fp){
	int i;
	char cognome[30],nome[30],indirizzo[30];
	int eta;
	i=0;
	while(fscanf(fp,"%s%s%s%d",cognome,nome,indirizzo,&eta)!=EOF){
		strcpy(v[i].cognome,cognome);
		strcpy(v[i].nome,nome);
		strcpy(v[i].indirizzo,indirizzo);
		v[i].eta=eta;
		i++;
	}
}
