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
vector<vector<int>> Verticalorder(Node* root)
{
    vector<vector<int>> res;
    queue<pair<Node*, pair<int, int>>> q;
    map<int, map<int, multiset<int>>>nodes;
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node* node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        nodes[x][y].insert(node->data);
        if(node->left)
        {
            q.push({node->left, {x-1, y+1}});
        }
        if(node->right)
        {
            q.push({node->right, {x+1, y+1}});
        }
    }
    for(auto p: nodes)
    {
        vector<int> col;
        for(auto q: p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }
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
    vector<vector<int>> ans;
    ans = Verticalorder(root);
    for(int i = 0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}