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
void preorder(Node* root)
{
    Node* temp = root;
    if(temp==NULL)
    {
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
    //time complexity = O(N)
    //space complexity = O(N)
}
void postorder(Node* root)
{
    Node* temp = root;
    if(temp==NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
    //time complexity = O(N)
    //space complexity = O(N)
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
vector<vector<int>> levelorder(Node* root)
{
    vector<vector<int>> ans;
    queue<Node*> pq;
    pq.push(root);
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
        ans.push_back(level);
    }
    return ans;
    //time complexity = O(N)
    //space complexity = O(N)
}
vector<int> preordert(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    stack<Node* > st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL)
        {
            st.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            st.push(temp->left);
        }
    }
    return ans;
    //time complexity = O(N)
    //space complexity = O(N)
}
vector<int> inordert(Node* root)
{
    vector<int> ans;
    stack<Node*>st;
    if(root==NULL)
    {
        return ans;
    }
    Node* temp = root;
    while(true)
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
    //time complexity = O(N)
    //space complexity = O(N)
}
vector <int> postordert(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    stack<Node*>st1, st2;
    st1.push(root);
    while(!st1.empty())
    {
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left!=NULL)
        {
            st1.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            st1.push(temp->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
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
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    vector<vector<int>> ans = levelorder(root);
    for(int i = 0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
    } 
    cout<<endl;
    vector<int> ans1 = preordert(root);
    for(int i = 0; i<ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    ans1 = inordert(root);
    for(int i = 0; i<ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    ans1 = postordert(root);
    for(int i = 0; i<ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }
     
}