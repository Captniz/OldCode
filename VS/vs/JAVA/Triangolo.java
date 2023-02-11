
public class Triangolo{
	protected int lati[];
	
	Triangolo(int lat1,int lat2,int lat3){
		lati = new int[3];
		lati[0]=lat1;
		lati[1]=lat2;
		lati[2]=lat3;
	}
	
	public static void main(String args[]){
		Triangolo a = new Triangolo(10,20,30);
		a.stampa();
		Isoscele b = new Isoscele(10,20,30);
		b.stampa();
		Isoscele c = new Isoscele(10,10,30);
		c.stampa();
	}
	
	boolean isTriangolo(){
		int a=lati[0];
		int b=lati[1];
		int c=lati[2];
		if((a<(b+c))&&(c<(b+a))&&(b<(a+c))){
			return true;
		}
		return false;
	}
	int perimetro(){
		int p=0;
		for(int i=0;i<3;i++){
			p+=lati[i];
		}
		return p;
	}
	void stampa(){
		for(int i=0;i<3;i++){
			System.out.println("Lato " + (i+1) + ":" + lati[i]);
		}
		System.out.println("Perimetro:"+ this.perimetro());
	}
}
class Isoscele extends Triangolo{
	Isoscele(int lat1,int lat2,int lat3){
		super(lat1,lat2,lat3);
		if((lat1==lat2&&lat1!=lat3)&&(lat3==lat2&&lat1!=lat3)&&(lat1==lat3&&lat2!=lat3)){
			return;
		}
		for(int i=0;i<3;i++){
			lati[i]=0;
		}
		return;
	}
}

class Equilatero extends Triangolo{
	Equilatero(int lat1,int lat2,int lat3){
		super(lat1,lat2,lat3);
		if(lat1==lat2&&lat2==lat3&&lat3==lat1){
			return;
		}
		for(int i=0;i<3;i++){
			lati[i]=0;
		}
		return;
	}
}
