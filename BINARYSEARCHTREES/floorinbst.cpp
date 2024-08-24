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
int floor(Node* root, int val)
{
    int floor = -1;
    while(root!=NULL)
    {
        if(root->data == val)
        {
            floor = root->data;
            return floor;
        }
        if(root->data>val)
        {
            root = root->left;
        }
        else 
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
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
    int result = floor(root, key);
    if (result == -1) {
        cout << "floor value not found" << endl;
    } else {
        cout << "floor value for " << key << " is " << result << endl;
    }

    return 0;
}