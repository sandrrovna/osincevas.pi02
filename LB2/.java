//Мультисписок
public class Node {
    int data;
    Node prev;   
    Node next;
    
    public Node(int data)
     {  
        this.data = data;       
        this.prev = null;       
        this.next = null;       
    }   
}
public class DoublyLinkedList {
    Node head;   
    Node tail;
    
    public DoublyLinkedList()   
    {
        this.head = null;     
        this.tail = null;       
    }   
}

//Очередь
Queue<String> queue = new LinkedList<>();
queue.add('фундук'); 
queue.add('миндаль'); 
queue.add('фисташка'); 

//Дек
Deque<Integer> stack = new ArrayDeque<>();
stack.push(11); 
stack.push(12); 
stack.push(13); 

//Приоритетная очередь
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
minHeap.offer(5); 
minHeap.offer(2); 
minHeap.offer(10); 
minHeap.offer(1); 
