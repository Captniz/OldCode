/*72&gt; ADT simulato di uno stack mediante un array 
simuliamo DIM = 5
    printf("\n1 -&gt; Aggiungi el" );
    printf("\n2 -&gt; Estrai el");
    printf("\n3 -&gt; Svuota stack");
    printf("\n4 -&gt; Visualizza stack");
    printf("\n0 -&gt; Esc");

primitive:
void push(element, stack);
element pop(stack);
boolean isEmpty(stack);
boolean isFull(stack);
int Top(stack);
void clear(stack)

NB: i controlli: ad es. prima di estrarre un el lo stack deve averne almeno uno
prima di aggiungere un el lo stack non deve essere pieno ... etc
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;string.h&gt;
#define DIM 10
void Push(int v[DIM],int n);
int Pop(int v[DIM]);
int isEmpty(int v[DIM]);
int isFull(int v[DIM]);
int Top(int v[DIM]);
void clear(int v[DIM]);
int menu(int *e, int v[DIM], int n);
int main(){
    int Stack[DIM],e,n;
    e=0;
    n=0;
    clear(Stack);
    while(1){
        switch (menu(&e, Stack, n)){
        case 0:
            return 0;
            break;
        
        case 1:
            if (!isFull(Stack)){
                printf("Elemento:");
                scanf("%d",&n);
                Push(Stack,n);
            }else{
                e=2;
            }
            break;

        case 2:
            if (!isEmpty(Stack)){
                n = Pop(Stack);
                e=4;
            }else{
                e=2;
            }
            break;

        case 3:
            clear(Stack);
            break;

        case 4:
            e=3;
            break;

        default:
            e=1;
            break;
        }
    }
    return 0;
}

void Push(int v[DIM],int n){
    int i;
    for(i=(DIM-1);i&gt;0;i--){
        v[i]=v[i-1];
    }
    v[0]=n;
}
int Pop(int v[DIM]){
    int i,temp;
    temp=v[0];
    for(i=1;i&lt;DIM;i++){
        v[i-1]=v[i];
    }
    v[DIM-1]=0;
    return temp;
}
int isEmpty(int v[DIM]){
    if(v[0]){
    	return 0;
    }
    return 1;
}
int isFull(int v[DIM]){
    if(v[(DIM-1)]){
        return 1;
    }
    return 0;
}

int Top(int v[DIM]){
    return v[0];
}
void clear(int v[DIM]){
    int i;
    for(i=0;i&lt;DIM;i++){
        v[i]=0;
    }
}
int menu(int *e, int v[DIM], int n){
    int i;
    for(i=0;i&lt;50;i++){
        putchar('\n');
    }
    switch (*e){
    case 1:
    	printf("!!!INPUT ERRATO!!!\n");
        break;
    case 2:
        printf("!!!STACK NON PRONTO A ESEGUIRE L'OPERAZIONE!!!\n");
        break;
    case 3:
        for(i=0;i&lt;DIM;i++){
            printf("%3d\n",v[i]);
        }
        break;
    case 4:
        printf("%d\n",n);
        break;
    default:
        break;
	}
    printf("\n1 -&gt; Aggiungi el\n2 -&gt; Estrai el\n3 -&gt; Svuota stack\n4 -&gt; Visualizza stack\n0 -&gt; Esc\nOpzione:" );
    scanf("%d", &i);
    fflush(stdin);
    *e=0;
    return i;
}
