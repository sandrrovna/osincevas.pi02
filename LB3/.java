//Бинарная куча
import java.util.PriorityQueue;
public class BinaryHeapExample {
    public static void main(String[] args) {
        // Создание бинарной кучи
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        // Добавление элементов
        heap.offer(10);
        heap.offer(5);
        // Извлечение минимального элемента
        int smallest = heap.poll();
        System.out.println(smallest);  // Выведет 5
    }
}

//Биноминальня куча
import org.apache.commons.collections.Bag;
import org.apache.commons.collections.bag.HashBag;
public class BinomialHeapExample {
    public static void main(String[] args) {
        Bag bag = new HashBag();
        bag.add(10);
        bag.add(5);
        // Далее потребуется дополнительная логика для обработки как биномиальной кучи
    }
}

//Куча Фибоначчи
import com.google.common.collect.MinMaxPriorityQueue;
public class FibonacciHeapExample {
    public static void main(String[] args) {
        MinMaxPriorityQueue<Integer> fheap = MinMaxPriorityQueue.create();
        fheap.add(10);
        fheap.add(5);
        // Требуется дописать дополнительную логику для полной реализации
    }
}

//Хэш-таблица
#include <iostream>
#include <unordered_map>
int main() {
    // Создание хэш-таблицы
    std::unordered_map<std::string, int> hash_table;
    // Добавление пар ключ-значение
    hash_table["apple"] = 10;
    hash_table["banana"] = 5;
    // Получение значения по ключу
    int value = hash_table["apple"];
    std::cout << value << std::endl;  // Выведет 10
    return 0;
}
