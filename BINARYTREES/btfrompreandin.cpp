#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data1) {
        data = data1;
        left = right = nullptr;
    }
};
Node* construct(vector<int> &pre, int prestart, int preend, vector<int> &in, int instart, int inend, map<int, int> &inmap)
{
    if(prestart>preend||instart>inend)
    {
        return nullptr;
    }

    Node* root = new Node(pre[prestart]);

    int inroot = inmap[root->data];
    int numsleft = inroot - instart;
    root->left = construct(pre, prestart+1, prestart+numsleft, in, instart, inroot-1, inmap);
    root->right = construct(pre, prestart+numsleft+1, preend, in, inroot+1, inend, inmap);
    return root;
}
Node* buildtree(vector<int> &pre, vector<int> &in)
{
    map<int, int> inmap;

    for(int i = 0; i < pre.size(); i++)
    {
        inmap[in[i]] = i;
    }

    Node* root = construct(pre, 0, pre.size() - 1, in, 0, in.size() - 1, inmap);
    return root;
}
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
int main()
{   
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 20, 7, 15};
    Node* root = buildtree(pre, in);
    printInOrder(root);
    return 0;
}