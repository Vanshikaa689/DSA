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
Node* removeduplicates(Node* head)
{
    Node* temp = head;
    Node* nextNode = temp->next;
    while(nextNode!=NULL)
    {
        if(nextNode->data==temp->data)
        {
            while(nextNode!=NULL&&nextNode->data == temp->data)
            {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete(duplicate);
            }
            temp->next = nextNode;
             if (nextNode != NULL) {
                nextNode->prev = temp;
            }
            temp = nextNode;
            if (nextNode != NULL) {
                nextNode = nextNode->next;
            }  
        }
        else 
        {
            temp = nextNode;
            if(nextNode!=NULL)
            {
                nextNode=nextNode->next;
            }
        }
    }
    return head;
    //time complexity = O(N)
    //space complexity = O(1)
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    Node* head = convertarray2ll(arr);
    head = removeduplicates(head);
    print(head);

}
