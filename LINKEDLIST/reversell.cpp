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
Node* reversell(Node* head)
{   
    //using stack
    stack<int> st;
    if(head==NULL||head->next == NULL)
    {
        return head;
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp= temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        temp->data = st.top();
        st.pop();
        temp= temp->next;
    }
    return head;
    //brute force
    // if(head==NULL||head->next ==NULL)
    // {
    //     return head;
    // }
    // Node* temp = head;
    // Node* prev = NULL;
    // Node* front = NULL;
    // while(temp!=NULL)
    // {
    //     front = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = front;
    // }
    // return prev;
    //recursion
    // if(head==nullptr || head->next==nullptr)
    // {
    //     return head;
    // }
    // Node* newhead = reversell(head->next);
    // Node* front = head->next;
    // front->next = head;
    // head->next = NULL;
    // return newhead;
    //time complexity = O(N)
    //spcae complexity = O(N)
}
int main()
{
    vector<int> arr = {3, 2, 5, 8, 7};
    Node* head = convertarray2ll(arr);
    head = reversell(head);
    print(head);

}
