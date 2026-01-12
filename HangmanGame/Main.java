import java.util.*;
import java.io.*;

public class Main{
    static int count = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("words.txt"));
        
        String line;
        while ((line = br.readLine()) != null) {
            count++;
        }

        br.close();

        Hangman hangman = new Hangman();
        int c = -1;

        Scanner sc = new Scanner(System.in);

        do{
            System.out.print("Enter the following numbers for\n1. New Game\n2. Stats\n3. Exit\nYour choice: ");
            c = sc.nextInt();
            sc.nextLine();

            switch(c){
                case 1:
                    String word = hangman.getWord(count);
                    hangman.totalGames++;
                    hangman.playGame(word);
                    break;
                case 2:
                    hangman.showStats();
                    break;
                case 3:
                    hangman.showStats();
                    System.out.println("\nExiting the game...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("\nInvalid choice. Please try again.");
                    break;
            }
        } while(c != 3);

        sc.close();
    }
}