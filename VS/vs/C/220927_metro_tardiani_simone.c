/*
Il file binario metrodata.dat ha un record avente la seguente struttura:

struct registra {

    int stazione;

    int scesi;

    int saliti;

}

e contiene un record per ogni stazione – identificata da un codice numerico – del percorso di una linea metropolitana. Scrivere un programma che legga il contenuto di metrodata.dat e produca un file di tipo .txt (metrodata.txt) la cui singola riga abbia un formato #101,20+,80- e determinare il numero di persone che sono presenti sulla metro all’ultima stazione.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct registra {

    int stazione;

    int scesi;

    int saliti;

} reg; 

int main(){
    
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    reg buf;
    int ctr=0;

    if(out==NULL || in == NULL){
        printf("Errore file");
        exit(1);
    }

    while (fread(&buf,sizeof(reg),1,in)){
        printf("#%d, +%d, -%d\n",buf.stazione,buf.saliti,buf.scesi);
        fprintf(out, "#%d, +%d, -%d\n",buf.stazione,buf.saliti,buf.scesi);
        ctr=ctr+buf.saliti-buf.scesi;
    }
    fprintf(out,"Passegeri stazione finale:%d",ctr);

    fclose(in);
    fclose(out);

    return 0;
}
