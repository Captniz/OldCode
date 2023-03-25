import java.util.Scanner;

/*4>221110_calcolatrice.java 
Gestire una calcolatrice con almeno operazioni base: 
addizione, sottrazione, moltiplicazione, divisione (ma anche elevamento a potenza ...)
*/
//221110_calcolatrice.java
public class Calcolatrice {
    public float prev;

    Calcolatrice() {
        prev = 0;
    }

    float Add(float a, float b) {
        prev = a + b;
        return prev;
    }

    float Sub(float a, float b) {
        prev = a - b;
        return prev;
    }

    float Mul(float a, float b) {
        prev = a * b;
        return prev;
    }

    float Div(float a, float b) {
        prev = a / b;
        return prev;
    }

    float Pow(float a, float b) {
        prev = 1;
        for (int i = 0; i < b; i++) {
            this.Mul(prev, a);
        }
        return prev;
    }

    public static void main(String[] args) {
        Calcolatrice calc = new Calcolatrice();
        Scanner scn = new Scanner(System.in);
        int opt,opt2;
        float a, b;
        opt = 0;
        a = 0f;
        b = 0f;
        
        while(true) {
            System.out.print("\033[H\033[2J");
            System.out.println("Risultato precendente: " + calc.prev);

            System.out.print("Scegli un operazione: \n1) Addizione\n2) Sottrazione\n3) Moltiplicazione\n4) Divisione\n5) Elevamento a potenza\n6) Uscita\nOpzione:");
            opt = scn.nextInt();
            if (opt == 6) {
                System.out.print("\033[H\033[2J");
                System.out.println("Risultato finale: " + calc.prev);
                scn.close();
                System.exit(0);
            }

            System.out.print("\nUsare il risultato precendente come primo numero? \n1) Si \n2) No\nOpzione:");
            opt2 = scn.nextInt();

            if (opt2 == 1) {
                a = calc.prev;
            }else{
                System.out.print("\nInserisci il primo numero: ");
                a = scn.nextInt();
            }

            System.out.print("\nInserisci il secondo numero: ");
            b = scn.nextInt();
            
            switch (opt) {
                case 1:
                    calc.Add(a, b);
                    break;
                case 2:
                    calc.Sub(a, b);
                    break;
                case 3:
                    calc.Mul(a, b);
                    break;
                case 4:
                    calc.Div(a, b);
                    break;
                case 5:
                    calc.Pow(a, b);
                    break;  
                default:
                    System.out.println("Operazione non valida");
                    break;
            }
        }
    }
}
