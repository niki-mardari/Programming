    import org.junit.jupiter.api.Test;
    import static org.junit.jupiter.api.Assertions.*;
    import java.io.ByteArrayOutputStream;
    import java.io.PrintStream;
    import java.util.Queue;
    import java.util.Scanner;

    /*
    Tested File used: tinyTale.txt

    it was the best of times it was the worst of times
    it was the age of wisdom it was the age of foolishness
    it was the epoch of belief it was the epoch of incredulity
    it was the season of light it was the season of darkness
    it was the spring of hope it was the winter of despair

    */ 

    public class TailTest {

        // Test parseK when k is a non numeric string, the output should be an error message
        @Test
        public void parseK_nonNumeric_throwsException() {
            IllegalArgumentException e = assertThrows(IllegalArgumentException.class, () -> Tail.parseK(new String[]{"abc"}));
            assertEquals("Error: k must be a positive integer.\nUsage: java Tail <k> < inputfile", e.getMessage());
        }

        // Test loadTailQueue when k = 1 the output is the last string of the input
        @Test
        public void loadTailQueue_kEquals1_returnsLastString() throws Exception {
            Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
            Queue<String> result = Tail.loadTailQueue(scanner, 1);

            assertEquals(1, result.size());
            assertEquals("despair", result.poll());

            scanner.close();
        }

        // Test loadTailQueue when k = 3 the output is the last three strings of the input
        @Test
        public void loadTailQueue_kEquals3_returnsLastThreeStrings() throws Exception {
            Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
            Queue<String> result = Tail.loadTailQueue(scanner, 3);

            assertEquals(3, result.size());
            assertEquals("winter", result.poll());
            assertEquals("of", result.poll());
            assertEquals("despair", result.poll());

            scanner.close();
        }

        // Test loadTailQueue when k is greater than the number of strings in the input, the output should be all strings
        @Test
        public void loadTailQueue_kGreaterThanInputSize_returnsAllStrings() throws Exception {
            Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
            Queue<String> result = Tail.loadTailQueue(scanner, 100);

            assertEquals(60, result.size());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("best", result.poll());
            assertEquals("of", result.poll());
            assertEquals("times", result.poll());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("worst", result.poll());
            assertEquals("of", result.poll());
            assertEquals("times", result.poll());

            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("age", result.poll());
            assertEquals("of", result.poll());
            assertEquals("wisdom", result.poll());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("age", result.poll());
            assertEquals("of", result.poll());
            assertEquals("foolishness", result.poll());

            assertEquals("it", result.poll());
            assertEquals("was", result.poll()); 
            assertEquals("the", result.poll());
            assertEquals("epoch", result.poll());
            assertEquals("of", result.poll());
            assertEquals("belief", result.poll());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("epoch", result.poll());
            assertEquals("of", result.poll());
            assertEquals("incredulity", result.poll());

            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("season", result.poll());
            assertEquals("of", result.poll());
            assertEquals("light", result.poll());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("season", result.poll());
            assertEquals("of", result.poll());
            assertEquals("darkness", result.poll());

            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("spring", result.poll());
            assertEquals("of", result.poll());
            assertEquals("hope", result.poll());
            assertEquals("it", result.poll());
            assertEquals("was", result.poll());
            assertEquals("the", result.poll());
            assertEquals("winter", result.poll());
            assertEquals("of", result.poll());
            assertEquals("despair", result.poll());

            scanner.close();
        }

        // Test runTail when k = 2 the output should be the last two strings of the input
        @Test
        public void runTail_kEquals2_printsLastTwoStrings() throws Exception{
            Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
            ByteArrayOutputStream outContent = new ByteArrayOutputStream();
            PrintStream out = new PrintStream(outContent);

            Tail.runTail(2, scanner, out);

            String expected = "of" + System.lineSeparator() + "despair" + System.lineSeparator();

            assertEquals(expected, outContent.toString());

            scanner.close();
            out.close();
        }

        // Test runTailApp when k = 5 the output should be the last five strings of the input
        @Test 
        public void runTailApp_kEquals5_printsLastFiveStrings() throws Exception {
            Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
            ByteArrayOutputStream outContent = new ByteArrayOutputStream();
            PrintStream out = new PrintStream(outContent);

            String[] args = {"5"};
            Tail.runTailApp(args, scanner, out);

            String expected =
                    "was" + System.lineSeparator() +
                    "the" + System.lineSeparator() +
                    "winter" + System.lineSeparator() +
                    "of" + System.lineSeparator() +
                    "despair" + System.lineSeparator();

            assertEquals(expected, outContent.toString());

            scanner.close();
            out.close();
        }

        // Test runTailApp when k = 0 the output should be an error message
        @Test
        public void runTailApp_zero_printsErrorMessage() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        String[] args = {"0"};
        Tail.runTailApp(args, scanner, out);

        String expected = "Error: k must be greater than 0." + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
        }

        @Test
        public void runTailApp_negative_printsErrorMessage() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        String[] args = {"-1"};
        Tail.runTailApp(args, scanner, out);

        String expected = "Error: k must be greater than 0." + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
        }

    }
    // Excecuted from root dir
    // To compile: javac -cp "lib\junit-platform-console-standalone-6.0.3.jar;src" -d bin src\Tail.java src\TailTest.java
    // To run: java -jar lib\junit-platform-console-standalone-6.0.3.jar execute --class-path bin --scan-class-path
