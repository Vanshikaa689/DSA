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
// 0 based indexing - 2*i+1 , 2*i+2
// queue - node, level(index)
int width(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    int res = 0;
    while(!q.empty())
    {
        int mmin = q.front().second;
        int n = q.size();
        int first, last;
        for(int i = 0; i<n; i++)
        {
            int cur_id = q.front().second-mmin;
            Node* temp = q.front().first;
            q.pop();
            if(i==0)
            {
                first = cur_id;
            }
            if(i==n-1)
            {
                last = cur_id;
            }
            if(temp->left)
            {
                q.push({temp->left, 2*cur_id+1});
            }
            if(temp->right)
            {
                q.push({temp->right, 2*cur_id+2});
            }
        }
        res = max(res, last-first+1);
    }
    return res;
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
    cout<<width(root);
}