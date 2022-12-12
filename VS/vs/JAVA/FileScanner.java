import java.util.*;
import java.io.*;

class FileScanner{
    public static void main(String[] args) throws IOException {
        Scanner fle = new Scanner(new File("input.txt"));
        int ctr=0;
        while(fle.hasNextInt()){
            fle.nextInt();
            ctr++;
        }
        int arr[] = new int [ctr];
        fle = new Scanner(new File("input.txt"));
        ctr=0;
        while(fle.hasNextInt()){
            arr[ctr]=fle.nextInt();
            ctr++;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+ " ");
        }
    }
}