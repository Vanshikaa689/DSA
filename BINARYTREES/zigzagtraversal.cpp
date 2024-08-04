#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
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
vector<vector<int>> levelorder(Node* root)
{
    vector<vector<int>> ans;
    queue<Node*> pq;
    pq.push(root);
    int count = 0;
    while(!pq.empty())
    {
        vector<int> level;
        int size = pq.size();
        for(int i = 0; i<size; i++)
        {
            Node* temp = pq.front();
            pq.pop();
            level.push_back(temp->data);
            if(temp->left!=NULL)
            {
                pq.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                pq.push(temp->right);
            }
        }
        count++;
        if(count%2==0)
        {

            reverse(level.begin(), level.end());
        }
        ans.push_back(level);
    }
    return ans;
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

    vector<vector<int>> ans = levelorder(root);

    for(int i = 0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}