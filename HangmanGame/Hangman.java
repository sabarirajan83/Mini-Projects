import java.util.*;
import java.io.*;

class Hangman {
    static int totalGames = 0;
    static int totalWins = 0;

    public String getWord(int index) throws Exception {
        Random rand = new Random();
        int target = rand.nextInt(index);

        BufferedReader br = new BufferedReader(new FileReader("words.txt"));
        for (int i = 0; i < target; i++) {
            br.readLine();
        }

        String word = br.readLine();
        br.close();
        
        return word;
    }

    public void playGame(String word) {
        Scanner sc = new Scanner(System.in);
        Set<Character> guessedLetters = new HashSet<>();
        int attemptsLeft = 7;
        char[] displayWord = new char[word.length()];
        Arrays.fill(displayWord, '_');

        while (attemptsLeft > 0) {
            System.out.println("\nWord: " + String.valueOf(displayWord));
            System.out.println("Attempts left: " + attemptsLeft);
            System.out.print("Guess a letter: ");
            char guess = sc.nextLine().charAt(0);

            if (guessedLetters.contains(guess)) {
                System.out.println("You already guessed that letter. Try again.");
                continue;
            }

            guessedLetters.add(guess);

            if (word.indexOf(guess) >= 0) {
                for (int i = 0; i < word.length(); i++) {
                    if(word.charAt(i) == guess) {
                        displayWord[i] = guess;
                    }
                }
                if(String.valueOf(displayWord).equals(word)) {
                    System.out.println("Congratulations! You've guessed the word: " + word);
                    totalWins++;
                    return;
                }
            } 
            else {
                attemptsLeft--;
                System.out.println("Wrong guess!");
            }
        }

        System.out.println("Game over! The word was: " + word);
    }

    public void showStats() {
        System.out.println("Showing game statistics...");
        System.out.println("Total Games Played: " + totalGames);
        System.out.println("Total Wins: " + totalWins);
        System.out.printf("Win Rate: %.2f%%\n", (float)totalWins / totalGames * 100 + "\n");
    }
}