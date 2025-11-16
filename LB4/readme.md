Определения понятий:
	Дерево — это иерархическая структура данных, состоящая из узлов, соединённых рёбрами. 
	Оно имеет корневой узел и ветви, ведущие к потомкам. Особенность дерева — наличие 
	единственного пути от корня к любому узлу. Примеры деревьев включают бинарные деревья 
	поиска, AVL-деревья, красно-чёрные деревья и др.

	Граф — это набор вершин (узлов) и рёбер, соединяющих вершины. Графы бывают разными 
	видами: направленные (ориентированные) и ненаправленные, взвешенные и невзвешенные. 
	Примеры графов: социальные сети, транспортные маршруты, веб-графы и многие другие.

Формирование деревьев и графов на Python, Java и C++:
	Деревья:
		Python:
		Обычно реализуется с помощью классов или простых кортежей/диктов.
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

Простое дерево можно сформировать так:
```python
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
```

		Java:
		Деревья строятся через классы и рекурсивные связи.
```java
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) {
        this.val = val;
    }
}
```

Создание дерева:
```java
TreeNode root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
```

		C++:
		Деревья формируются аналогично Java/Python, но с использованием указателей.
```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
```

Создание дерева:
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
```

---

	Графы:
		Python:
		Представляется матрицами смежности или списками смежности.
Матрица смежности:
```python
graph = [
    [0, 1, 0, 0],
    [1, 0, 1, 1],
    [0, 1, 0, 1],
    [0, 1, 1, 0]
]
```

Список смежности:
```python
graph = {
    0: [1],
    1: [0, 2, 3],
    2: [1, 3],
    3: [1, 2]
}
```

		Java:
		Чаще всего графы представляют списками смежности с использованием классов.
```java
import java.util.ArrayList;
import java.util.List;
class Graph {
    private final int V;
    private List<List<Integer>> adj;
    Graph(int vertices) {
        V = vertices;
        adj = new ArrayList<>(V);
        for (int i = 0; i < V; ++i) {
            adj.add(new ArrayList<>());
        }
    }
    void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u); // Если граф несимметричен, убрать вторую строку
    }
}
```

Использование:
```java
Graph g = new Graph(4);
g.addEdge(0, 1);
g.addEdge(1, 2);
g.addEdge(1, 3);
g.addEdge(2, 3);
```

		C++:
		Также возможны матрица смежности и список смежности.
Матрица смежности:
```cpp
const int N = 4;
int graph[N][N] = {
    {0, 1, 0, 0},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0}
};
```

Список смежности:
```cpp
#include <vector>
std::vector<std::vector<int>> graph(N);
graph[0].push_back(1);
graph[1].push_back(0);
graph[1].push_back(2);
graph[1].push_back(3);
graph[2].push_back(1);
graph[2].push_back(3);
graph[3].push_back(1);
graph[3].push_back(2);
```
---


Алгоритм обхода дерева DFS (Depth-First Search):
	Обход в глубину (DFS) — это алгоритм поиска, который последовательно проходит по ветвям 
	дерева до тех пор, пока не достигнет листа, затем возвращается назад и исследует 
	следующую ветку.
	Шаги работы алгоритма:
		1. Посещаем корень дерева.
		2. Рекурсивно проходим левое поддерево.
		3. Затем правое поддерево.
		4. Повторяем шаги для каждого поддерева.
	Время работы: O(n), где n — количество узлов в дереве.
	Пример кода на Python:
```python
def dfs(root):
    if not root:
        return
    print(root.val)  # Обработка текущего узла
    dfs(root.left)   # Левое поддерево
    dfs(root.right)  # Правое поддерево
```

		Пример кода на Java:
```java
void dfs(TreeNode node) {
    if (node == null) return;
    System.out.print(node.val + " ");  // Обрабатываем текущий узел
    dfs(node.left);                     // Левое поддерево
    dfs(node.right);                   // Правое поддерево
}
```

		Пример кода на C++:
```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    std::cout << node->val << " ";  // Обрабатываем текущий узел
    dfs(node->left);                 // Левое поддерево
    dfs(node->right);                // Правое поддерево
}
```
