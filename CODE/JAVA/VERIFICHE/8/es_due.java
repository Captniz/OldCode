package es_due;

public class es_due {
    public static void main(String[] args){
        Tavolo t = new Tavolo(6);
        AiutoCuoco a = new AiutoCuoco(t);
        Chef c = new Chef(t);
        
        a.start();
        c.start();
    }
}

class AiutoCuoco extends Thread{
    Tavolo t;
    int ctr;
    
    AiutoCuoco(Tavolo t){
        this.t = t;
        ctr = 1;
    }
    
    @Override
    public void run(){
        for( ;; ){
            try {
                Thread.sleep((int)(Math.random()*1000)); 
                t.push("Piatto " + ctr);
                System.out.println("Pronto il piatto " + ctr);
                ctr++;

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Chef extends Thread{
    Tavolo t;
    
    Chef(Tavolo t){
        this.t = t;
    }
    
    @Override
    public void run(){
        for( ;; ){
            try {
                if(t.isEmpty()){
                    Thread.sleep((int)(Math.random()*1000));
                    continue;
                }
                System.out.println(t.toString());
                System.out.println("Consegnato al cliente il " + t.pop());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Tavolo{
    int N;
    int in;
    int out;
    String[] b;

    Tavolo(int DIM){
        N = DIM;
        in = 0;
        out = 0;
        b = new String[DIM]; 
    }
    
    public synchronized void push(String piatto){
        b[in] = piatto;
        in = (in+1)%N;
    }
    
    public synchronized String pop(){
        String tmp = b[out];
        out = (out+1)%N;
        return tmp;
    }
    
    public boolean isEmpty(){
        if(in==out){
            return true;
        }
        return false;
    }
    
    @Override
    public String toString(){
		String tmp = "";
		for(int i=0;i<b.length;i++){
			tmp+="["+b[i]+"]";
		}
        return tmp;
    }
}