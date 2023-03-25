import java.util.Scanner;
//221028_AreaRettangoloInput.java
class AreaRettangoloInput{
    public static void main(String[] args){
        int area = 0;
        int base = 0;
        int altezza = 0;
        Scanner scn = new Scanner(System.in);
        System.out.println("Inserisci la base: ");
        base = scn.nextInt();
        System.out.println("Inserisci l'altezza: ");
        altezza = scn.nextInt();
        area = base * altezza;

        System.out.println("Base: " + base + "\nAltezza: " + altezza + "\nArea: " + area);
        scn.close();
    }
} 