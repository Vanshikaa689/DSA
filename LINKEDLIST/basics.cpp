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
int lengthofll(Node *head)
{
    int count = 0;
    Node *temp = head;
    while(temp!=nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int check(Node * head, int num)
{
    Node *temp = head;
    while(temp!=nullptr)
    {
        if(temp->data == num)
        {
            return 1;
        }
        temp = temp->next;
        
    }
    return 0;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertarray2ll(arr);
    // cout<<head->data<<"\n";
    // Node* temp = head;
    // while(temp!=NULL)
    // {
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<lenghtofll(head);
    cout<<check(head, 5);

}
