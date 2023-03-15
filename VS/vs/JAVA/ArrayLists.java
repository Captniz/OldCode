import java.util.*;

public class ArrayLists {
    public static void main(String[] args) {
        Random rnd = new Random();
        ArrayList<Integer> list = new ArrayList<Integer>();

        System.out.print("Array:");
        for (int i = 0; i < 10; i++) {
            list.add(rnd.nextInt(5)+1);
            System.out.print(list.get(i) + " ");
        }
        System.out.println();

        int seq = 1;
        int maxSeq = 0;
        int addr = 0;
        int maxAddr = 0;
        int i=0;
        int j=0;    
        
        for(i = 1; i<list.size(); i++){
            if(list.get(i)==(list.get((i-1))+1)){
                seq++;
            }else{
                if (seq>maxSeq){
                    maxSeq = seq;
                    maxAddr = addr;
                }
                seq = 1;
                addr = i;
            }
        }
        if (seq>maxSeq){
            maxSeq = seq;
            maxAddr = addr;
        }

        System.out.print("Sequenza:");
        for(i = maxAddr; i<(maxAddr+maxSeq);i++){
            System.out.print(list.get(i) + " ");
        }
        System.out.println();

        for(i=0;i<list.size();i++){
            for (j = i; j < list.size(); j++) {
                if((i!=j) && list.get(i) == list.get(j)){
                    list.remove(j);
                    j--;
                }
            }
        }

        System.out.print("Array senza ripetizioni:");
        for (i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        System.out.println();
    }
}