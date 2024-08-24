// lowest val greater than equal to key
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
int kth(Node* root, int k, int &count)
{
    Node* curr = root;
    if(root == nullptr)
    {
        return -1;
    }
    int left = kth(curr->left, k, count);
    if(left!=-1)
    {
        return left;
    }
    count++;
    if(k==count)
    {
        return curr->data;
    }
    return kth(curr->right, k, count);
    return 0;
    
}
int kthsmallest(Node* root, int k)
{
    int count = 0;
    return kth(root, k, count);
}
int  main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    int k = 2;
    cout<<kthsmallest(root, k);
    return 0;

} 
