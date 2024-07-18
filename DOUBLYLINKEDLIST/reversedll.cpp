#include<iostream>
using namespace std;
#include<vector>
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1, Node* next1, Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node* convertarray2ll(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node * temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
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
    if(head == nullptr || head->next == NULL)
    {
        return head;
    }
    Node* last = NULL;
    Node* curr = head;
    while(curr!=NULL)
    {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    return last->prev;

}
int main()
{
    vector<int> arr = {2, 5, 8, 7, 4, 5};
    Node* head = convertarray2ll(arr);
    print(head);
    head = reversell(head);
    print(head);
    return 0;
}
