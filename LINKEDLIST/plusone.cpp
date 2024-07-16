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
Node* array2ll(vector<int> arr)
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
int helper(Node* head)
{
    if(head==NULL)
    {
        return 1;
    }
    int carry = helper(head->next);
    int val = head->data+carry;
    head->data = val%10;
    carry = val/10;
    return carry;
}
Node* plusone(Node* head)
{
    //using recursion 
    int carry = helper(head);
    if(carry == 1)
    {
        Node* newhead = new Node(1, head);
        return newhead;
    }
    return head;
    //iterative
    // int carry = 1;
    // if(head==NULL)
    // {
    //     return head;
    // }
    // else if(head->next == NULL)
    // {
    //     int val = head->data+carry;
    //     head->data = val%10;
    //     if(carry==1)
    //     {
    //         Node* n = new Node(1, NULL);
    //         return n;
    //     }
    //     return head;
    // }
    // head = reversell(head);
    // Node* temp = head;
    // while(temp!=NULL)
    // {
    //     int val = temp->data+carry;
    //     temp->data = val%10;
    //     carry = val/10;
    //     temp = temp->next;
    // }
    // head = reversell(head);
    // if(carry==1)
    // {
    //     Node* newhead = new Node(carry, head);
    //     return newhead;
    // }
    // return head;
}
int main()
{
    vector<int> arr = {9,9,9,9};
    Node* head = array2ll(arr);
    head = plusone(head);
    print(head);
}
