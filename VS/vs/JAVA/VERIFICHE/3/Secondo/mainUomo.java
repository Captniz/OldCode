//Primo.java
import java.util.*;
public class mainUomo{
	public static void main(String args[]){
		int i=0;
		Random rnd = new Random();
		Stagista s[] = new Stagista[10];
		Uomo u = new Uomo("Pietro","Bini","Maschio","Bologna");
		String c[] = {"Bologna","Milano","Roma","Mantova","Firenze"};
		
		u.stampa(); 
		
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		s[i]= new Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(5)+1],rnd.nextInt(40)+10,++i);
		
		for(i=0;i<10;i++){
				s[i].stampa();
		}
		
		System.out.println("\nIl Piu giovane:");
		s[getGiovane(s)].stampa();
		
		System.out.println("\nCitta pref:");
		getCittaPref(s,c);
		
	}
	
	static int getGiovane(Stagista s[]){
		int i=1;
		int min=s[0].annoNascita();
		int addr=0;
		for(i=1;i<10;i++){
			if(min>s[i].annoNascita()){
				min=s[i].annoNascita();
				addr=i;
			}
		}
		return i;
	}
	static void getCittaPref(Stagista s[], String c[]){
		int ctr=0;
		int prevctr=0;
		int cit=0;
		for(int i=0;i<c.length;i++){
			for(int j=0;j<s.length;j++){
				if(s[j].getCit()==c[i]){
					ctr++;
				}
			}
			if(ctr>prevctr){
				cit=i;
				prevctr=ctr;
			}
			ctr=0;
		}
		System.out.print(c[cit] + " " + prevctr);
	}
}

