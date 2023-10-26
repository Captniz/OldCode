import java.util.*;
import java.io.*;

public class es_tre {

    public static void main(String[] args) {
       Libro[] libri;
       
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            String tmp = "";
            int ctr = 0;
            tmp = br.readLine();
            while(tmp != null) {
                ctr++;
                tmp = br.readLine();
            }
            br.close();
       
            libri = new Libro[ctr];
            Scanner sc = new Scanner(new File("input.txt"));
            
            for(int i=0;i<ctr;i++){
                libri[i] = new Libro(Integer.parseInt(sc.next()),sc.next(),Float.parseFloat(sc.next()));
            }
            
            sc.close();
            int cod;
            Searcher[] s = new Searcher[4];

            for( ;; ){
                Scanner scn = new Scanner(System.in);
                System.out.println("Codice:");
                cod = scn.nextInt();
                int start = 0;
                int split = ctr/4;
                int mod = ctr%4;
                
                for(int i=0;i<3;i++){
                    s[i] = new Searcher(start,libri,cod,start+split);
                    s[i].start();
                    start += split;
                }
                s[3] = new Searcher(start,libri,cod,start+split+mod);
                s[3].start();
                for(int i=0;i<4;i++){
                    s[i].join();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}

class Searcher extends Thread{
    int start;
    Libro[] libri;
    int codice;
    int end;
    

    public Searcher(int start, Libro[] libri, int codice,int end) {
        this.start = start;
        this.libri = libri;
        this.codice = codice;
        this.end = end;
    }
    
    @Override
    public void run(){
        for(int i=start;i<end;i++){
            if(libri[i].getCode()==codice){
                System.out.println(libri[i].getName()+ ", Prezzo: " + libri[i].getPrc()); 
                return;
            }
        }
    }
}

class Libro{
    int code;
    String name;
   float prc;
    
    Libro(int code, String name, float prc){
        this.code = code;
        this.name = name;
        this.prc =prc;
    }

    public String getName() {
        return name;
    }

    public float getPrc() {
        return prc;
    }

    public int getCode() {
        return code;
    }
}