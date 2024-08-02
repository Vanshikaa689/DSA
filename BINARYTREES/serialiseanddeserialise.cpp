#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<sstream>
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
class Codec{
    public:
        string serialize(Node* root) {
        string s;
        if(root==nullptr)
        {
            return "";
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                s+="#,";
            }
            else
            {
                s+=to_string(temp->data)+",";
            }
            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }
    Node* deserialize(string data) {
        if(data.empty())
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node* root = new Node(stoi(str));
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#")
            {
                temp->left = NULL;
            }
            else
            {
                Node* leftnode = new Node(stoi(str));
                temp->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if(str=="#")
            {
                temp->right = NULL;
            }
            else
            {
                Node* rightnode = new Node(stoi(str));
                temp->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    Codec sol;
    string serialized = sol.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    Node* deserializedRoot = sol.deserialize(serialized);
    string reserialized = sol.serialize(deserializedRoot);
    cout << "Reserialized Tree: " << reserialized << endl;
}

    
