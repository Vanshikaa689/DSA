#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
bool isSymmetrichelp(Node* left, Node* right)
{
    if(left==NULL||right==NULL)
    {
        return left==right;
    }
    if(left->data!=right->data)
    {
        return false;
    }
    return (isSymmetrichelp(left->left, right->right)&&isSymmetrichelp(left->right, right->left));

}
bool isSymmetric(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    return isSymmetrichelp(root->left, root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    cout<<isSymmetric(root);
}