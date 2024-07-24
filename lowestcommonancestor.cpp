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
Node* lca(Node* root, Node* p, Node*q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root==p||root==q)
    {
        return root;
    }
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
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

    Node* p = lca(root, root->left->left, root->right->right);
    cout<<p->data;
}