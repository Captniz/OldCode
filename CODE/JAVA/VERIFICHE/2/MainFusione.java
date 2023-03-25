public class MainFusione{	
	public static void main(String[] args){
		Fusione f = new Fusione();
		int v1[] = {1,1,3,5,7,6,9};
		int v2[] = {2,3,3,3,7};
		int v3[] = new int [v1.length + v2.length];
		
		f.sort(v1);
		f.sort(v2);
		f.merge(v1,v2,v3);
		f.printA(v1);
		System.out.print('\n');
		f.printA(v2);
		System.out.print('\n');
		f.printA(v3);
	}
}
