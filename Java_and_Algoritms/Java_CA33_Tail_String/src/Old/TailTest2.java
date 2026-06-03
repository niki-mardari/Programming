package Old;
import org.junit.jupiter.api.Test;
import Tail1;

import static org.junit.jupiter.api.Assertions.*;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Queue;
import java.util.Scanner;

// Excecuted from root dir
// To compile: javac -cp "lib\junit-platform-console-standalone-6.0.3.jar;src" -d bin src\Tail.java src\TailTest2.java
// To run: java -jar lib\junit-platform-console-standalone-6.0.3.jar execute --class-path bin --scan-class-path

public class TailTest2 {

    // Testing parseK method with valid input
    @Test
    public void parseK_validNumber_returnsK() {
        int result = Tail.parseK(new String[]{"3"});
        assertEquals(3, result);
    }

    // Testing parseK method with no input
    @Test
    public void parseK_missingArgument_throwsException() {
        IllegalArgumentException ex =
                assertThrows(IllegalArgumentException.class, () -> Tail.parseK(new String[]{}));

        assertEquals("Usage: java Tail <k> < inputfile", ex.getMessage());
    }

    // Testing parseK method with non-numeric input abc
    @Test
    public void parseK_nonNumeric_throwsException() {
        IllegalArgumentException ex =
                assertThrows(IllegalArgumentException.class, () -> Tail.parseK(new String[]{"abc"}));

        assertEquals(
                "Error: k must be a positive integer.\nUsage: java Tail <k> < inputfile",
                ex.getMessage()
        );
    }

    // Testing parseK method with zero as input
    @Test
    public void parseK_zero_throwsException() {
        IllegalArgumentException ex =
                assertThrows(IllegalArgumentException.class, () -> Tail.parseK(new String[]{"0"}));

        assertEquals("Error: k must be greater than 0.", ex.getMessage());
    }

    // Testing parseK method with negative number as input
    @Test
    public void parseK_negative_throwsException() {
        IllegalArgumentException ex =
                assertThrows(IllegalArgumentException.class, () -> Tail.parseK(new String[]{"-1"}));

        assertEquals("Error: k must be greater than 0.", ex.getMessage());
    }

    // Testing loadTailQueue method with k=1 should return only the last line
    @Test
    public void loadTailQueue_kEquals1_returnsLastLineOnly() throws Exception {

        Scanner scanner = new Scanner(new java.io.File("data/sample.txt"));

        Queue<String> result = Tail.loadTailQueue(scanner, 1);

        assertEquals(1, result.size());
        assertEquals("This is the END", result.poll());

        scanner.close();
    }

    // Testing loadTailQueue method with k=3 should return the last three lines
    @Test
    public void loadTailQueue_kEquals3_returnsLastThreeLines() throws Exception {
        
        Scanner scanner = new Scanner(new java.io.File("data/sample.txt"));

        Queue<String> result = Tail.loadTailQueue(scanner, 3);

        assertEquals(3, result.size());
        assertEquals("LED7 LED7.1 LED7.2 LED7.3 LED7.4 LED7.5 LED7.6 LED7.7 LED7.8 LED7.9", result.poll());
        assertEquals("LED8", result.poll());
        assertEquals("This is the END", result.poll());

        scanner.close();
    }

    // Testing loadTailQueue method with k greater than the number of lines should return all lines
    @Test
    public void loadTailQueue_kGreaterThanInputSize_returnsAllLines() {
        Scanner scanner = new Scanner(
                "A\n" +
                "B\n" +
                "C\n"
        );

        Queue<String> result = Tail.loadTailQueue(scanner, 10);

        assertEquals(3, result.size());
        assertEquals("A", result.poll());
        assertEquals("B", result.poll());
        assertEquals("C", result.poll());

        scanner.close();
    }

    // Testing loadTailQueue method with k=0 should throw an exception
    @Test
    public void runTail_validInput_printsLastLines() {
        Scanner scanner = new Scanner(
                "A\n" +
                "B\n" +
                "C\n" +
                "D\n"
        );

        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        Tail.runTail(2, scanner, out);

        String expected =
                "C" + System.lineSeparator() +
                "D" + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
    }

    // Testing runTail method with k=0 should throw an exception "k must be greater than 0."
    @Test
    public void runTail_invalidK_throwsException() {
        Scanner scanner = new Scanner("A\nB\n");
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        IllegalArgumentException ex =
                assertThrows(IllegalArgumentException.class, () -> Tail.runTail(0, scanner, out));

        assertEquals("k must be greater than 0.", ex.getMessage());

        scanner.close();
        out.close();
    }

    // Testing runTailApp method with invalid number should print "Error: k must be a positive integer." and usage message
    @Test
    public void runTailApp_invalidNumber_printsFriendlyError() {
        Scanner scanner = new Scanner("A\nB\nC\n");
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        Tail.runTailApp(new String[]{"abc"}, scanner, out);

        String expected =
                "Error: k must be a positive integer." + System.lineSeparator() +
                "Usage: java Tail <k> < inputfile" + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
    }

    // Testing runTailApp method with zero as input should print "Error: k must be greater than 0."
    @Test
    public void runTailApp_zero_printsFriendlyError() {
        Scanner scanner = new Scanner("A\nB\nC\n");
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        Tail.runTailApp(new String[]{"0"}, scanner, out);

        String expected = "Error: k must be greater than 0." + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
    }
}