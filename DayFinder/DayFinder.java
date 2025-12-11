import java.util.*;

public class DayFinder{
    static String findDay(String date) throws Exception {
        String[] parts = date.split("/");

        if(parts.length != 3){
            System.out.println("Invalid Date Format");
            return null;
        }

        int day = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);
        
        if(!((month >= 1 && month <= 12) && (day >= 1 && day <= 31))){
            System.out.println("Invalid Date");
            return null;
        }

        if(month == 1){month = 13; year--;}
        if(month == 2){month = 14; year--;}
        
        int k = year%100;
        int j = year/100;
        
        int h = (int)((day + Math.floor(13*(month+1)/5) + k + Math.floor(k/4) + Math.floor(j/4) + 5*j) % 7);
        
        return switch(h){
            case 0 -> "SATURDAY";
            case 1 -> "SUNDAY";
            case 2 -> "MONDAY";
            case 3 -> "TUESDAY";
            case 4 -> "WEDNESDAY";
            case 5 -> "THURSDAY";
            case 6 -> "FRIDAY";
            default -> "INVALID INPUT";
        };
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the Date (DD/MM/YYYY): ");
        String date = sc.nextLine().trim();
        try{
        String day = findDay(date);
        
        if(day != null)
        System.out.println("\nThe day is " + day);
        } catch(Exception e){
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}