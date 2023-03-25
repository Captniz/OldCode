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
    public static void main(String[] args) {
        Rettangolo arr[ ]= new Rettangolo[3];
        arr[0]= new Rettangolo();
        arr[1]= new Rettangolo(5,6);
        arr[2]= new Rettangolo(20,30);

        for (int i = 0; i < 3; i++) {
            System.out.println("RETTANGOLO " + (i+1) + ":");
            System.out.println("Area " + (i+1) + ": " + arr[i].getArea());
            System.out.println("Perimetro " + (i+1) + ": " + arr[i].getPerim());
            System.out.print("\n\n");
        }
    }
}
