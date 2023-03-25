/**
 * vector
 */
import java.util.*;
public class vector {
    public static void main(String[] args) {
        Vector<Integer> v = new Vector<>();
        Random rnd = new Random();
        int tmp = 0;
        for (int i = 0; i < 15; i++) {
            v.add(rnd.nextInt(1, 100));
        }
        

        for (int i = 0; i < (15-1); i++) {
            for (int j = (i+1); j <15; j++) {
                if((int)v.get(i)>(int)v.get(j)){
                    tmp = (int)v.get(i);
                    v.set(i, v.get(j));
                    v.set(j,tmp);
                }
            }
        }
        System.out.println(v);
    }
}