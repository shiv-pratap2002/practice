// Heap Contruction + Sorting
#include<bits/stdc++.h>

using namespace std;
//math to reach indices
int parent(int i)
{
    if(i==0)
    {
        return 0;
    }
    return (i-1)/2;
}
int leftchild(int i)
{
    return 2*i+1;
}
int rightchild(int i)
{
    return 2*(i+1);
}
// iterative method to siftup 
void siftup(int i,vector<int>&c)
{
    while(i>=1 and c[parent(i)]<c[i])
    {
        swap(c[parent(i)],c[i]);
        i = parent(i);
    }
}
// choose the highest path always and sift down from there untill i reaches a leaf 
void siftdown(int i, vector<int>&c,int size)
{
    int maxind = i;
    // int n = c.size();
    int l = leftchild(i),r =rightchild(i);
    if(l<size and c[l]>c[maxind])
    {
        maxind = l;
    }
    if(r<size and c[r]>c[maxind])
    {
        maxind = r;
    }
    if(i!=maxind)
    {
        swap(c[i],c[maxind]);
        siftdown(maxind,c,size);
    }
}
// insert at leaf then sift it up to make the structure satisfy heap prop
void insert(int p,vector<int>&c)
{
    c.push_back(p);
    int m = c.size()-1;
    siftup(m,c);
}

void out(vector<int>c)
{
    for(int i = 0;i<c.size();i++)
    {
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}
// output max element then replace it with 2nd highest number
int extract_max(vector<int>&c)
{
    int result = c[0];
    int size = c.size();
    c[0]=c[size-1];
    siftdown(0,c,size);
    return result;
}
// change priority of element at index i to p and maintain heap prop
void change_priority(int i,int p,vector<int>&c)
{
    int old = c[i];
    c[i] = p;
    if(p<old)
    {
        siftup(i,c);
    }
    else
    {
        siftdown(i,c,c.size());
    }
}
// permute the array to reach closest heap prop state...sounds time-consuming
void build_heap(vector<int>&a)
{
    int n = a.size()-1;
    for(int i=n/2;i>=0;i--)
    {
        siftdown(i,a,n+1);
    }
    cout<<"The Heap -\n";
    out(a);
}
// simple swappin', a clean O(nlogn). Still QuickSort fazzterrr 
void heap_sort(vector<int>&a)
{
    build_heap(a);
    for(int i=a.size()-1;i>=1;i--)
    {
        swap(a[0],a[i]);
        siftdown(0,a,i);
    }
}
int main()
{
    // vector<int>heap;
    // insert(2,heap);
    // insert(24,heap);
    // insert(12,heap);
    // out(heap);
    // insert(9,heap);
    // insert(42,heap);
    // insert(1,heap);
    // out(heap);
    // extract_max(heap);
    // out(heap);    
    int n;
    cout<<"Size of array = ";
    cin>>n;
    vector<int>a(n);
    cout<<"The Array -\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heap_sort(a);
    cout<<"Sorted Array - \n";
    out(a);
}