import java.util.Scanner;
public class MainContoCorrente{
	public static void main(String[] args){
		boolean flag=true;
		String c="";
		int s=0;
		ContoCorrente con= new ContoCorrente();
		Scanner scn = new Scanner(System.in);
		
		while(flag==true){
			scn = new Scanner(System.in);
			System.out.print("\n\n\nv-versamento\np-prelievo\nl-lista movimenti\ns-saldo\nx-exit\nOpt:");
			c=scn.nextLine();
			
			if(c.charAt(0)=='x'){
				flag=false;
				scn.close();
			}else if(c.charAt(0)=='v'){
				do{
				System.out.print("\nSoldi:");
				s=scn.nextInt();
				}while(s<0);
				con.versa(s);
			}else if(c.charAt(0)=='l'){
				con.lista();
			}else if(c.charAt(0)=='s'){
				System.out.print(con.getSaldo());
			}else if(c.charAt(0)=='p'){
				do{
				System.out.print("\nSoldi:");
				s=scn.nextInt();
				}while(s<0);
				con.preleva(s);
			}else{
				System.out.println("Opzione non valida");
			}
		}
	}
}
