//230331_tardiani_simone

//Data una coda C1 inverti gli elementi a due a due (Es: [1 2 3 4 5] -> [2 1 4 3 5])

import java.util.LinkedList;
import java.util.Queue;

class ScambioDueColonna {
	public static void main(String args[]) {
		Queue<Integer> C1 = new LinkedList<Integer>();
		C1.add(1);
		C1.add(2);
		C1.add(3);
		C1.add(4);
		C1.add(5);

		System.out.println(C1);
		C1 = reverseCoppia(C1);
		System.out.println(C1);
	}

	public static Queue<Integer> reverseCoppia(Queue<Integer> C) {
		Queue<Integer> tmp = new LinkedList<Integer>();
		int tmpNum = 0;

		while (!C.isEmpty()) {
			tmpNum = C.remove();
			if (!C.isEmpty()) {
				tmp.add(C.remove());
			}
			tmp.add(tmpNum);
		}

		return tmp;
	}
}
