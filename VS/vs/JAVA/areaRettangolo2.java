//javac args 3 5
//221028_AreaRettangolo2.java
public class AreaRettangolo2{
    public static void main(String[] args){
        int base = Integer.valueOf(args[0]).intValue();
        int altezza = Integer.valueOf(args[1]).intValue();
        int area = 0;
        area = base * altezza;

        System.out.println("Base = " + base + "\nAltezza = " + altezza + "\nArea = " + area);
    }
} 