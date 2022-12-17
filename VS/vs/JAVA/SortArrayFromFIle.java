import java.util.*;
import java.io.*;

class SortArrayFromFIle {
    int v[];
    SortArrayFromFIle(int size){
        v= new int [size];
    };
    static int readFileLength(Scanner fle){
        int l=0;
        while (fle.hasNext()==true) {
            l++;
            fle.nextInt();
        }
        return l;
    }
    void readFile(Scanner fle){
        int ctr=0;
        while(fle.hasNextInt()){
            v[ctr]=fle.nextInt();
            ctr++;
        }
    };
    void sort(){
        int tmp=0;
        for(int i=0;i<(v.length-1);i++){
            for(int j=i+1;j<v.length;j++){
                if(v[i]>v[j]){
                    tmp=v[i];
                    v[i]=v[j];
                    v[j]=tmp;
                }
            }
        }
    };
    void print(){
        for (int i = 0; i < v.length; i++) {
            System.out.println(v[i]);
        }
        System.out.println("Size:"+v.length);
    }
    public static void main(String[] args) throws IOException{
        Scanner fle;
        fle= new Scanner(new File("./input.txt"));                       
        SortArrayFromFIle c = new SortArrayFromFIle(readFileLength(fle));
        fle= new Scanner(new File("./input.txt")); 
        c.readFile(fle);
        c.sort();
        c.print();
    }
}