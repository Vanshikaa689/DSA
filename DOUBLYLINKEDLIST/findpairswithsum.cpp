#include<iostream>
using namespace std;
#include<vector>
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1, Node* next1, Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node* convertarray2ll(vector<int> &arr)
{
    if(arr.empty())
    {
        return NULL;
    }
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node * temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
vector<pair<int, int>> findpairswithsumk(Node* head, int sum)
{
    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = head;
    while(right->next!=nullptr)
    {
        
        right = right->next;
    }
    while(left<right)
    {
        if(left->data + right->data == sum)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(left->data + right->data < sum)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
    
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertarray2ll(arr);
    vector<pair<int, int>> ans;
    ans = findpairswithsumk(head, 5);
    for(auto i : ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

}
