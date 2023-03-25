/*9>221206_Near.java
Dato un vettore di 10 interi random[1..100] - tutti diversi fra loro(NB!!!) non ordinati - e un numero intero inserito da tastiera; scrivi un metodo statico che restituisca al programma principale, l'elemento del vettore più vicino al numero inserito , la sua posizione nel vettore e la sua distanza dal numero inserito.*/
//221206_Near.java
import java.util.Random;
class Near{
    final int DIM=10;
    final int RANGE=100;
    final int START=(-20);
    public int arr[];

    Near(){
        int tmp; 
        boolean found;
        Random rnd = new Random();
        arr = new int [DIM];

        for (int i = 0; i < DIM; i++) {
            do{
                tmp = rnd.nextInt(RANGE)+START;
                found=false;
                for(int j = 0; j<i;j++){
                    if (tmp==arr[j]) {
                        found=true;
                    }
                }
            }while(found);
            arr[i]=tmp;
        }
    }

    public int[] findNearest(int near){
        int position=0;
        int distance=RANGE+1;
        for (int i = 0; i < arr.length; i++) {
            if(Math.abs(near-arr[i])<distance){
                distance=Math.abs(near-arr[i]);
                position=i;
            }
        }
        int ret [] = {arr[position],position,distance};
        return ret;
    }

    public static void main(String[] args){
        int nScelta=15;
        int ret[] = new int [3];
        Near n = new Near();
        
        ret = n.findNearest(nScelta);
        
        //Stampa
        for (int i = 0; i < n.arr.length; i++) {
            System.out.print(n.arr[i]+ " ");
        }
        
        System.out.println("\n\nNumero scelto: " + nScelta);
        System.out.println("Numero piu' vicino: " + ret[0]);
        System.out.println("Posizione numero piu' vicino: " + ret[1]);
        System.out.println("Distanza numero piu' vicino: " + ret[2]);
    } 
}