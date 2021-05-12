#include<bits/stdc++.h>

using namespace std;

int h[2];

void swap(int *i,int *j)
{
    int y;
    y=*i;
    *i=*j;
    *j=y;
}


void partition(int a[],int l,int r)
{
    int v=a[l];
    int i=l+1;
    while(i<=r)
    {
        if(a[i]<v)
        {
            swap(&a[i++],&a[l++]);
        }
        else if(a[i]>v)
        {
            swap(&a[i],&a[r--]);
        }
        else
        {
            i++;
        }
        
    }
    // swap(&a[l],&a[r]);
    // cout<<l<<' '<<r<<" pivot="<<a[l]<<'\n';
    h[0]=l;h[1]=r;
}

void sort(int a[],int l,int r)
{
    if(l<r)
    {
        
        int k=(r+l)/2;
        swap(&a[k],&a[l]);
        partition(a,l,r);
        sort(a,l,h[0]);
        sort(a,h[1]+1,r);
    }
}

int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<' ';   
    }

}