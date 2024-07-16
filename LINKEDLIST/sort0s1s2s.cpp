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

Node* sortarray(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* dummy0 = new Node(-1);
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);
    Node* zero = dummy0;
    Node* one = dummy1;
    Node* two = dummy2;

    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            temp=temp->next;
            zero = zero->next;
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            temp=temp->next;
            one = one->next;
        }
        else
        {
            two->next = temp;
            temp=temp->next;
            two = two->next;
        }
    }

    zero->next = (dummy1->next)?(dummy1->next):dummy2->next;
    one->next = dummy2->next;
    two->next = NULL;
    Node* newhead = dummy0->next;
    delete(dummy0);
    delete(dummy1) ;
    delete(dummy2);
    return newhead;
    //time complexity = O(N)
    //space complexity = O(1)
}
int main()
{
    vector<int> arr1 = {1, 0, 0, 2, 1, 2 ,0, 0, 1};
    Node* head = array2ll(arr1);
    head = sortarray(head);
    print(head);
}
