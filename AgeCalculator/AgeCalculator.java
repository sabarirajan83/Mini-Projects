// AgeCalculator

import java.time.LocalDate;
import java.time.Period;
import java.util.Scanner;

public class AgeCalculator {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter your Date Of Birth  (DD-MM-YYYY): ");
        String date = sc.nextLine();

        String[] parts = date.split("-");

        int day = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);

        LocalDate birthDate = LocalDate.of(year, month, day);
        LocalDate currentDate = LocalDate.now();
        
        if(birthDate.isAfter(currentDate)){
            System.out.println("Invalid Date of Birth");
            return;
        }

        Period age = Period.between(birthDate, currentDate);
        System.out.println("\nYour age: " + age.getYears() + " years, " + age.getMonths() + " months, " + age.getDays() + " days");

        sc.close();
    }
}