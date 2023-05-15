public class Main {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        bt.insertFile("numeri.txt");
        System.out.println("Albero originale:");
        bt.print();
        System.out.println();
        System.out.println("sommaFoglie: " + bt.sommaFoglie());
        System.out.println("sinistraInside: " + bt.sinistraInside());
        System.out.println("alberoDue: " + bt.alberoDue());
        System.out.println("Albero con foglie di sinistra cancellate:");
        System.out.println();
        bt.cancellaFoglieSinistra();
        bt.print();
    }
}
