#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node* convertarray2ll(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
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

Node* deletenode(Node* head, Node* mid)
{
    if(head==mid)
    {
        return head->next;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=mid)
    {
        prev = temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}
Node* delmiddle(Node* head)
{   //OPTIMAL - Tortoise and Hare algorithm
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newhead = deletenode(head, slow);
    return newhead;
}

int main()
{
    vector<int> arr = {3, 2, 8, 7, 9};
    Node* head = convertarray2ll(arr);
    head = delmiddle(head);
    print(head);
}
