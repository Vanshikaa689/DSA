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
    if(arr.empty())
    {
        return NULL;
    }
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
Node* deleteall(Node* head, int num)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == num)
        {
            Node* nnode = temp;
            if(temp==head)
            {
                head = temp->next;
                if(head!=NULL)
                {
                temp->next->prev = nullptr;
                }
                temp = temp->next;
                
            }
            else if(temp->next ==NULL)
            {
                temp->prev->next = NULL;
                temp = NULL;
            
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
                
            }
            delete(nnode);
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> arr = {8, 2, 5, 8, 7, 4, 8};
    Node* head = convertarray2ll(arr);
    head = deleteall(head, 8);
    print(head);
}
