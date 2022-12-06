import java.util.Scanner;

/*8>221205_clock.java
Scrivere una classe Orologio per simulare il comportamento di un orologio. La classe contiene un costruttore parametrizzato con tre argomenti 
* (ore, min, sec) e uno di default settato a 00:00:00. Possiede inoltre un metodo public che incrementa i secondi (potrebbe far scattare i minuti), 
* uno che incrementa i minuti (potrebbe far scattare le ore) e uno che incrementa le ore(non fa scattare nulla dopo 23 riparte 00 - 
* non esiste un metodo per tornare indietro). Infine un metodo che stampa l'ora. (NB: si ricorda che non esiste 60 per ore, min, sec ma [0..59])*/

public class Clock {
    private int hh;
	private int mm;
	private int ss;
	
    ClocK(int hhh;int mmm;int sss){
        hh=hhh;
        mm=mmm;
        ss=sss;
        if(this.Check()>0){
            hh=0;
            mm=0;
            ss=0;
            System.out.println("!!!DATI NON VALIDI!!!");
        }
    }
	Clock(){
		hh=0;
		mm=0;
		ss=0;
	}
    private int Check(){
        if(hh>=24 || hh<0||mm>=60|| mm<0||ss>=60 || ss<0){
            System.out.println("!!!DATI NON VALIDI!!!");
            return 1;
        }
        return 0;
    }
    private void CheckAdder(){
        int ctr=0;
        while(ss>=60){
            ss-=60;
            ctr++;
        }
        mm+=ctr;
        ctr=0;
        while(mm>=60){
            mm-=60;
            ctr++;
        }
        hh+=ctr;
        while(hh>=24){
            hh-=24;
        }
    }
    public int setH(int hhh){
        int tmp;
        tmp=hh;
        hh=hhh;
        if(this.Check()>0){
            hh=tmp;
            return 1;
        }
        return 0;
    }
    public int setM(int mmm){
        int tmp;
        tmp=mm;
        mm=mmm;
        if(this.Check()>0){
            mm=tmp;
            return 1;
        }
        return 0;
    }
    public int setS(int sss){
        int tmp;
        tmp=ss;
        ss=sss;
        if(this.Check()>0){
            ss=tmp;
            return 1;
        }
        return 0;
    }
    public void addS(int sss){
        ss+=sss;
        this.CheckAdder();
    }
    public void addM(int mmm){
        mm+=mmm;
        this.CheckAdder();
    }
    public void addH(int hhh){
        hh+=hhh;
        this.CheckAdder();
    }	
	public void Print(){
		System.out.format("%2d:%2d:%2d",hh,mm,ss);
	}
    public static void main(String[] args) {
        int hh=0,mm=0,ss=0;
        Scanner scn = new Scanner(System.in);
        Clock c = new Clock();
        
        do{
            System.out.print("Ore:");
        }while(c.setH(scn.nextInt())>0);

        do{
            System.out.print("Minuti:");
        }while(c.setM(scn.nextInt())>0);

        do{
            System.out.print("Secondi:");
        }while(c.setS(scn.nextInt())>0);
        
        c.addM(60);

        c.Print();
    }
}
