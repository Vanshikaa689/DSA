//node a -> node b 
//in a path a single node appears only once
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
int maxsumpath(Node* root, int &maxi)
{
    if(root==nullptr){
        return 0;
    }
    int lh = max(0, maxsumpath(root->left, maxi));
    int rh = max(0, maxsumpath(root->right, maxi));
    maxi = max(maxi, lh+rh+root->data);
    return max(lh,rh) + root->data;
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
    int maxi = INT_MIN;
    maxsumpath(root, maxi);
    cout<<maxi;
    
}