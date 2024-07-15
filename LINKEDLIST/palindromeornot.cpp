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
Node* middle(Node* head)
{   //OPTIMAL - Tortoise and Hare algorithm
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

bool isPalindrome(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return true;
    }
    Node* mid = middle(head);//O(N/2)
    Node* newhead = reversell(mid->next);//O(N/2)
    mid->next = NULL;
    Node* temp1 = head;
    Node* temp2 = newhead;
    while(temp1!=nullptr && temp2!=nullptr)//O(N/2)
    {
        if(temp1->data != temp2->data)
        {
            reversell(newhead);//O(N/2)
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    reversell(newhead);
    return true;
    //time complexity = O(2N)
    //space comoplexity = O(1)
}
int main()
{
    vector<int> arr = {3, 2, 5, 4, 3, 2};
    Node* head = convertarray2ll(arr);
    cout<<isPalindrome(head);
}
