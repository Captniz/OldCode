class TreNumeriShell{
	public static void main(String[] args){
		int a=0;
		int b=0;
		int c=0;
		int media=0;
		try{
			a=Integer.valueOf(args[0]).intValue();
			b=Integer.valueOf(args[1]).intValue();
			c=Integer.valueOf(args[2]).intValue();
		}catch(Exception e){
			System.out.println("Errore caricamento");
		}
		media=a+b+c;
		media=media/3;
		
		System.out.println(media);
	}
}