// any traversal, cnt++
// time complexity = O(N)
// space complexity = O(1)

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

int findleftheight(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return 1+findleftheight(root->left);
}

int findrightheight(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return 1+findrightheight(root->right);
}
int countnodes(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int lh = findleftheight(root);
    int rh = findrightheight(root);
    if(lh = rh)
    {
        return (1<<lh)-1;
    }
    return 1+countnodes(root->left)+countnodes(root->right);
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
    cout<<countnodes(root);
}