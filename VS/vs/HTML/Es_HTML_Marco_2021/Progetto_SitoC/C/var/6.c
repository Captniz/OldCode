/*6&gt; inserire dei numeri e visualizzare i due maggiori (0 to end)*/

#include&lt;stdio.h&gt;
int main()
{
	int n,max1=0,max2=0;

	do{
		printf("numero: ");
		scanf("%d",&n);
		fflush(stdin);
		
		if(n&gt;max1){
			max2=max1;
			max1=n;
		}else{
			if(n&gt;max2){
				max2=n;
			}
		}	
	}while(n!=0);
	
	printf("il primo numero maggiore: %d\n",max1);
	printf("il secondo numero maggiore: %d",max2);
	
	return 0;
}

