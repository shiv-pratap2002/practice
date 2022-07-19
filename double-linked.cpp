// Common operations on Double Linked List
#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
node *head=NULL;
node *tail=NULL;
void pushfront(int key)
{
    node *n=new node(key);
    n->next=head;
    // head->prev=n;
    head=n;
    tail=n->next;
    
}
void pushback(int key)
{
    node *n= new node(key);
    if(tail==NULL)
    {
        head=n;
        tail=n;
        return;
    }
    n->prev=tail;
    tail->next=n;
    tail=n;
}
void popfront()
{
    if(head==NULL)
    {
        cout<<"Whatcha doin";
    }
    else
    {
        (head->next)->prev=NULL;
        head=(head->next);
    }
}

void popback()
{
    if(head==NULL)
    {
        cout<<"Empty list";
    }
    if (head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        (tail->prev)->next=NULL;
        tail=tail->prev;
    }
    
}
void topback()
{
    if(tail==NULL)
    {
        cout<<"NONE: ERROR";
    }
    else
    {
        cout<<to_string(tail->data)<<'\n';
    }
}
void topfront()
{
    if(head==NULL)
    {
        cout<<"NONE: ERROR";
    }
    else
    {
        cout<<to_string(head->data)<<'\n';
    }
}
void output()
{
    node *n=head;
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    while(n->next!=NULL)
    {
        cout<<n->data<<' ';
        n=n->next;
    }
    cout<<n->data<<'\n';
}
int main()
{
    // pushfront(9);
    // pushfront(10);
    // output();
    pushback(11);
    // pushback(12);
    node v(9);
    output();
    popback();
    output();
    // topfront();
    // topback();
    // cout<<head->data;
}
