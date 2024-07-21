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
Node* construct(vector<int> &post, int poststart, int postend, vector<int> &in, int instart, int inend, map<int, int> &inmap)
{
    if(poststart>postend||instart>inend)
    {
        return nullptr;
    }

    Node* root = new Node(post[postend]);

    int inroot = inmap[root->data];
    int numsleft = inroot - instart;
    root->left = construct(post, poststart, poststart+numsleft-1, in, instart, inroot-1, inmap);
    root->right = construct(post, poststart+numsleft, postend-1, in, inroot+1, inend, inmap);
    return root;
}
Node* buildtree(vector<int> &post, vector<int> &in)
{
    map<int, int> inmap;

    for(int i = 0; i < post.size(); i++)
    {
        inmap[in[i]] = i;
    }

    Node* root = construct(post, 0, post.size() - 1, in, 0, in.size() - 1, inmap);
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
    vector<int> in = {40, 20, 50, 10, 60, 30};
    vector<int> post = {40, 50, 20, 60, 30, 10};
    Node* root = buildtree(post, in);
    printInOrder(root);
    return 0;
}