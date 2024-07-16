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
int lenghtofll(Node *head)
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
    if(head==nullptr|| head->next == nullptr)
    {
        return NULL;
    }
    Node* prev = head;
    head= head->next;
    prev->next = NULL;
    head->prev = NULL;
    delete(prev);
    return head;
}
Node* removetail(Node* head)
{

    if(head==nullptr||head->next==nullptr)
    {
        return nullptr;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next->prev = NULL;
    delete(temp->next);
    temp->next = NULL;
    return head;

}
Node* removeatind(Node* head, int ind)
{
    if(head==nullptr)
    {
        return NULL;
    }
    int cnt = 1;
    Node* temp = head;
    while(temp!=NULL&&cnt!=ind)
    {
        temp= temp->next;
        cnt++;
    }
    if(temp==NULL)
    {
        return head;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    if(front==NULL && back == NULL)
    {
        return NULL;
    }
    if(front==NULL)
    {
        removetail(head);
    }
    else if(back==NULL)
    {
        removehead(head);
    }
    else
    {
        back->next = front;
        front->prev = back;
        temp->next = NULL;
        temp->prev = NULL;
        delete(temp);
        return head;
    }
}
Node* deleteval(Node* head, int val)
{
    if(head==nullptr)
    {
        return NULL;
    }
    if(head->data==val)
    {
        return removehead(head);
    }
    Node* temp = head;
    while(temp!=NULL && temp->data!=val)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return head;
    }
    if(temp->next==NULL)
    {
        return removetail(head);
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete(temp);
    return head;
   
}
Node* insertbeforehead(Node* head, int val)
{
    Node* temp = new Node(val, head, nullptr); 
    if(head==nullptr)
    {
        return temp;
    }
    head->prev = temp;
    return temp;
}
Node* insertaftertail(Node* head, int val)
{
    Node* temp = new Node(val, nullptr, nullptr);
    if(head==nullptr)
    {
        return temp;
    }
    Node* temp1 = head;
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    return head;
}
Node* insertatind(Node*head, int ind, int val)
{
    Node* temp = new Node(val, nullptr, nullptr);
    if(head==nullptr)
    {
        return temp;
    }
    if(ind==0)
    {
        return insertbeforehead(head, val);
    }
    Node* temp1 = head;
    int cnt = 0;
    while(temp1!=NULL&& cnt!=ind)
    {
        cnt++;
        temp1=temp1->next;
    }
    if(temp1==NULL)
    {
        return head;
    }
    temp->next = temp1;
    temp->prev = temp1->prev;
    temp1->prev->next = temp;
    temp1->prev = temp;
    return head;

}
Node* insertbeforeval(Node* head, int val, int val2)
{
    if(head==nullptr)
    {
        return NULL;
    }
    if(head->data==val)
    {
        return insertbeforehead(head, val2);
    }
    Node*temp = head;
    while(temp!=NULL&&temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return head;
    }
    Node* temp1 = new Node(val2, nullptr, nullptr);
    temp1->next = temp;
    temp1->prev = temp->prev;
    temp->prev->next = temp1;
    temp->prev = temp1;
    return head; 
}

int main()
{
    vector<int> arr = {2, 5, 8, 7, 4, 5};
    Node* head = convertarray2ll(arr);
    print(head);
    head = removehead(head);
    print(head);
    head = removetail(head);
    print(head);
    head = removeatind(head,2);
    print(head);
    head = deleteval(head, 7);
    print(head);
    head = insertbeforehead(head, 10);
    print(head);
    head = insertaftertail(head, 11);
    print(head);
    head = insertatind(head, 2, 12);
    print(head);
    head = insertbeforeval(head, 12, 15);
    print(head);
}
