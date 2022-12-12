public class MainRettangolo{

	public static void main(String[] args){

		Rettangolo r1= new Rettangolo();

		Rettangolo r2 = new Rettangolo(5, 3);

		System.out.println("Perimetro: " + r1.getPerimetro());

		System.out.println("Area: " + r1.getArea());

		System.out.println("Perimetro: " + r2.getPerimetro());

		System.out.println("Area: " + r2.getArea());

		r2.setBase(7);

		r2.setAltezza(5);

		System.out.println("Perimetro: " + r2.getPerimetro());

		System.out.println("Area: " + r2.getArea());

	}
}
