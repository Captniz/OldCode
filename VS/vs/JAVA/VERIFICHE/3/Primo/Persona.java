//Primo.java
import java.util.*;
public class Persona{
	protected String nome;
	protected String cognome;
	protected String codiceF;
	
	Persona(String nome, String cognome, int id){
		this.nome=nome;
		this.cognome=cognome;
		codiceF = "CF"+id;
	}
	
	void setN(String nome){
		this.nome = nome;
	}
	void setC(String cognome){
		this.cognome = cognome;
	}
	void setCod(int id){
		codiceF="CF"+id;
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
	void stampa(){
		System.out.println("Persona [ nome=" + nome + ", cognome=" + cognome + ", codiceFiscale=" + codiceF+ " ]");
	}
}
class Studente extends Persona{
	private int mat;
	private String uni;
	
	Studente(String nome, String cognome, int id,int mat, String uni){
		super(nome,cognome,id);
		this.mat = mat;
		this.uni = uni;
	}
	void setUni(String uni){
		this.uni = uni;
	}
	String getUni(){
		return uni;
	}
	void setMat(int mat){
		this.mat=mat;
	}
	int getMat(){
		return mat;
	}	
	@Override
	void stampa(){
		System.out.println("Studente [ nome=" + nome + ", cognome=" + cognome + ", codiceFiscale=" + codiceF+ ", universita=" + uni + ", matricola=" + mat +" ]");
	}	
}
class Docente extends Persona{
	private int sal;
	private String mater;
	
	Docente(String nome, String cognome, int id,int sal, String mater){
		super(nome,cognome,id);
		this.sal = sal;
		this.mater = mater;
	}
	void setMater(String mater){
		this.mater = mater;
	}
	String getMater(){
		return mater;
	}
	void setSal(int sal){
		this.sal=sal;
	}
	int getSal(){
		return sal;
	}	
	@Override
	void stampa(){
		System.out.println("Docente [ nome=" + nome + ", cognome=" + cognome + ", codiceFiscale=" + codiceF+ ", materia=" + mater + ", salario=" + sal +" ]");
	}	
}
