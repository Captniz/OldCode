/**
 * tx
 */
public class tx {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int j2 = 0; j2 < 10; j2++) {
                    for (int j3 = 0; j3 < 10; j3++) {
                        //if all the numbers are different
                        if (i != j && i != j2 && i != j3 && j != j2 && j != j3 && j2 != j3)
                            System.out.println(i + "" + j + "" + j2 + "" + j3);
                    }
                }
            }
        }
    }
}