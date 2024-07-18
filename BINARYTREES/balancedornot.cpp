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
int maxdepth(Node* root)
{
    if(root==nullptr){
        return 0;
    }
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    if(lh==-1||rh==-1)
    {
        return -1;
    }
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return max(lh,rh)+1;
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
    if(maxdepth(root)!=-1)
    {
        cout<<"balanced";
    }
    else{
        cout<<"unbalanced";
    }
}
