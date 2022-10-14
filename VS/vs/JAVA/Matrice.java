/*Data una matrice di interi trovare la riga o la colonna con somma più alta.
Se viene inserita una sola dimensione la matrice è quadrata dimensione x dimensione.
Se vengono inserite due dimensioni la matrice è rettangolare riga x colonna.
Qualsiasi altro caso è errato.*/
import java.util.Random;

class Matrice{
    public static void main(String[] args) {
        int mat[][];
        int max,ctr,maxCoord;
        max=0;
        ctr=0;
        maxCoord=0;
        Random rand = new Random();

        //Controllo argomenti e crea matrice
        if (args.length == 1) {
            mat = new int[Integer.parseInt(args[0])][Integer.parseInt(args[0])];
        }else if(args.length == 2) {
            mat = new int[Integer.parseInt(args[0])][Integer.parseInt(args[1])];
        } else {
            System.out.println("Errore: numero argomenti");
            return;
        }
        
        //Inizializza matrice con numeri casuali; inoltre calcola la somma di ogni riga
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                mat[i][j]=rand.nextInt(25);
                ctr=ctr+mat[i][j];
            }
            if (ctr>max) {
                max=ctr;
                maxCoord=i;
            }
            ctr=0;
        }

        //Stampa matrice
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                System.out.format("%3d",mat[i][j]);
            }
            System.out.println();
        }

        //calcola la somma di ogni colonna
        for (int i = 0; i < mat[0].length; i++) {
            for (int j = 0; j < mat.length; j++) {
                ctr=ctr+mat[j][i];
            }
            if (ctr>max) {
                max=ctr;
                maxCoord=(i * -1);
            }
            ctr=0;
        }

        //Stampa risultato
        if (maxCoord>=0) {
            System.out.println("La riga con somma piu alta e' la "+maxCoord+" con somma "+max);
        }else{
            System.out.println("La colonna con somma piu alta e' la "+(maxCoord * -1)+" con somma "+max);
        }
    }
}
