#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

// Вспомогательные структуры и генераторы случайных чисел
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // Генератор случайных чисел

// Возвращает случайное вещественное число из интервала [a, b)
double random_double(double a, double b) {
    uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}

// Возвращает случайное целое число из интервала [a, b)
int random_int(int a, int b) {
    uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

// Расчёт евклидова расстояния между двумя точками
double distance(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

// Сумма расстояний от всех клиентов до ближайших центров
double totalDistance(const vector<pair<double, double>>& clients, const vector<pair<double, double>>& centers) {
    double total = 0.0;
    for (const auto& client : clients) {
        double minDist = numeric_limits<double>::infinity(); // Начальное значение бесконечности
        for (const auto& center : centers) {
            minDist = min(minDist, distance(client, center)); // Минимальное расстояние до ближайшего центра
        }
        total += minDist;
    }
    return total;
}

// Метод имитации отжига для нахождения оптимального расположения центров
vector<pair<double, double>> sa_facility_location(
    const vector<pair<double, double>>& clients,
    int k, double temp, double cooling
) {
    // Инициализация случайных положений центров
    vector<pair<double, double>> centers(k);
    for (int i = 0; i < k; ++i) {
        centers[i] = {random_double(-10, 10), random_double(-10, 10)}; // Случайные координаты
    }

    double current_cost = totalDistance(clients, centers); // Начальная оценка качества решения

    while (temp > 1e-6) {
        // Формируем кандидата: немного сдвигаем случайный центр
        vector<pair<double, double>> new_centers = centers;
        int idx = random_int(0, k - 1); // Индекс случайного центра
        new_centers[idx].first += random_double(-1, 1) * temp; // Небольшое изменение по X
        new_centers[idx].second += random_double(-1, 1) * temp; // Небольшое изменение по Y

        double new_cost = totalDistance(clients, new_centers); // Оценка качества нового кандидата

        // Критерий Метрополиса для принятия нового кандидата
        if (new_cost < current_cost ||
           exp((current_cost - new_cost) / temp) > random_double(0, 1)) {
            // Если новый кандидат лучше или удовлетворяет условию Метрополиса
            centers = new_centers;      // Обновляем центры
            current_cost = new_cost;     // Обновляем оценку качества
        }

        temp *= cooling;                 // Остужаем систему
    }

    return centers;
}

int main() {
    // Ручной ввод данных пользователем
    int n_clients, k_centers;
    double initial_temperature, cooling_factor;

    cout << "Введите количество клиентов: ";
    cin >> n_clients;

    vector<pair<double, double>> clients(n_clients);
    cout << "Введите координаты клиентов (каждая пара 'x y' на отдельной строке):" << endl;
    for (int i = 0; i < n_clients; ++i) {
        cin >> clients[i].first >> clients[i].second;
    }

    cout << "Введите количество центров: ";
    cin >> k_centers;

    cout << "Введите начальную температуру: ";
    cin >> initial_temperature;

    cout << "Введите коэффициент охлаждения: ";
    cin >> cooling_factor;

    // Выполняем алгоритм
    vector<pair<double, double>> optimal_centers =
        sa_facility_location(clients, k_centers, initial_temperature, cooling_factor);

    // Вывод результата
    cout << "Оптимальные центры:" << endl;
    for (const auto& center : optimal_centers) {
        cout << '(' << center.first << ", " << center.second << ')' << endl;
    }

    return 0;
}
// Ввод:
// 5
// 1.0 2.0
// 3.5 4.0
// -2.0 -1.0
// 0.0 0.0
// 5.0 3.0
// 2
// 10.0
// 0.95

// Вывод:
// Оптимальные центры:
// (3.12553, 6.11006)
// (-1.53055, -0.760953)
