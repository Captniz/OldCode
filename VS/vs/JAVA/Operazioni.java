public class Operazioni {
    private int op1;
    private int op2;
    public int ctr;

    public Operazioni(int op1, int op2){
        this.op1 = op1;
        this.op2 = op2;
    }
    public int add(){
        return op1 + op2;
    }
    private int adder(int op, int opp){
        return op + opp;
    }
    public int multiplier(){
        for (int i = 0; i < op2; i++) {
            ctr=adder(ctr, op1);
        }
        return ctr;
    }
}
