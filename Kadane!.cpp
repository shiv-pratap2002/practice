// This is C++ implemnentation  of
// Kadane's Algorithm
#include<bits/stdc++.h>

using namespace std;
// to find largest contiguous sum in given array, 
// damn so simple
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=a[0],csum=0;
    for(int i=0;i<n;i++)
    {
        csum+=a[i];
        if(csum>sum)
        {
            sum=csum;
        }
        if(csum<0)
        {
            csum=0;
        }
    }
    cout<<sum<<endl;
}