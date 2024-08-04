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
vector<int> topview(Node* root)
{
    queue<pair<Node*, int>> q;
    vector<int> res;
    map<int, Node*> mpp;
    if(root==NULL)
    {
        return res;
    }
    q.push({root, 0});
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node* node = temp.first;
        int x = temp.second;
        if(mpp.find(x)==mpp.end())
        {
            mpp[x] = node;
        }
        if(node->left)
        {
            q.push({node->left, x-1});
        }
        if(node->right)
        {
            q.push({node->right, x+1});
        }
    }
    for(auto i:mpp)
    {
        res.push_back(i.second->data);
    }
    
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(7);
    vector<int> res;
    res = topview(root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
}