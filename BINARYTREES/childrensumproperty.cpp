#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data1) {
        data = data1;
        left = right = nullptr;
    }
};

void changeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    int child = 0;
    if (root->left) {
        child += root->left->data;
    }
    if (root->right) {
        child += root->right->data;
    }
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) {
            root->left->data = root->data;
        }
        if (root->right) {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    int sum = 0;
    if (root->left) {
        sum += root->left->data;
    }
    if (root->right) {
        sum += root->right->data;
    }
    if (root->left || root->right) {
        root->data = sum;
    }
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    changeTree(root);
    printInOrder(root);
    return 0;
}
