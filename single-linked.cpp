// some basic single linked list operations
#include <iostream>

using namespace std;
// creating a node
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertathead(node *&head,int val)
{
    node *n=new node(val);
    n->next=head;
    head=n;
}
void insertattail(node *&head,int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    else{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    }
}
void out(node *head)
{
    node *temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp->next!=NULL);
    cout<<temp->data<<'\n';
}
void reverse(node *&head)
{
    node *curr = head;
    node *prev = nullptr;
    node *next =nullptr;
    while(curr != nullptr)
    {
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    node *head=NULL;
    insertattail(head,1);
    insertathead(head,5);
    out(head);
    cout<<'\n';
    insertattail(head,7);
    insertattail(head,3);
    insertathead(head,4);
    out(head);
    reverse(head);
    out(head);
}





