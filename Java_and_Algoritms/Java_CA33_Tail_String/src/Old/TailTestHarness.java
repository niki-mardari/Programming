package Old;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class TailTestHarness {

    // Load the last k strings from a Scanner
    public static Queue<String> loadTailQueue(Scanner scanner, int k) {
        Queue<String> words = new LinkedList<>();

        while (scanner.hasNextLine()) {
            words.add(scanner.nextLine());

            if (words.size() > k) {
                words.poll();
            }
        }

        return words;
    }

    // Convert queue contents into one string for easy comparison
    public static String queueToString(Queue<String> words) {
        StringBuilder sb = new StringBuilder();

        for (String word : words) {
            sb.append(word).append(" ");
        }

        return sb.toString().trim();
    }

    // One reusable test method
    public static void runTest(String testName, String filename, int k, String expected) {
        try {
            Scanner scanner = new Scanner(new File(filename));

            Queue<String> resultQueue = loadTailQueue(scanner, k);
            String actual = queueToString(resultQueue);

            scanner.close();

            System.out.println("Test: " + testName);
            System.out.println("Expected: " + expected);
            System.out.println("Actual:   " + actual);

            if (actual.equals(expected)) {
                System.out.println("Result: PASS");
            } else {
                System.out.println("Result: FAIL");
            }

            System.out.println();

        } catch (FileNotFoundException e) {
            System.out.println("Test: " + testName);
            System.out.println("Result: FAIL - File not found: " + filename);
            System.out.println();
        }
    }

    public static void main(String[] args) {
        runTest("sample.txt with k=3", "../data/sample.txt", 3, "LED7 LED7.1 LED7.2 LED7.3 LED7.4 LED7.5 LED7.6 LED7.7 LED7.8 LED7.9 LED8 This is the END");
        runTest("sample.txt with k=5", "../data/sample.txt", 5, "LED5 LED6 LED7 LED7.1 LED7.2 LED7.3 LED7.4 LED7.5 LED7.6 LED7.7 LED7.8 LED7.9 LED8 This is the END");
        runTest("sample.txt with k=1", "../data/sample.txt", 1, "This is the END");
        runTest("sample.txt with k=8", "../data/sample.txt", 8, "LED2 LED3 LED4 LED5 LED6 LED7 LED7.1 LED7.2 LED7.3 LED7.4 LED7.5 LED7.6 LED7.7 LED7.8 LED7.9 LED8 This is the END");
        runTest("sample.txt with k=0", "../data/sample.txt", 0, "");
        runTest("sample.txt with k=-1", "../data/sample.txt", -1, "");
    }
}