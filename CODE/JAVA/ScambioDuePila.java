//230331_tardiani_simone

//Data una pila P1 inverti gli elementi a due a due (Es: [1 2 3 4 5] -> [2 1 4 3 5])

import java.util.Stack;

class ScambioDuePila {
	public static void main(String args[]) {
		Stack<Integer> P1 = new Stack<Integer>();
		P1.push(1);
		P1.push(2);
		P1.push(3);
		P1.push(4);
		P1.push(5);

		System.out.println(P1);
		P1 = reverseCoppia(P1);
		System.out.println(P1);
	}

	public static Stack<Integer> reverseCoppia(Stack<Integer> P) {
		Stack<Integer> tmp = new Stack<Integer>();
		int tmpNum = 0;

		while (!P.isEmpty()) {
			tmp.push(P.pop());
		}

		while (!tmp.isEmpty()) {
			tmpNum = tmp.pop();
			if (!tmp.isEmpty()) {
				P.push(tmp.pop());
			}
			P.push(tmpNum);
		}

		return P;
	}
}
