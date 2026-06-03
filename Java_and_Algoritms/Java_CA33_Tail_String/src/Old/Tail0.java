package Old;
// Name: Niki
// Purpose: CA3 Java Tail program initial version
// What? Enter Tail <number of lines to print> 

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Simple tail program.
// Accepts negative order for normal printing 
public class Tail0
{
	// Method to initialize queue 
    public static Queue<String> loadQueue(int amount)
    {
        Queue<String> words = new LinkedList<>();   // queue holding the last N words
        Scanner scanner = new Scanner(System.in);   // reads from keyboard or redirected file
		
        while (scanner.hasNextLine()) {
            words.add(scanner.nextLine());
            // If amount is less than elements in queue and is more than 0
            if (words.size() > amount && amount > 0) {
            	// get rid of newest in
                words.poll();
            }
        }
        scanner.close();
        return words;
    }

    // Print method to output queue in reverse or normal queue order 
    // Depends on polarity of args[0] aka amount value
    public static void printTail(Queue<String> words, int amount)
    {
    	// if amount more than 0, print full limited queue
    	if (amount > 0){
        while (!words.isEmpty()) {
            System.out.println(words.poll());
        }}
        // Otherwise amount is negative, print in normal queue order
        else {
        	// Turn positive for normal printing
        	amount = -1*amount;
        	// Print amount number of times
        	for(int i = 0; i < amount; i++){
        		System.out.println(words.poll());
        	}
        }
    }
    // Small main
    public static void main(String[] args)
    {
        if (args.length < 1) {
            System.out.println("Usage: java Tail <amount> < inputfile");
            return;
        }
		// Parse int from args string array
        int amount = Integer.parseInt(args[0]);
        //Queue<String> words = loadQueue(amount); 
        printTail(loadQueue(amount), amount);
    } // End of main
}
