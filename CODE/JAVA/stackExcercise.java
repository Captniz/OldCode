import java.util.*;

public class stackExcercise {
    public static void main(String[] args) {
        Stack<Integer> p1 = new Stack<Integer>();
        p1.add(1);
        p1.add(2);
        p1.add(3);
        System.out.println(p1);
        p1 = reverse(p1);
        System.out.println(p1);

    }

    public static Stack<Integer> reverse(Stack<Integer> p1) {
        Stack<Integer> tmp = new Stack<Integer>();
        while (!p1.isEmpty()) {
            tmp.push(p1.pop());
        }
        return tmp;
    }

}
