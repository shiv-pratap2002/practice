// Binary tree creation an traversals
#include<bits/stdc++.h>

using namespace std;

class tree
{
    public:
    int val;
    tree *left;
    tree *right;
    tree(int v)
    {
        val=v;
        left=NULL;
        right=NULL;
    }
};

void insert_at(tree *root, int val)
{
    tree *t;
    if(root==NULL)
    {
        t=new tree(val);
        root=t;
    }
    else
    {
        if(root->left==NULL)
        {
            t=new tree(val);
            root->left=t;
        }
        else
        {
            t=new tree(val);
            root->right=t;
        }
        
    }
    
}

void preorder(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    else
    {
        cout<<(r->val)<<' ';
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    else
    {
        postorder(r->left);
        postorder(r->right);
        cout<<(r->val)<<' ';
    }
}
void inorder(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    else
    {
        inorder(r->left);
        cout<<(r->val)<<' ';
        inorder(r->right);
    }
}
int height(tree *r)
{
    if(r==NULL)
    {
        return 0;
    }
    else{
    return max(1+height(r->left),1+height(r->right));
    }
}
vector<int> lvl_order(tree *r)
{
    vector<int>c(height(r),0);
    if(r==NULL)
    {
        return c;
    }
    queue<tree *>q;
    q.push(r);    
    c.push_back(r->val);
    while(true)
    {
        int n=q.size();
        if(n==0)
        {
            return c;
        }
        while(n>0)
        {
            tree *p=q.front();
            q.pop();
            if(p->left!=NULL)
            {
                q.push(p->left);
                c.push_back((p->left)->val);

            }
            if(p->right!=NULL)
            {
                q.push(p->right);
                c.push_back((p->right)->val);
            }

            n--;
        }
    }
    
}

int main()
{
    tree *root=new tree(2);
    insert_at(root,3);
    insert_at(root->left,4);
    insert_at(root,4);
    insert_at(root->left,6);
    insert_at(root->left->left,342);
    insert_at(root->left->right,2);
    inorder(root);
    cout<<'\n';
    preorder(root);
    cout<<'\n';
    postorder(root);
    cout<<'\n';
    vector<int> l = lvl_order(root);
    for(int i=0;i<l.size();i++)
    {
        cout<<l[i]<<' ';
    }

}