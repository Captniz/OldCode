public class ScambiMaxMin {
    public static void main(String[] args) {
        /*Dato un array caricato contestualmente di DIM 8 scambiare max e min*/
        int posizioneMin,posizioneMax,tmp;
        int v[] = {1,5,3,7,9,3,0,2};
        posizioneMax = 0;
        posizioneMin = 0;
        tmp = 0;

        System.out.println("Vettore originale");
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }

        for (int i = 1; i < 8; i++) {
            if (v[i]>v[posizioneMax]) {
                posizioneMax=i;
            }
            if (v[i]<v[posizioneMin]) {
                posizioneMin=i;
            }
        }
        tmp=v[posizioneMin];
        v[posizioneMin]=v[posizioneMax];
        v[posizioneMax]=tmp;

        System.out.println("\n\nVettore scambiato");
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }
    }
}