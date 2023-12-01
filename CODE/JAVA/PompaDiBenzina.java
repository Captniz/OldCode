/*
 * Un distributore di benzina ha N pompe e 1 serbatoio della capacità di M litri. Ogni automobile all’arrivo richiede una specifica quantità di benzina. 
 * Il serbatoio è rifornito da una autobotte che lo riempe fino alla capacità massima e solo se nessuna automobile sta facendo rifornimento.
 * Le automobile possono fare benzina solo se c’è una pompa libera, se la quantità di benzina richiesta è disponibile e se l’autobotte non sta riempiendo il serbatoio.
 */

public class PompaDiBenzina {
    public static void main(String[] args) {
        Pompa[] pompe = new Pompa[10];
        
        for (int i = 0; i < pompe.length; i++) {
            pompe[i] = new Pompa();
        }

        Autobotte serbatoio = new Autobotte(5000,);
    }
}

class Pompa{
    int LitriDisponibili;
    int value;

    Pompa(int LitriDisponibili){
        this.LitriDisponibili = LitriDisponibili;
        value = 1;
    }

    public synchronized void acquire(){
        if (value == 0){
            try{
                wait();
            }catch(Exception e){}
            value--;
        }
    }

    public synchronized void release(){
        value++;
        notify();
    }

    public int getValue() {
        return value;
    }

    public int getLitriDisponibili() {
        return LitriDisponibili;
    }
}

class Auto extends Thread{
    Pompa[] pompe;
    
    Auto(Pompa[] pompe){
        this.pompe = pompe;
    }

    synchronized Pompa acquirePompa(){
        while(true){
            for (int i = 0; i < pompe.length; i++) {
                if(pompe[i].getValue()==1){
                    pompe[i].acquire();
                    return pompe[i];
                }
            }
        }
    }

    public void rifornisci(){
        Pompa a = this.acquirePompa();
        try {
            Thread.sleep((int)(Math.random()*1000+300));
        } catch (Exception e) {}
        a.release();
    }
}

class Autobotte extends Thread{
    Pompa[] pompe;
    Serbatoio serb;
    
    Autobotte(Pompa[] pompe, Serbatoio serb){
        this.pompe = pompe;
        this.serb = serb;
    }
    
    public void refill(){
        for(;;){
            try{
                Thread.sleep(10000);
            }catch(Exception e){}
            
            for (int i = 0; i < pompe.length; i++) {
                pompe[i].acquire();
            }
            
            try{
                Thread.sleep(1500);
            }catch(Exception e){}
            Serbatoio.refill();
        }
    }
}

class Serbatoio{
    int LitriMaxSerbatoio;
    int Serbatoio;

    Serbatoio(int litri, Pompa[] pompe){
        LitriMaxSerbatoio = litri;
        Serbatoio = litri;
    }

    public void refill(){
        Serbatoio = LitriMaxSerbatoio;
    }

    public void refill(){
        Serbatoio = LitriMaxSerbatoio;
    }

    public int getLitriMaxSerbatoio() {
        return LitriMaxSerbatoio;
    }

    public int getSerbatoio() {
        return Serbatoio;
    }
}