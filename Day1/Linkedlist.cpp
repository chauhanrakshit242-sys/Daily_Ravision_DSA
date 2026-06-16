#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data =data;
        this->next=NULL;
    }
};
void print( Node * head)
{
    if(head==NULL)
    {
       return;
    }
    Node * temp =head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
};
 void reverse(Node * head)
 {
    if(head==NULL)
    {
        return ;
    }
    reverse(head->next);
    cout<<head->data<<" ";
 } 
 void add(Node* root , int& sum)
 {
    if(root==NULL)
    {
       return;
    }
    sum = sum +root->data;
    add(root->next,sum);
 }
int main()
{
    int n;
    cout<<"Enter the Number of element in list:";
    cin>>n;
    Node * head =NULL;
    Node * tail =NULL;
    if(n==0)
    {
        cout<<"Invalid Input";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int val;
            cin>>val;
            Node * temp = new Node(val);
            if(head==NULL)
            {
                head=tail=temp;
            }
            else
            {
                tail->next =temp;
                tail = temp;
            }
        }
    }
    cout<<"Original List :"<<endl;
    print(head);
    cout<<endl;
    cout<<"Reverse List :"<<endl;
    reverse(head);
    int sum=0;
    add(head,sum);
    cout<<endl;
    cout<<"Sum of ALL eleemnt in linked list:"<<sum;
    return  0;
}