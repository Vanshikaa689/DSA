#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<map>
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
bool detectloop(Node* head)
{
    //optimal solution 
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
    //time complexity = o(N)
    //space complexity = o(1)
    //brute force
    // map<Node*, int>mpp;
    // Node* temp = head;
    // while(temp!=NULL)
    // {
    //     if(mpp[temp]==1)
    //     {
    //         return true;
    //     }
    //     mpp[temp] = 1;
    //     temp = temp->next; 
    // }
    // return false;
    //time complexity = O(N*logN)
    //space complexity = O(N)
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7, 9};
    Node* head = convertarray2ll(arr);
    cout<<detectloop(head);
}
