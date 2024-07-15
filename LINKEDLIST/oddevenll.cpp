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
// Node* oddeven(Node* head)
// {
//     if(head==NULL||head->next == NULL)
//     {
//         return head;
//     }
//     vector<int> arr;
//     Node* temp = head;
//     while(temp!=NULL&&temp->next!=NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp)
//     {
//         arr.push_back(temp->data);
//     }
//     temp = head->next;
//     while(temp!=NULL&&temp->next!=NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp)
//     {
//         arr.push_back(temp->data);
//     }
//     Node* headn = new Node(arr[0]);
//     Node* mover = headn;
//     for(int i=1; i<arr.size(); i++)
//     {
//         Node * temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = mover->next;
//     }
//     return headn;
    
// }
Node* oddeven(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenstart = even;
    while(even!=NULL&&even->next!=NULL)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenstart;
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
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* head = array2ll(arr);
    Node* newhead = oddeven(head);
    print(newhead);
}
