//Data una stringa fare il reverse
import java.util.Scanner;

class ReverseString{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = new String();
        char TempArr[0];
        
        System.out.print("Stringa:");
        str = new String(scan.nextLine());
        TempArr[] = new char [str.length()];

        for(int i = (str.length()-1); i >= 0; i--){
            TempArr[(str.length()-1-i)] = str.charAt(i); 
        }
        str = new String(TempArr);

        System.out.println("\n" + str);
    }
}