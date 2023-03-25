public class Media {
    private int array [];
    
    public Media(int a[]){
        this.array = a; 
    }

    public void printArray(){
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]+ " ");
        }
        System.out.println();
        return;
    }

    public void printArray(float array[]){
        for (int i = 0; i < array.length; i++) {
                System.out.print(array[i] + " ");
        }
        System.out.println();
        return;
    }

    public float[] getDati(){
        int max = array[0];
        int min = array[0];
        float med = 0;
        float dati[] = new float [3];

        for (int i = 0; i < array.length; i++) {
            if(array[i]>max){
                max = array[i];
            }
            if(array[i]<min){
                min = array[i];
            }
            med+=array[i];
        }
        med = med/array.length;

        dati[0]= (float)max;
        dati[1]= (float)min;
        dati[2]= med;

        return dati;
    }

    public static void main(String[] args) {
        int numeri [] = {1,2,5,1,2,7,8,2,4,5,7,1};
        Media m = new Media(numeri); 
        m.printArray();
        m.printArray(m.getDati());
    }
}
