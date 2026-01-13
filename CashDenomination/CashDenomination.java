import java.util.Scanner;

class InvalidAmountException extends Exception {
    public InvalidAmountException(String message) {
        super(message);
        System.out.println(message);
    }
}

public class CashDenomination {

    public static void main(String[] args) {
        int[] notes = {500, 200, 100, 50, 20, 10, 5, 2, 1};

        Scanner sc = new Scanner(System.in);

        int amount = -1;

        do{
            System.out.print("\nEnter amount: ");
            try{
                amount = sc.nextInt();
                if (amount < 0) {
                    throw new InvalidAmountException("Amount cannot be negative.");
                }
            }
            catch (Exception e) {
                System.out.println("Invalid input! Please enter a valid number.");
                sc.nextLine();
                continue;
            }
        }while(amount < 0);

        System.out.println("\nDenominations:\nNote  x  Count");

        for (int note : notes) {
            if (amount >= note) {
                int count = amount / note;
                amount = amount % note;
                System.out.println(note + " x " + count);
            }
        }

        sc.close();
    }
}
