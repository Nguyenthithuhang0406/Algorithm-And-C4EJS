// Tìm kiếm trong cây nhị phân (binary search tree)
#include <bits/stdc++.h>
using namespace std;

// Định nghĩa class đại diện cho một nút trong cây nhị phân
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm tìm kiếm một giá trị trong cây nhị phân
Node *search(Node *root, int key)
{
    // Nếu cây rỗng hoặc khóa khớp với giá trị của nút gốc
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    // Nếu khóa nhỏ hơn giá trị của nút gốc, đi sang cây con trái
    if (root->data > key)
    {
        return search(root->left, key);
    }

    // Ngược lại, đi sang cây con phải
    return search(root->right, key);
}

int main()
{
    // Xây dựng cây nhị phân
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    int key = 6;
    Node *result = search(root, key);

    if (result != nullptr)
    {
        cout << "Giá trị " << key << " được tìm thấy trong cây." << endl;
    }
    else
    {
        cout << "Giá trị " << key << " không tồn tại trong cây." << endl;
    }

    return 0;
}

// Cân bằng trong cây nhị phân (Balanced Binary Tree)
#include <bits/stdc++.h>
using namespace std;

// Định nghĩa cấu trúc của một Node trong cây nhị phân AVL
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Tính chiều cao của một node
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// Tạo một node mới
Node *createNode(int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

// Xoay phải tại node x
Node *rotateRight(Node *x)
{
    Node *y = x->left;
    Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

// Xoay trái tại node y
Node *rotateLeft(Node *y)
{
    Node *x = y->right;
    Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Lấy hiệu số cân bằng của một node
int getBalanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Chèn một node mới vào cây
Node *insertNode(Node *root, int key)
{
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root;

    root->height = std::max(height(root->left), height(root->right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    // Kiểm tra cân bằng và xoay cây để cân bằng
    if (balanceFactor > 1)
    {
        if (key < root->left->key)
        {
            return rotateRight(root);
        }
        else if (key > root->left->key)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balanceFactor < -1)
    {
        if (key > root->right->key)
        {
            return rotateLeft(root);
        }
        else if (key < root->right->key)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// In-order traversal để in cây nhị phân AVL
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;

    // Chèn các phần tử vào cây
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Cây nhị phân AVL sau khi chèn: ";
    inorderTraversal(root);

    return 0;
}

// duyệt các loại cây (Traversal)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Hàm đệ quy để duyệt cây theo pre-order
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    // Tạo một cây nhị phân đơn giản
    Node *root = new Node();
    root->data = 1;

    Node *leftChild = new Node();
    leftChild->data = 2;

    Node *rightChild = new Node();
    rightChild->data = 3;

    root->left = leftChild;
    root->right = rightChild;

    // Duyệt cây theo pre-order
    preOrder(root);

    return 0;
}

// Spanning Tree

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc đỉnh
struct Node
{
    int parent;
    vector<int> neighbors;
};

// Hàm tìm cây bao trùm
void findSpanningTree(vector<Node> &graph, int start)
{
    graph[start].parent = -1; // Gốc của cây

    vector<int> queue;
    queue.push_back(start);

    while (!queue.empty())
    {
        int current = queue.front();
        queue.erase(queue.begin());

        for (int i = 0; i < graph[current].neighbors.size(); i++)
        {
            int neighbor = graph[current].neighbors[i];
            if (graph[neighbor].parent == -1)
            {
                graph[neighbor].parent = current;
                queue.push_back(neighbor);
            }
        }
    }
}

int main()
{
    int numVertices, numEdges;
    cout << "Nhập số đỉnh: ";
    cin >> numVertices;
    cout << "Nhập số cạnh: ";
    cin >> numEdges;

    vector<Node> graph(numVertices);

    cout << "Nhập cạnh (u, v) là cung nối giữa hai đỉnh u và v: " << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].neighbors.push_back(v);
        graph[v].neighbors.push_back(u);
    }

    int startVertex;
    cout << "Nhập đỉnh bắt đầu tìm cây bao trùm: ";
    cin >> startVertex;

    findSpanningTree(graph, startVertex);

    cout << "Cây bao trùm: " << endl;
    for (int i = 0; i < numVertices; i++)
    {
        if (graph[i].parent != -1)
        {
            cout << "(" << graph[i].parent << " - " << i << ")" << endl;
        }
    }

    return 0;
}

// Triển Khai Cây Tiền Tố Trie

#include <bits/stdc++.h>
using namespace std;

// Định nghĩa Node cho Trie
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

// Class Trie
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Hàm chèn một từ vào cây tiền tố
    void insert(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                current->children[ch] = new TrieNode(); // Nếu không có nút con chưa tồn tại, tạo mới một nút con
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true; // Đánh dấu kết thúc của một từ
    }

    // Hàm kiểm tra xem một từ có tồn tại trong cây tiền tố hay không
    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                return false; // Nếu không tìm thấy ký tự, từ không tồn tại trong cây tiền tố
            }
            current = current->children[ch];
        }
        return current->isEndOfWord; // Trả về true nếu đây là kết thúc của một từ
    }
};

int main()
{
    Trie trie;

    // Chèn các từ vào cây tiền tố
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("cat");
    trie.insert("dog");

    // Tìm kiếm từ trong cây tiền tố
    cout << trie.search("apple") << endl;  // Kết quả: 1 (true)
    cout << trie.search("banana") << endl; // Kết quả: 1 (true)
    cout << trie.search("cat") << endl;    // Kết quả: 1 (true)
    cout << trie.search("dog") << endl;    // Kết quả: 1 (true)
    cout << trie.search("car") << endl;    // Kết quả: 0 (false)

    return 0;
}
