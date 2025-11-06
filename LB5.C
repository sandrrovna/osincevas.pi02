#include <iostream>
using namespace std;

// Рекурсивная функция для нахождения суммы цифр числа
int sumOfDigits(int n) {
    // Базовый случай: если число меньше 10, возвращаем само число
    if (n < 10)
        return n;
    
    // Рекурсивный случай: складываем последнюю цифру и сумму остальных цифр
    else
        return (n % 10 + sumOfDigits(n / 10));
}

int main() {
    int number = 12345;
    cout << "Сумма цифр числа " << number << ": " << sumOfDigits(number) << endl;
    return 0;
}

//Сумма цифр числа 12345: 15
