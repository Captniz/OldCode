/**
 * Interfacce
 */
public class Interfacce {
    public static void main(String[] args) {
        
    }
}
class Counter {
    private int val;

    public Counter(){
        val=0;
    }
    public Counter(int v){
        val=v;
    }
    public void reset(){
        val=0;
    }
    public int getValue(){
        return val;
    }
    public void inc(){
        val++;
    }

    public int compareTo(Object obj){
        Counter o = (Counter)obj;
        if(getValue() > o.getValue()){
            return 1;
        }else if(getValue() < o.getValue()){
            return -1;
        }
        return 0;
    }
}