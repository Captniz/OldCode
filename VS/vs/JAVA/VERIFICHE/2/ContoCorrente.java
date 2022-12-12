public class ContoCorrente{
	int saldo;
	int list[];
	ContoCorrente(){
		saldo=0;
		list = new int [5];
	}
	public void versa(int s){
		saldo+=s;
		this.add(s);
	}
	public void preleva(int s){
		saldo-=s;
		this.add((-1*s));
	}
	public int getSaldo(){
		return saldo;
	}
	public void lista(){
		for(int i=(list.length-1);i>=0;i--){
			if(list[i]==0){
			}else if (list[i]>0){
				System.out.println("versamento:"+ list[i]);
			}else{
				System.out.println("prelievo:"+ list[i]);
			}
		}
	}
	private void add(int s){
		for(int i=(list.length-2);i>=0;i--){
			list[(i+1)]=list[i];
		}
		list[0]=s;
	}
}
