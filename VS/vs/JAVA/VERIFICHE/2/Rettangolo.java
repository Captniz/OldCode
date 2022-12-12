public class Rettangolo{
	int b;
	int h;
	
	Rettangolo(){
		b=1;
		h=1;
	}
	Rettangolo(int base, int alt){
		b=base;
		h=alt;
	};
	public int getPerimetro(){
		return ((b*2)+(h*2));
	}
	public int getArea(){
		return (b*h);
	}
	public void setBase(int base){
			b=base;
	}
	public void setAltezza(int alt){
			h=alt;
	}
}
