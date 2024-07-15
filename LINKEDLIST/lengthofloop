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
int lengthofloop(Node* head)
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
            break;
        }
    }
    int count = 1;
    slow = slow->next;
    while(fast!=slow)
    {
        slow = slow->next;
        count++;
    }
    return count;
    //brute force
    // map<Node*, int> mpp;
    // Node* temp = head;
    // int timer = 1;
    // while(temp!=NULL)
    // {
    //     if(mpp.find(temp)!=mpp.end())//if mpp[temp] is not a new element it wont return a pointer poiting to mpp.end()
    //     {
    //         //if key temp is found in the map find returns an iterator pointing to the element in the map
    //         int value = mpp[temp];
    //         return timer - value;
    //     }
    //     mpp[temp] = timer;
    //     timer++;
    //     temp = temp->next;
    // }
    // return -1;
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7, 9};
    Node* head = convertarray2ll(arr);
    cout<<lengthofloop(head);
}
