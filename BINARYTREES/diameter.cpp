//longest path bwtween any two nodes
//path doesnt need to pass through root
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
int diameter(Node* root, int &maxi)
{
    if(root==nullptr)
    {
        return 0;
    }
    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);
    maxi = max(maxi, lh+rh);
    return max(lh,rh)+1;
    //time complexity = O(N)
    //space complexity = O(N)
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
    int maxdia = 0;
    diameter(root, maxdia);
    cout<<maxdia;
}