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
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    //time complexity = O(N/2)
    //space complexity = O(1)

    //BRUTE FORCE
    // Node* temp = head;
    // int count = 0;
    // while(temp!=NULL)
    // {
    //     temp = temp->next;
    //     count++;
    // }
    // int middlenode = count/2 +1;
    // temp = head;
    // for(int i = 1; i<middlenode; i++)
    // {
    //     temp = temp->next;
    // }
    // return temp->data;
    //time complexity = O(N+N/2)
    //space complexity = O(1)1
}

int main()
{
    vector<int> arr = {3, 2, 5, 8, 7, 9};
    Node* head = convertarray2ll(arr);
    Node* mid = middle(head);
    cout<<mid->data;
}
