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
Node* insert(Node* root, int val)
{
    Node* curr = root;
    if(root==nullptr)
    {
        return new Node(val);
    }
    while(true)
    {
        if(val<curr->data)
        {
            if(curr->left==nullptr)
            {
                curr->left = new Node(val);
                break;
            }
            curr = curr->left;
        }
        else
        {
            if(curr->right==nullptr)
            {
                curr->right = new Node(val);
                break;
            }
            curr = curr->right;
        }
    }
    return root;

}
void inorder(Node* root)
{
    Node* temp = root;
    if(temp==NULL)
    {
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
    //time complexity = O(N)
    //space complexity = O(N)
}
int main()
{
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    inorder(root);
}