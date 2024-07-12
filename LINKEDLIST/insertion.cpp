#include<iostream>
using namespace std;
#include<vector>
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
Node* inserthead(Node* head, int val)
{
    Node* temp = new Node(val, NULL);
    temp->next = head;
    return temp;
}
Node* inserttail(Node* head, int val)
{
    if(head==NULL)
    {
        Node* n = new Node(val, head);
        return n;
    }
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val, NULL);
        return head;
    }
}
Node* insertatind(Node* head, int ind, int val)
{
    if(head==NULL)
    {
        Node* n = new Node(val, head);
        return n;
    }
    else if(ind==0)
    {
        Node* n = new Node(val, head);
        return n;
    }
    else{
        Node* temp = head;
        Node* n = new Node(val, NULL);
        Node* prev = NULL;
        int cnt = 0;
        while(temp!=NULL && ind>cnt)
        {
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            return head;
        }
        n->next = temp;
        prev->next = n;
        return head;
    }
}
Node* insertafterval(Node* head, int val, int val2)
{
    if(head==NULL)
    {
        return head;
    }
    else
    {
        Node* temp = head;
        while(temp!=NULL && temp->data!=val)
        {
            temp = temp->next;
        }
        if(temp==NULL)
        {
            return head;
        }
        Node* n = new Node(val2, NULL);
        n->next = temp->next;
        temp->next = n;
        return head;
    }
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7};
    Node* head = convertarray2ll(arr);
    print(head);
    head = inserthead(head, 1);
    print(head);
    head = inserttail(head, 4);
    print(head);
    head = insertatind(head, 2, 6);
    print(head);
    head = insertafterval(head, 5, 9);
    print(head);
}
