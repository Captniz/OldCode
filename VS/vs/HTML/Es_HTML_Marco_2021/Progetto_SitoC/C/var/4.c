/*4&gt; Dato un numero, contare quanti divisori pari e quanti divisori dispari ha.
Esempio: 16
Dispari: 1 			
Pari: 2 4 8 16 		*/
#include&lt;stdio.h&gt;

int main()
{
    int n,i;
    int DivisoriPari=0;
    int DivisoriDispari=0;
    printf("Numero?:");
    scanf("%d",&n);
	fflush(stdin);
    for (i=1; i&lt;=n; i++){
        if (n%i==0){
            if (i%2==0){
                printf("\n%d e' pari",i);
                DivisoriPari++;
            }else{
                printf("\n%d e' dispari",i);
                DivisoriDispari++;
            }
        }
    }
    printf("\nDivisori pari:%d",DivisoriPari);
    printf("\nDivisori dispari:%d",DivisoriDispari);
    return 0;
}

