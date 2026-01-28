import java.util.Scanner;

class TemperatureConverter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double inputTemp = 0;
        int choice = 0;

        while(true) {
            try {
                System.out.print("""
Enter the following numbers for temperature conversion:
1. Celsius to Fahrenheit
2. Celsius to Kelvin
3. Fahrenheit to Celsius
4. Fahrenheit to Kelvin
5. Kelvin to Celsius
6. Kelvin to Fahrenheit
""");

                System.out.print("Choice: ");
                choice = sc.nextInt();

                System.out.print("Enter the temperature: ");
                inputTemp = sc.nextDouble();

                break;
            }
            catch (Exception e) {
                System.out.println("Invalid input. Please enter numbers only.\n");
                sc.nextLine();
            }
        }

        switch(choice){
            case 1:
                System.out.println(inputTemp + "°C = " + (inputTemp * 9/5 + 32) + "°F");
                break;
            case 2:
                System.out.println(inputTemp + "°C = " + (inputTemp + 273.15) + "K");
                break;
            case 3:
                System.out.println(inputTemp + "°F = " + ((inputTemp - 32) * 5/9) + "°C");
                break;
            case 4:
                System.out.println(inputTemp + "°F = " + ((inputTemp - 32) * 5/9 + 273.15) + "K");
                break;
            case 5:
                System.out.println(inputTemp + "K = " + (inputTemp - 273.15) + "°C");
                break;
            case 6:
                System.out.println(inputTemp + "K = " + ((inputTemp - 273.15) * 9/5 + 32) + "°F");
                break;
            default:
                System.out.println("Invalid choice. Please select a number between 1 and 6");
        }
    }
}