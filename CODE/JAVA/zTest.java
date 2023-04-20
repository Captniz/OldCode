import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.io.*;

public class zTest {
    public static void main(String[] args) {
       int[] a = {10,2,4,5,6};
       //contqxtualy load a queue
         Queue<Integer> q = new LinkedList<Integer>();
            for(int i=0; i<a.length; i++) {
                q.add(a[i]);
            }
    }
}