public class Rettangolo {
    private int b;
    private int h;

    public Rettangolo(){
        b=10;
        h=10;
    }
    public Rettangolo(int base, int altezza){
        b=base;
        h=altezza;
    }
    public int getBase(){
        return b;
    }
    public int getAltezza(){
        return h;
    }
    public int getArea(){
        return b*h;
    }
    public int getPerim(){
        return (b+h)*2;
    }
    public void setBase(int var){
        b = var;
    }
    public void setAltezza(int var){
        h = var;
    }
}
