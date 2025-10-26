#include <iostream> // Подключаем библиотеку ввода-вывода

// Функция для вывода массива на экран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) { // Проходим циклом по каждому элементу массива
        std::cout << arr[i] << " ";   // Выводим каждый элемент на экран
    }
    std::cout << "\n";                // Перевод строки после вывода всех элементов
}

// Основная функция сортировки выбором
void selectionSort(int arr[], int n) {
    int minIndex;                     // Переменная для хранения индекса минимального элемента
    
    // Внешний цикл проходит по массиву слева направо
    for (int i = 0; i < n - 1; ++i) { // От первого элемента до предпоследнего включительно
        
        // Предполагаем, что первый элемент текущего несортированного участка является минимальным
        minIndex = i;
        
        // Внутренний цикл ищет минимальный элемент среди оставшихся неотсортированных элементов
        for (int j = i + 1; j < n; ++j) { // Просматриваем элементы справа от текущей позиции i
            if (arr[j] < arr[minIndex]) { // Если найден меньший элемент, обновляем индекс минимума
                minIndex = j;
            }
        }
        
        // Меняем местами текущий элемент с найденным минимумом
        if (minIndex != i) {           // Проверяем, нужен ли обмен
            std::swap(arr[i], arr[minIndex]); // Используем стандартную функцию swap для перестановки
        }
    }
}

// Главная функция программы
int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Исходный массив для сортировки
    int n = sizeof(arr)/sizeof(arr[0]); // Вычисляем количество элементов в массиве
    
    std::cout << "Исходный массив:\n";
    printArray(arr, n);               // Вывод исходного массива
    
    selectionSort(arr, n);            // Сортируем массив методом выбора
    
    std::cout << "Отсортированный массив:\n";
    printArray(arr, n);               // Вывод отсортированного массива
    
    return 0;                         // Завершаем программу успешно
}

//Исходный массив: [64, 25, 12, 22, 11]
//Отсортированный массив: [11, 12, 22, 25, 64]

#include <iostream>
using namespace std;

// Вспомогательная функция для объединения двух отсортированных частей массива
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;          // Размер левой половины
    int n2 = right - mid;             // Размер правой половины

    // Создание временных массивов для левого и правого отрезков
    int L[n1], R[n2];

    // Копирование данных в временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];          // Левая половина
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];      // Правая половина

    // Слияние двух половинок в одном массиве
    int i = 0, j = 0, k = left;       // Индексы для лев., прав. и результирующего массивов
    while (i < n1 && j < n2) {        // Пока обе части содержат элементы
        if (L[i] <= R[j]) {            // Если левый элемент меньше либо равен правому
            arr[k++] = L[i++];         // Добавляем левый элемент и увеличиваем счётчик
        } else {
            arr[k++] = R[j++];         // Иначе добавляем правый элемент
        }
    }

    // Остаточные элементы в левом массиве
    while (i < n1)
        arr[k++] = L[i++];

    // Остаточные элементы в правом массиве
    while (j < n2)
        arr[k++] = R[j++];
}

// Рекурсивная функция для разделения массива и последующей сортировки
void mergeSort(int arr[], int left, int right) {
    if (left < right) {                        // Базовый случай рекурсии
        int mid = left + (right - left) / 2;  // Средний индекс для деления пополам
        mergeSort(arr, left, mid);             // Сортировка левой половины
        mergeSort(arr, mid + 1, right);        // Сортировка правой половины
        merge(arr, left, mid, right);          // Объединение отсортированных половин
    }
}

// Функция для вывода массива
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Главная функция
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is\n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is\n";
    printArray(arr, arr_size);

    return 0;
}

//Исходный массив: [12, 11, 13, 5, 6, 7]
//Отсортированный массив: [5, 6, 7, 11, 12, 13]

#include <iostream>
using namespace std;

// Функция для построения максимальной кучи (heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;              // Предполагается, что текущий элемент — наибольший
    int left = 2 * i + 1;         // Левый дочерний элемент
    int right = 2 * i + 2;        // Правый дочерний элемент

    // Если левый дочерний элемент больше текущего наибольшего
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент изменился, меняем местами и повторяем heapify
    if (largest != i) {
        swap(arr[i], arr[largest]); // Меняем местами
        heapify(arr, n, largest);   // Рекурсивно восстанавливаем кучу
    }
}

