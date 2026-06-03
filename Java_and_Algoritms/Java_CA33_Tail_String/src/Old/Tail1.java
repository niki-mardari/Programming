package Old;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*
 * Tail.java
 * Prints the last k strings from standard input using the Queue interface.
 *
 * Example:
 *     java Tail 5 < tinyW.txt
 *
 * N. Mardari - Revision 2 version
 */
public class Tail1 {

    /*
     * Reads all strings from standard input and keeps only the last k.
     * Arg 1: k, number of strings to keep
     * Returns: queue containing the last k strings
     */
    public static Queue<String> loadTailQueue(int k) {
        Queue<String> words = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            words.add(scanner.nextLine());

            if (words.size() > k) {
                words.poll();   // remove oldest string
            }
        }

        scanner.close();
        return words;
    }

    /*
     * Prints all strings stored in the queue in queue order.
     * Arg 1: queue of strings to print
     */
    public static void printQueue(Queue<String> words) {
        while (!words.isEmpty()) {
            System.out.println(words.poll());
        }
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Tail <k> < inputfile");
            return;
        }

        int k;

        try {
            k = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            System.out.println("Error: k must be a positive integer.");
            System.out.println("Usage: java Tail <k> < inputfile");
            return;
        }

        if (k <= 0) {
            System.out.println("Error: k must be greater than 0.");
            return;
        }

        Queue<String> words = loadTailQueue(k);
        printQueue(words);
    }
}

// TODO: Make Tail one function callable in main 