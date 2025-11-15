//Мультисписок
struct Node {
    int data;
    Node *prev;
    Node *next;
};

//Очередь
std::queue<std::string> queue;
queue.push('завтрак'); 
queue.push('обед'); 
queue.push('ужин');

//Дек
std::deque<int> d = {11, 12, 13};

//Приоритетная очередь
std::priority_queue<int> pq;
pq.push(1);     
pq.push(10);    
pq.push(5); 
