import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class zTest {

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        Stack<Integer> s = new Stack<>();
        q.add(1);
        q.add(2);
        q.add(3);
        System.out.println(q);
        while(!q.isEmpty()){
            s.add(q.poll());
        }
        System.out.println(s);
    }
}