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
Node* removehead(Node* head)
{
    if(head==nullptr)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return head;
}
Node* removetail(Node* head)
{

    if(head==nullptr)
    {
        return NULL;
    }
    else if(head->next==nullptr)
    {
        delete head;
    }
    else{
        Node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return head;
    }
}
Node* removeatind(Node* head, int ind)
{
    if(head==nullptr)
    {
        return NULL;
    }
    else if(ind==0)
    {
        // return removehead(head);
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    else{
        int cnt = 0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp!=NULL&&cnt<ind)
        {
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            return head;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    
}
Node* removeval(Node* head, int val)
{
    if(head==nullptr)
    {
        return NULL;
    }
    else if(head->data==val)
    {
        // return removehead(head);
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        while(temp!=NULL&&temp->data!=val)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            return head;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7};
    Node* head = convertarray2ll(arr);
    print(head);
    head = removehead(head);
    print(head);
    head = removetail(head);
    print(head);
    head = removeatind(head, 2);
    print(head);
    head = removeval(head, 2);
    print(head);
}
