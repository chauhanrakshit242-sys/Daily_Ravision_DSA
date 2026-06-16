#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data =data;
        this->next=NULL;
    }
};
Node* createList(vector<int>& arr)
{
    Node * head=NULL;
    Node * tail =NULL;
    int n=arr.size();
         for(int i=0;i<n;i++)
         {
            Node * temp =  new Node(arr[i]);
            if(head==NULL)
            {
                head=tail=temp;
            }
            else
            {
                tail->next =temp;
                tail=temp;
            }
         }
         return head;
    }

void  print(Node * head)
{
    if(head==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node * root = createList(arr);
    print(root);
    return  0;
}