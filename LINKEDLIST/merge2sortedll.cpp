#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
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
Node* mergell(Node* head1, Node* head2)
{   
    if(head1==nullptr)
    {
        return head2;
    }
    if(head2==nullptr)
    {
        return head1;
    }
    Node* dummy = new Node(-1, NULL);
    Node* t1 = head1;
    Node* t2 = head2;
    Node* temp = NULL;
    if(head1->data<head2->data)
    {
        dummy->next = head1;
        t1 = t1->next;
        temp = head1;
    }
    else
    {
        dummy->next = head2;
        t2 = t2->next;
        temp = head2;
    }
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->data<t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1!=NULL)
    {
        temp->next = t1;
    }
    else if(t2!=NULL)
    {
        temp->next = t2;
    }
    Node* newhead = dummy->next;
    delete(dummy);
    return newhead;
    // vector<int> arr;
    // Node* temp = head1;
    // while(temp!=nullptr)
    // {
    //     arr.push_back(temp->data);
    //     temp = temp->next;
    // }
    // temp = head2;
    // while(temp!=nullptr)
    // {
    //     arr.push_back(temp->data);
    //     temp = temp->next;
    // }
    // sort(arr.begin(), arr.end());
    // Node* head = array2ll(arr);
    // return head;
    //time complexity = O(N1)+O(N2)+O(NlogN)+O(N)
    //space complexity = O(N)+O(N)
}
int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9};
    Node* head1 = array2ll(arr1);
    vector<int> arr2 = {2, 4, 6, 8, 10};
    Node* head2 = array2ll(arr2);
    Node* head = mergell(head1, head2);
    print(head);
}
