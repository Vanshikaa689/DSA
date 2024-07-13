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
Node* detectintersection(Node* head1, Node* head2)
{
    //optimal approach 
    if(head1==NULL||head2==NULL)
    {
        return NULL;
    }
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2)
    {
        temp1 = (temp1==NULL)?head2:temp1->next;
        temp2 = (temp2==NULL)?head1:temp2->next;
    }
    return temp1;
    // Node* temp1 = head1;
    // Node* temp2 = head2;
    // int n1 = lengthofll(head1);
    // int n2 = lengthofll(head2);
    // int d = abs(n1-n2);
    // if(n1>n2)
    // {
    //     while(d--)
    //     {
    //         temp1 = temp1->next;
    //     }
    // }
    // else
    // {
    //     while(d--)
    //     {
    //         temp2 = temp2->next;
    //     }
    // }
    // while(temp1!=NULL&&temp2!=NULL)
    // {
    //     if(temp1==temp2)
    //     {
    //         return temp1;
    //     }
    //     temp1 = temp1->next;
    //     temp2 = temp2->next;
    // }
    // return NULL;
    // map<Node*, int>mpp;
    // Node* temp1 = head1;
    // Node* temp2 = head2;
    // while(temp1!=NULL)
    // {
    //     mpp[temp1] = 1;
    //     temp1 = temp1->next;
    // }
    // while(temp2!=NULL)
    // {
    //     if(mpp.find(temp2)!=mpp.end())
    //     {
    //         return temp2;
    //     }
    //     temp2 = temp2->next;
    // }
    // return NULL;
    //time complexity = O(N1*log(N))+O(N2*log(N))
    //space complexity = O(N1)orO(N2)

}
int main(){
    vector<int> arr1 = {3, 2, 5, 8, 7, 9, 10};
    vector<int> arr2 = {1, 2, 3, 8, 7, 9, 10};
    Node* head1 = convertarray2ll(arr1);
    Node* head2 = convertarray2ll(arr2);
    Node* head = detectintersection(head1, head2);
    print(head);
}
