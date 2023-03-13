/*
package pkg230304_java;

public class Main {

    public static void main(String[] args) {
        int Vettore1[] = {1,2,3,3,4,5,5,6,7,8};
        int Vettore2[] = new int [10]; 
        boolean flag=false;
        int ctr=0;
        
        System.out.println("Array base:");
        for(int i=0;i<10;i++){
            if(Vettore1[i]!=0){
                System.out.print(Vettore1[i]+" ");
            }
        }
        System.out.println("");
        
        for(int i=0;i<9;i++){
            flag=true;
            for(int j=(i+1);j<10;j++){
               if(Vettore1[i]==Vettore1[j]){
                   flag=false;
               }
            } 
            if(flag){
                Vettore2[ctr]=Vettore1[i];
                ctr++;
            }
        }
        
        System.out.println("Array2:");
        for(int i=0;i<10;i++){
            if(Vettore2[i]!=0){
                System.out.print(Vettore2[i]+" ");
            }
        }
        System.out.println("");
        
        1
    }
}
*/

public class Main {

    public static void main(String[] args) {
        int Vettore1[] = {1,2,4,4,4,5,5,6,7,1};
        int Vettore2[] = new int [10]; 
        boolean flag=false;
        int ctr=1;
        
        System.out.println("Array base:");
        for(int i=0;i<10;i++){
            if(Vettore1[i]!=0){
                System.out.print(Vettore1[i]+" ");
            }
        }
        System.out.println("");
        
        //CORREZIONE
        Vettore2[0]=Vettore1[0];
        for(int i=1; i<Vettore1.length; i++){
            flag=true;
            for(int j=0; j<Vettore2.length; j++){
                if(Vettore1[i]==Vettore2[j]){
                    flag=false;
                }
            }
            if(flag){
                Vettore2[ctr]=Vettore1[i];
                ctr++;
            }
        }
        //END CORREZIONE
        
        /*
        for(int i=0;i<9;i++){
            flag=true;
            for(int j=(i+1);j<10;j++){
               if(Vettore1[i]==Vettore1[j]){
                   flag=false;
               }
            } 
            if(flag){
                Vettore2[ctr]=Vettore1[i];
                ctr++;
            }
        }*/
        
        System.out.println("Array2:");
        for(int i=0;i<10;i++){
            if(Vettore2[i]!=0){
                System.out.print(Vettore2[i]+" ");
            }
        }
        System.out.println("");

        //CORREZIONE 
        
        int prevAddr=0;
        int prevLen=0;
        int len=1;
        int addr=0;
        int i=0;
        for( i=1;i<Vettore2.length;i++){
            if(Vettore2[i]==(Vettore2[(i-1)]+1)){
                len++;
            }else{
                if(len>prevLen){
                    prevLen=len;
                    prevAddr=addr;
                }
                len=1;
                addr=i;
            }
        }
        if(len>prevLen){
            prevLen=len;
            prevAddr=addr;
        }
        
        //END CORREZIONE
        
        System.out.println("Seq piu lunga: ");
        for(i=prevAddr;i<prevLen+prevAddr;i++){
            System.out.print(Vettore2[i]+" ");
        }
        System.out.println("");
    }
}

//ERRORI NON SO FARE LA SEQ E SBAGLIATA LA CONSEGNA DEI DUPLICATI