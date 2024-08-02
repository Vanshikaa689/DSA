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
bool findpath(Node* root, vector<int> &ans, int val)
{
    if(!root)
    {
        return false;
    }
    ans.push_back(root->data);
    if(root->data == val)
    {
        return true;
    }
    if(findpath(root->left, ans, val)||
    findpath(root->right, ans, val))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> solution(Node* root, int val)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    findpath(root, ans, val);
    return ans;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> ans = solution(root, 7);
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}