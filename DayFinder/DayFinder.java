import java.util.*;

public class DayFinder{
    static String findDay(String date){
        String[] parts = date.split("/");

        if(parts.length != 3){
            System.out.println("Invalid Date Format");
            return null;
        }

        int day = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);
        
        if(!(month >= 1 && month <= 12 && day >= 1 && day <= 31)){
            System.out.println("Invalid Date");
            return null;
        }

        if(month == 1){month = 13; year--;}
        if(month == 2){month = 14; year--;}
        
        int k = year % 100;
        int j = year / 100;
        
        int h = (day + (13*(month+1))/5 + k + k/4 + j/4 + 5*j) % 7;
        
        switch(h){
            case 0: return "SATURDAY";
            case 1: return "SUNDAY";
            case 2: return "MONDAY";
            case 3: return "TUESDAY";
            case 4: return "WEDNESDAY";
            case 5: return "THURSDAY";
            case 6: return "FRIDAY";
            default: return "INVALID INPUT";
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the Date (DD/MM/YYYY): ");
        String date = sc.nextLine().trim();

        String day = findDay(date);
        if(day != null)
            System.out.println("\nThe day is " + day);

        sc.close();
    }
}
