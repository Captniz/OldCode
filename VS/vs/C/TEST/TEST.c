/* Determina il numero di caratteri di un file esistente */
#include <stdio.h>
int main(){
 char buffer[100]; /* Buffer per la lettura */
 FILE *fp; // File pointer */
 long nc; /* Contatore caratteri */
 int n; /* Numero caratteri letti con fread() */
 int fine_file =0;/* Indica la fine della lettura del file */

 fp = fopen("prova.txt", "r");/* Apertura del file prova.txt */

 if( fp == NULL ){ /* Si è verificato un errore: il file non esiste */
    printf("Errore : il file non esiste\n");
 }else{
    nc = 0L; /* Inizializza il contatore */
    
    do { /* Ciclo di lettura */
        /* Legge 100 caratteri dal file ordini */
        n = fread(buffer, 1, 100, fp);
        if(n==0){ /* Controllo di fine file */
            fine_file = 1;
        }
        nc += n; /* Incremento del contatore */
    } while(fine_file==0);

    fclose(fp); /* Chiusura del file clienti */
    printf("Il file contiene %ld caratteri\n", nc);
 }
 return 0;
}
/* scrittura più compressa
 * while(1)
for(;;) {
 n = fread(buf, 1, 100, fp);
 if(n==0) break;
 nc += n;
}*/
/* Scrittura di una stringa in un file */
#include <stdio.h>
#include <string.h>
int main()
{
 char buffer[100]; /* Buffer */
 FILE *fp; /* File pointer */
 int len;
 
 printf("Inserisci un nome : ");
 scanf("%s",buffer);
 fflush(stdin);
 
 len = strlen(buffer);
 fp = fopen("prova2.txt", "w"); /* Crea il file prova2 */
 
 /* Memorizza il nome nel file */
 fwrite(buffer, 1, len, fp);
 fclose(fp); /* Chiude il file */
 printf("scrittura avvenuta correttamente");
 getchar();
 return 0;
}
// if( fp == NULL ) // memoria massa full

/*
1> copiare un file su un altro file
copia avvenuta correttamente
2> appendere file2 a file1 in un fileall (a)
3> leggere un file e vedere quante cifre ci sono [0..9]
*/