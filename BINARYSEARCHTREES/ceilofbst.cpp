// loswest val greater than equal to key
#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int data1)
    {
        data = data1;
        left = right = nullptr;
    }
};
int ceil(Node* root, int val)
{
    int ceil = -1;
    while(root!=NULL)
    {
        if(root->data == val)
        {
            ceil = root->data;
            return ceil;
        }
        if(root->data>val)
        {
            ceil = root->data;
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    return ceil;
}
int main()
{
     Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key = 5;
    int result = ceil(root, key);
    if (result == -1) {
        cout << "Ceil value not found" << endl;
    } else {
        cout << "Ceil value for " << key << " is " << result << endl;
    }

    return 0;
}
