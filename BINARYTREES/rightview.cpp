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
vector<int> rightview(Node* root, int level, vector<int> &ans)
{
   if(root==NULL)
   {
       return ans;
   }
   if(ans.size()==level)
   {
    ans.push_back(root->data);
   }
   rightview(root->right, level+1, ans);
   rightview(root->left, level+1, ans);
   return ans;
}
vector<int> rightviewhelper(Node* root, int level)
{
    vector<int> ans;
    rightview(root, level, ans);
    return ans;
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
    res = rightviewhelper(root, 0);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
}