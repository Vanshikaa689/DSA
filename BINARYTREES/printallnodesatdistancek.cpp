#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
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

void markparents(Node* root, unordered_map<Node*, Node*>& parent_track, Node* target)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left)
        {
            parent_track[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            parent_track[temp->right] = temp;
            q.push(temp->right);
        }
    }
}
//mark parents use a hashmap
vector<int> distancek(Node* root, Node* target, int k)
{
    unordered_map<Node*, Node*> parent_track;
    markparents(root, parent_track, target);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    while(!q.empty())
    {
        int n = q.size();
        if(level == k)//break if you reached desired level
        {
            break;
        }
        while(n--)//or use a for loop from 0 to n
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left])//chec k for tempka left right 
            //and parent if it exists and not visited push and mark true
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(parent_track[temp] && !visited[parent_track[temp]])
            {
                q.push(parent_track[temp]);
                visited[parent_track[temp]] = true;
            }
        }
        level++;
    }
    vector<int> ans;//push the q elements in the vector
    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
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
    vector<int> ans = distancek(root, root->left, 2);
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}