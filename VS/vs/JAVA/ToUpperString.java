//Data una stringa portarla a maiuscolo
import java.util.Scanner;

class ToUpperString{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Stringa:");
        String str = new String(scan.nextLine());

        str= str.toUpperCase();

        System.out.println("\n" + str);
    }
}