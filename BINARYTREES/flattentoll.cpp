#include <iostream>
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

void flatten(Node* root) {
    if (root == NULL) {
        return;
    }
    static Node* prev = NULL;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

void printFlattenedTree(Node* root) {
    Node* current = root;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    flatten(root);
    printFlattenedTree(root);
    return 0;
}
