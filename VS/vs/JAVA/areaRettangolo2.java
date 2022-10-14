//javac args 3 5
public class areaRettangolo2{
    public static void main(String[] args){
        int base = Integer.valueOf(args[0]).intValue();
        int altezza = Integer.valueOf(args[1]).intValue();
        int area = 0;
        area = base * altezza;

        System.out.println("Base = " + base + "\nAltezza = " + altezza + "\nArea = " + area);
    }
} 