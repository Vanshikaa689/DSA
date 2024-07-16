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
Node* reversell(Node* head)
{   
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node* newhead = reversell(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

Node* findknode(Node* head, int k)
{
    Node* temp = head;
    for(int i = 0; i<k-1; i++)
    {
        if(temp==nullptr)
        {
            return nullptr;
        }
        temp = temp->next;
    }
    return temp;
}
Node* reversegroup(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    int i;
    Node* temp = head;
    Node* knode = NULL;
    Node* nextnode = NULL;
    Node* prevnode = NULL;
    Node* newhead = NULL;
    while(temp!=NULL)
    {
        knode = findknode(temp, 3);
        if(knode==NULL)
        {
            if(prevnode!=NULL)
            {
                prevnode->next = temp;
            }
            break;
        }
        nextnode = knode->next;
        knode->next = NULL;
        Node* reversedhead = reversell(temp);
        if(newhead==NULL)
        {
            newhead = reversedhead;
        }
        else{
            if(prevnode!=NULL)
            {
                prevnode->next = reversedhead;
            }
        }
        prevnode = temp;
        temp = nextnode;

    }
    return newhead;
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7, 9, 10};
    Node* head = convertarray2ll(arr);
    head = reversegroup(head);
    print(head);
}
