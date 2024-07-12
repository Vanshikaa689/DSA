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
Node* add2numbers(Node* num1, Node* num2)
{
    Node* dummyhead = new Node(-1);
    Node* curr = dummyhead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1!=NULL&&temp2!=NULL)
    {
        int sum = carry;
        if(temp1!=NULL)
        {
            sum+=temp1->data;
        }
        if(temp2!=NULL)
        {
            sum+=temp2->data;
        }
        carry = sum/10;
        Node* newNode = new Node(sum%10);
        curr->next = newNode;
        curr = curr->next;
        if(temp1!=NULL)
        {
            temp1 = temp1->next;
        }
        if(temp2!=NULL)
        {
            temp2 = temp2->next;
        }
    }
    if(carry)
    {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyhead->next;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    Node* head1 = array2ll(arr1);
    Node* head2 = array2ll(arr2);
    Node* head = add2numbers(head1, head2);
    print(head);
}
