//Primo.java
import java.util.*;
public class Uomo{
	protected String nome;
	protected String cognome;
	protected String sesso;
	protected String codiceF;
	protected String citta;
	
	Uomo(){
		this.nome=null;
		this.cognome=null;
		this.sesso=null;
		this.citta=null;
		this.codiceF=null;
	}
	Uomo(String nome, String cognome, String sesso, String citta){
		this.nome=nome;
		this.cognome=cognome;
		this.sesso=sesso;
		this.citta=citta;
		codiceF = "";
		//this.setCod();
	}
	
	void setN(String nome){
		this.nome = nome;
	}
	void setC(String cognome){
		this.cognome = cognome;
	}
	void setCod(){
		/*Random rnd = new Random();
		char voc = 'x';
		int ctr = 0;
		char tmp = 'a';
		//Imposta nom
		for(int i=0;i<nome.length();i++){
			if(nome.charAt(i)!='a' || nome.charAt(i)!='e' || nome.charAt(i)!='i' || nome.charAt(i)!='o' || nome.charAt(i)!='u'){
				codiceF+=nome.charAt(i);
				ctr++;
			}else{
				voc = nome.charAt(i);
			}
		}
		if(ctr!=3){
			codiceF+=voc;
		}
		codiceF+=" ";
		
		//Imposta cog
		ctr=0;
		for(int i=0;i<cognome.length();i++){
			if(cognome.charAt(i)!='a' || cognome.charAt(i)!='e' || cognome.charAt(i)!='i' || cognome.charAt(i)!='o' || cognome.charAt(i)!='u'){
				codiceF+=cognome.charAt(i);
				ctr++;
			}else{
				voc = cognome.charAt(i);
			}
		}
		if(ctr!=3){
			codiceF+=voc;
		}
		codiceF+=" ";
		
		//Imposta data
		codiceF+=rnd.nextInt(50)+50;
		tmp=(rnd.nextInt(13)+97);
		codiceF+=tmp;
		codiceF+=rnd.nextInt(31)+1;
		codiceF+=" ";
		
		//Imposta secur
		tmp=rnd.nextInt(26)+97;
		codiceF+=tmp;
		codiceF+=rnd.nextInt(9)+1;
		codiceF+=rnd.nextInt(9)+1;
		codiceF+=rnd.nextInt(9)+1;
		tmp=rnd.nextInt(26)+97;
		codiceF+=tmp;*/
	}
	void setCod(String codiceF){
		this.codiceF=codiceF;
	}
	void setS(String sesso){
		this.sesso = sesso;
	}
	void setCit(String citta){
		this.citta = citta;
	}
	String getN(){
		return nome;
	}
	String getC(){
		return cognome;
	}
	String getCod(){
		return codiceF;
	}
	String getS(){
		return sesso;
	}
	String getCit(){
		return citta;
	}
	void stampa(){
		System.out.println("Uomo [ nome=" + nome + ", cognome=" + cognome + ", sesso=" + sesso+ ", citta=" + citta +", annoNascita=" + this.annoNascita()+ "  ]");
	}
	int annoNascita(){
		int tmp=0;
		
		//tmp+=10*Integer.valueOf(valueOf(codiceF.charAt(8)));
		//tmp+=Integer.valueOf(intValue(codiceF.charAt(9)));
		return tmp;
	}
}
class Stagista extends Uomo{
	int numeroPres;
	int numeroId;
	
	Stagista(String nome, String cognome, String sesso, String citta, int numeroPres, int numeroId){
		super( nome,  cognome,  sesso,  citta);
		this.numeroPres = numeroPres;
		this.numeroId = numeroId;
	}
	
	void setPres(int numeroPres){
		this.numeroPres = numeroPres;
	}
	
	void setId(int numeroId){
		this.numeroId=numeroId;
	}
	int getPres(){
		return numeroPres;
	}
	int getId(){
		return numeroId;
	}
	@Override
	void stampa(){
		System.out.println("Uomo [ nome=" + nome + ", cognome=" + cognome + ", sesso=" + sesso+ ", citta=" + citta+ ", annoNascita=" + annoNascita()+ ", presenze=" + numeroPres+ ", identifictivo=" + numeroId+"  ]");
	}
}

