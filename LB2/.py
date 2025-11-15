#Мультисписок
groups = [['Маша', 'Петя'], ['Таня', 'Ваня'], ['Оля', 'Коля']]

#Очередь
from queue import Queue
q = Queue()
q.put(11)
q.put(12)
q.put(13)

#Дек
from collections import deque
tasks = deque()
tasks.append('хорошо')
tasks.append('плохо')

#Приоритетная очередь
from queue import PriorityQueue
q = PriorityQueue()
q.put((1, 'high-priority item'))
q.put((5, 'mid-priority item'))
q.put((10, 'low-priority item'))
