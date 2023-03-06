//Primo.java
import java.util.*;
public class MainPersona{
	public static void main(String args[]){
		int i=0;
		Persona a[] = new Persona[3];
		Studente b[] = new Studente[3];
		Docente c[] = new Docente[3];
		
		a[0] = new Persona("Mario","Rossi",++i);
		a[1] = new Persona("Filippo","Neri",++i);
		a[2] = new Persona("Marco","Bianchi",++i);
		
		b[0] = new Studente("Mario","Rossi",++i,10,"Bologna");
		b[1] = new Studente("Filippo","Neri",++i,11,"Milano");
		b[2] = new Studente("Marco","Bianchi",++i,12,"Roma");
		
		c[0] = new Docente("Mario","Rossi",++i,1000,"Matematica");
		c[1] = new Docente("Filippo","Neri",++i,1002,"Scienze");
		c[2] = new Docente("Marco","Bianchi",++i,1210,"Storia");
		
		for(i=0;i<3;i++){
			a[i].stampa();
		}
		for(i=0;i<3;i++){
			b[i].stampa();
		}
		for(i=0;i<3;i++){
			c[i].stampa();
		}
	}
}
