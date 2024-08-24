#include<iostream>
using namespace std;
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
Node* search(Node* root, int val)
{
    while(root!=NULL && root->data!=val)
    {
        if(root->data>val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(root==NULL)
    {
        return NULL;
    }
    return root;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(search(root, 3)!=NULL)
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
}