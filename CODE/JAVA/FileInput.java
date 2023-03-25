import java.util.*;
import java.io.*;

public class FileInput {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        Stack<Integer> even = new Stack<Integer>();
        Stack<Integer> odd = new Stack<Integer>();
        try{
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            loadStack(br, stack);
            br.close();
        }catch(IOException e){
            System.out.println("Input/Output Error");
            e.printStackTrace();
        }
        /*
        //Alternativa più semplice e versatile
        
        try {
            Scanner sc = new Scanner(new File("input.txt"));
            while (sc.hasNext()) {
                stack.push(Integer.parseInt(sc.next()));
            }
            sc.close()
        } catch (FileNotFoundException e) {
            System.out.println("Si è verificato un errore durante la lettura del file.");
            e.printStackTrace();
        }*/
        
        splitStack(stack,even,odd);
        System.out.println("stack:" + stack);
        System.out.println("even:" + even);
        System.out.println("odd:" + odd);
    }
    static void loadStack(BufferedReader br,Stack<Integer> st){
        String line = "";
        //Bisogna ignorare questo errore, viene preso nel main
        try {
            while((line = br.readLine()) != null){
                st.push(Integer.parseInt(line));
            }
        } catch (Exception e) {
            return;
        }
    }
    static void splitStack(Stack<Integer> st,Stack<Integer> even,Stack<Integer> odd){
        int tmp = 0;
        while(!st.empty()){
            tmp=st.pop();
            if(tmp%2==0){
                even.push(tmp);
            }else{
                odd.push(tmp);
            }
        }
    }
}