//longest path bwtween any two nodes
//path doesnt need to pass through root
#include<iostream>
using namespace std;
#include<vector>
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
bool isLeaf(Node* root)
{
    return root->left==nullptr&&root->right==nullptr;
}
void addLeft(Node* root, vector<int> res)
{
    Node* curr = root->left;
    while(curr!=nullptr)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if(curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void addRight(Node* root, vector<int> res)
{
    Node* curr = root->right;
    stack<int> st;
    while(curr!=nullptr)
    {
        if(!isLeaf(curr))
        {
            st.push(curr->data);
        }
        if(curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
}
void addLeaves(Node* root, vector<int> res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
}
vector<int> printBoundary(Node* root, vector<int> &res)
{
    if(root==nullptr)
    {
        return res;
    }
    if(!isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);
    return res;
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
    vector<int> res;
    printBoundary(root, res);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
}