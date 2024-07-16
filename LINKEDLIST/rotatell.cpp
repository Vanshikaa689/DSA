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

Node* rotate(Node* head, int k)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node* temp=head;
    Node* temp1 = head;
    int len = lengthofll(head);
    k = k%len;
    if(k==0)
    {
        return head;
    }
    int ind = len-k;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = head;
    while(ind!=0)
    {
        temp1 = temp1->next;
        ind--;
    }
    head = temp1->next;
    temp1->next = NULL;
    return head;

}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7};
    Node* head = convertarray2ll(arr);
    head = rotate(head, 3);
    print(head);
}
