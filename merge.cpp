// The efficient and popular Merge Sort
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>&c,int low,int  high,int mid)
{
    int n1=mid+1-low;
    int n2 = high - mid;
    int a[n1];
    int b[n2];
    for(int o = 0; o<n1;o++)
    {
        a[o] = c[low+o];
    }
    for(int o = 0;o<n2;o++)
    {
        b[o] = c[mid+1+o];
    }
    int i = 0,j=0,k=low;
    while(i<n1 and j<n2)
    {
        if(a[i]>b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
        }
    }
    while(i<n1)
    {
        c[k++]=a[i++];
    }
    while(j<n2)
    {
        c[k++] = b[j++];
    }
}

void mergesort(vector<int> &c,int low,int high)
{

    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(c,low,mid);
        mergesort(c,mid+1,high);
        merge(c,low,high,mid);
    }
    else
    {
        return;
    }
    
}

int main()
{
    int n;cin>>n;
    vector<int>c(n);
    for(int i = 0;i<n;i++)
    {
        cin>>c[i];
    }
    mergesort(c,0,n-1);
    for(int i = 0;i<n;i++)
    {
        cout<<c[i]<<' ';
    }
}