class SecondoTardiani{
	public static void main(String args[]){
		int v[] = new int [args.length];
		int sum=0;
		
		if(args.length <=1){
			System.out.print("Inserire almeno due valori.");
			return;
		}
		
		try{
			for(int i=0; i<args.length; i++){
				v[i]=Integer.valueOf(args[i]).intValue();
				sum=sum+v[i];
			}
		}catch(Exception e){
			System.out.print("Inserire solo numeri.");
			return;
		}
		
		for(int i=0; i<args.length; i++){
			System.out.format("%4d",v[i]);
		}
		System.out.print("\nSomma: " + sum);
		return;
	}
}