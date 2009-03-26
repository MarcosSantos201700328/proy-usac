/**
 * Factorial.java -
 *   A recursive program to calculate the factorial
 *   of a number.
 *
 *   n! = n * (n-1) * (n-2) * ... * 1
 *
 *   A recursive definition of factorial is:
 *
 *   n! = 1          if n <= 1
 *      = n * (n-1)! if n > 2
 */
public class Factorial {
    public static void main () {

	int theNum, theFact;

	System.out.println("This program computes the factorial " +
			   "of a number.");
	System.out.print("Enter a number: ");
	theNum=Console.in.readInt();

	theFact = fact(theNum);

	System.out.println(theNum + "! = " + theFact + ".");
    }

    /**
     * Calculate the factorial of n.
     *
     * @param n the number to calculate the factorial of.
     * @return n! - the factorial of n.
     */
    static int fact(int n) {

	// Base Case:
	//    If n <= 1 then n! = 1.
	if (n <= 1) {
	    return 1;
	}
	// Recursive Case:
	//    If n > 1 then n! = n * (n-1)!
	else {
	    return (n * fact(n - 1));
	}
    }
}
