#Бинарная куча
import heapq
# Создание бинарной кучи
heap = []
# Добавление элементов
heapq.heappush(heap, 10)
heapq.heappush(heap, 5)
# Извлечение минимального элемента
smallest = heapq.heappop(heap)
print(smallest)  # Выведет 5

#Биноминальня куча
from binomial_heap import BinomialHeap
# Создание биномиальной кучи
bh = BinomialHeap()
# Добавление элементов
bh.insert(10)
bh.insert(5)
# Поиск минимального элемента
min_element = bh.find_min()
print(min_element)  # Выведет 5

#Куча Фибоначчи
from fibonacci_heap_mod import FibonacciHeap
# Создание кучи Фибоначчи
fh = FibonacciHeap()
# Добавление элементов
fh.insert(10)
fh.insert(5)
# Поиск минимального элемента
min_element = fh.find_min().key
print(min_element)  # Выведет 5

#Хэш-таблица
# Создание хэш-таблицы
hash_table = {}
# Добавление пары ключ-значение
hash_table['apple'] = 10
hash_table['banana'] = 5
# Получение значения по ключу
value = hash_table['apple']
print(value)  # Выведет 10
