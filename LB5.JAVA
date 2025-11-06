public class Main {

    public static void main(String[] args) {
        int number = 12345;
        System.out.println("Сумма цифр числа " + number + " равна " + sumOfDigits(number));
    }

    // Рекурсивная функция для вычисления суммы цифр числа
    public static int sumOfDigits(int n) {
        // Базовый случай: если число меньше 10, вернуть само число
        if (n < 10) {
            return n;
        }
        // Рекурсивный случай: сумма последней цифры и результата рекурсивного вызова
        return (n % 10) + sumOfDigits(n / 10); 
    }
}
//Сумма цифр числа 12345 равна 15