// Основная функция пирамидальной сортировки
void heapSort(int arr[], int n) {
    // Превращаем массив в максимальную кучу (max-heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Меняем местами корень (наибольший элемент) с последним элементом
        heapify(arr, i, 0);   // Восстанавливаем кучу для уменьшенной части массива
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
}

// Главная функция
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}

//Исходный массив: [64, 34, 25, 12, 22, 11, 90]
//Отсортированный массив: [11, 12, 22, 25, 34, 64, 90]

#include <iostream>
using namespace std;

// Функция бинарного поиска
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {                            // Пока границы не пересеклись
        int mid = low + (high - low) / 2;            // Вычисление середины диапазона

        // Если найден элемент, возвращаем его индекс
        if (arr[mid] == target) {
            return mid;
        }
        // Если цель меньше центрального элемента, сужаем диапазон слева
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        // Если цель больше центрального элемента, сужаем диапазон справа
        else {
            low = mid + 1;
        }
    }
    // Если элемент не найден, возвращаем -1
    return -1;
}

// Главная функция
int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};  // Упорядоченный массив
    int n = sizeof(arr) / sizeof(arr[0]);               // Длина массива
    int target = 55;                                   // Цель поиска

    // Вызов функции бинарного поиска
    int result = binarySearch(arr, 0, n - 1, target);

    // Вывод результата
    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result << "." << endl;
    } else {
        cout << "Элемент " << target << " не найден." << endl;
    }

    return 0;
}

//Элемент 55 найден на позиции 4.

#include <iostream>
using namespace std;

// Функция интерполирующего поиска
int interpolateSearch(int arr[], int low, int high, int target) {
    while ((low <= high) && (target >= arr[low]) && (target <= arr[high])) {
        // Формула для оценки приблизительного положения искомого элемента
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        // Если элемент найден, возвращаем его индекс
        if (arr[pos] == target) {
            return pos;
        }

        // Если элемент меньше, то уменьшаем верхнюю границу
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // Если элемент больше, то увеличиваем нижнюю границу
        else {
            high = pos - 1;
        }
    }
    // Если элемент не найден, возвращаем -1
    return -1;
}

// Главная функция
int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);  // Размер массива
    int target = 22;                      // Целевой элемент для поиска

    // Вызов функции интерполирующего поиска
    int result = interpolateSearch(arr, 0, n - 1, target);

    // Вывод результата
    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result << "." << endl;
    } else {
        cout << "Элемент " << target << " не найден." << endl;
    }

    return 0;
}

//Элемент 22 найден на позиции 8.

#include <iostream>
using namespace std;

// Генерируем числа Фибоначчи до необходимого предела
int fibGen(int n) {
    if (n <= 1) return n;
    return fibGen(n - 1) + fibGen(n - 2);
}

// Функция поиска по Фибоначчи
int fibonacciSearch(int arr[], int target, int n) {
    // Генерируем числа Фибоначчи, подходящие для поиска
    int fibMm2 = 0;   // F(m-2)
    int fibMm1 = 1;   // F(m-1)
    int fibM = fibMm2 + fibMm1;  // F(m)

    // Ищем такое m, чтобы F(m) стало больше или равно числу элементов
    while (fibM < n) {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    // Индекс начала подмассива
    int offset = -1;

    // Начинаем поиск
    while (fibM > 1) {
        // Индекс точки проверки
        int i = min(offset + fibMm2, n - 1);

        // Если элемент меньше искомого, пропускаем левую часть
        if (arr[i] < target) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        // Если элемент больше искомого, пропускаем правую часть
        else if (arr[i] > target) {
            fibM = fibMm2;
            fibMm1 -= fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        // Если элемент найден, возвращаем его индекс
        else {
            return i;
        }
    }

    // Если элемент равен последнему элементу массива
    if (fibMm1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    // Если элемент не найден
    return -1;
}

// Главная функция
int main() {
    int arr[] = {10, 22, 33, 45, 89, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);  // Размер массива
    int target = 89;                      // Искусственный элемент для поиска

    // Вызов функции поиска по Фибоначчи
    int result = fibonacciSearch(arr, target, n);

    // Вывод результата
    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result << "." << endl;
    } else {
        cout << "Элемент " << target << " не найден." << endl;
    }

    return 0;
}

//Элемент 89 найден на позиции 4.
