//Dev ơi mình đi đâu thế?
//Cây AVL

#include<bits/stdc++.h>
using namespace std;

//định nghĩa kiểu dữ liệu các Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

//tính chiều cao mỗi Node
int getHeight(Node* root){
    if(root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

//Các kỹ thuật quay cây AVL
//Quay phải
Node* rightRotate(Node* root){
    Node* x = root->left;

    //bắt đầu quay phải
    root->left = x->right;
    x->right = root;

    //thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    //trả về root mới
    return x;
}

//quay trái
Node* leftRotate(Node* root){
    Node* y = root->right;

    //bắt đầu quay trái
    root->right = y->left;
    y->left = root;

    //thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    //trả về root mới
    return y;
}

//Insertion-AVL Tree
Node* Insert(Node* root, int value){
    //insert
    if (root == NULL)
    {
        //trả về Node có height = 1;
        return new Node{value, NULL, NULL, 1};
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }else 
        if(value < root->data)
            root->left = Insert(root->left, value);
            else 
                return root;
    
    //set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    //quay
    int valBalance = getHeight(root->left) - getHeight(root->right);

    //kiểm tra 4 trường hợp
    //Left left -> rightRotate
    if (valBalance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    //Right right -> leftRotate
    if(valBalance < -1 && value > root->right->data)
        return leftRotate(root); 

    //Left Right -> leftRotate -> rightRotate
    if (valBalance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right left -> rightRotate -> leftRotate
    if(valBalance < -1 && value < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }


    return root;
       
}

int COUNT = 10;
//in
void print(Node* root, int space){
    if(root == NULL)
        return;
    space += COUNT;
    print(root->right, space);
    cout<<"\n";

    for(int i = COUNT; i < space; i++)
        cout << " ";
        
    cout << root->data << "(" << root->height << ")" <<"\n";
    
    print(root->left, space);
}

void print2(Node* root){
    print(root, 0);
}

int main(){
    Node* tree = NULL;
    tree = Insert(tree, 18);
    tree = Insert(tree, 12);
    tree = Insert(tree, 30);
    tree = Insert(tree, 25);
    tree = Insert(tree, 69);
    tree = Insert(tree, 23);
    print2(tree);
}
