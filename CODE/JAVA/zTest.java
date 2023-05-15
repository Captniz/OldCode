import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.io.*;

public class zTest {
    public static void main(String[] args) {
        num a = new num();
        num b = a;
        System.out.println(a.getA());
        b = null;
        System.out.println(a.getA());
    }
}

class num {
    int a;
    num(){
        a = 100;
    }
    public int getA() {
        return a;
    }
    public void setA(int a) {
        this.a = a;
    }
}