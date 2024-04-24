//Traversing linked list: duyệt qua và in ra giá trị cụ thể của từng node
#include<bits/stdc++.h>
using namespace std;

//khai báo cấu trúc của node trong linked list
struct Node{
    int data;
    Node* next;
};

//hàm duyệt qua và in giá trị của từng node trong linked list
void printLinkedList(Node* head){
    Node* current = head;  //đặt node current là node đầu tiên của linked list

    while(current != nullptr){
        cout << current->data << " "; //in  ra giá trị của node hiện tại
        current = current->next; //chuyển sang node kế tiếp
    }
}

int main(){
    //tạo các node trong linked list
    Node* head = new Node(); //Node đầu tiên
    Node* second = new Node(); // Node thứ hai
    Node* third = new Node();  // Node thứ ba


    //Gán giá trị vào từng node
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = nullptr; // không có node kế tiếp

    //duyệt qua và in giá trị của từng node trong linked list
    printLinkedList(head);

    //giải phóng bộ nhớ
    delete head;
    delete second;
    delete third;

    return 0;
}


//thêm , xoá node
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void addToBeginning(Node*& head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteLastNode(Node*& head){
    if(head == nullptr){
        return ; // danh sách rỗng
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return ; // danh sách chỉ có một node
    }

    Node* current = head;
    while(current->next->next != nullptr){
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}
int main(){
    Node* head = nullptr; //khởi tạo danh sách rỗng

    //thêm các node vào đầu danh sách
    addToBeginning(head, 3);
    addToBeginning(head, 2);
    addToBeginning(head, 1);

    //xoá node cuối
    deleteLastNode(head);

    //in danh sách
    Node* current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    
    return 0;
}

//đảo ngược thứ tự các node trong linked list
//sd 3 con trỏ
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//sd đệ quy
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

//tìm kiếm và xoá node chứa giá trị cụ thể trong linked list
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteNode(Node** head, int value){
    //trường hợp danh sách liên kết rỗng
    if(*head == nullptr){
        return;
    }

    //nếu node đầu danh sách liên kết chứa giá trị cần xoá
    if((*head)->data == value){
        Node* temp = *head;
        *head = (*head) -> next;
        delete temp;
        return;
    }

    //tìm node chứa giá trị cần xoá
    Node* current = *head;
    Node* prev = nullptr;

    while(current != nullptr && current->data != value){
        prev = current;
        current = current->next;
    }

    //nếu không tìm giá trị cần xoá
    if(current == nullptr){
        return;
    }

    //xoá node chứa giá trị cần xoá
    prev->next = current->next;
    delete current;
}

void printList(Node* node){
    while(node != nullptr){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    //tạo danh sách liên kết ví dụ
    Node* head = new Node(); //Node đầu tiên
    Node* second = new Node(); // Node thứ hai
    Node* third = new Node();  // Node thứ ba


    //Gán giá trị vào từng node
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = nullptr; // không có node kế tiếp

    //in ra danh sách liên kết ban đầu
    cout << "danh sách liên kết ban đầu: ";
    printList(head);

    //tìm kiếm và xoá giá trị 2
    deleteNode(&head, 2);

    //in ra danh sách sau khi xoá
    cout << "danh sách liên kết sau khi xoá là: ";
    printList(head);

    return 0;
}


//merge hai linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Hàm để thêm một nút mới vào linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Hàm để in linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Hàm để merge hai linked list đã cho thành một linked list mới
Node* mergeLists(Node* list1, Node* list2) {
    Node* result = nullptr;

    // Nếu list1 là rỗng, trả về list2
    if (list1 == nullptr) {
        return list2;
    }
    // Nếu list2 là rỗng, trả về list1
    if (list2 == nullptr) {
        return list1;
    }

    // Chọn node đầu tiên từ hai linked list
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeLists(list1, list2->next);
    }

    return result;
}

int main() {
    // Tạo hai linked list đã cho
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    push(&list1, 5);
    push(&list1, 3);
    push(&list1, 1);

    push(&list2, 6);
    push(&list2, 4);
    push(&list2, 2);

    cout <<"linked list 1: ";
    printList(list1);

    cout <<"linked list 2: ";
    printList(list2);

    // Merge hai linked list
    Node* mergedList = mergeLists(list1, list2);

    cout <<"merged list: ";
    printList(mergedList);

    return 0;