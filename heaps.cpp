// Heap Operations
#include<bits/stdc++.h>
using namespace std;
// How to access heap parent,child in array representation
int parent(int i)
{
    return (i-1)/2;
}
int right_child(int i)
{
    return 2*i+2;
}
int left_child(int i)
{
    return 2*i+1;
}
// Pulling a value upwards to its rightful place 
// according to heap property
void siftup(vector<int>&v,int i)
{
    
    if(v.size()==1)
    {
        return;
    }
    int t;
    while(i>0 and v[parent(i)]<v[i])
    {
        t = v[i];
        v[i] = v[parent(i)];
        v[parent(i)]=t;
        i = parent(i);
    }
}
// Dragging a value downwards to its rightful place
// according to heap property
void siftdown(vector<int>&v,int i)
{
    cout<<"LO\n";
    int max = i;
    int l = left_child(i);
    if(l<v.size() and v[l]>v[max])
    {
        max = l;
    }
    int r = right_child(i);
    if(r<v.size() and v[r]>v[max])
    {
        max = r;
    }
    if(i!=max)
    {
        int t = v[i];
        v[i] = v[max];
        v[max]=t;
        siftdown(v,max);
    }
}
// Insert heap
void insert(vector<int>&v,int p)
{
    v.push_back(p);
    siftup(v,v.size()-1);
}
// Extract the max i.e. root element from heap
int extract_max(vector<int>&v)
{
    int r = v[0];
    v[0] = v[v.size()-1];
    siftdown(v,0);
    return r;
}
// Remove ith element from heap
void remove(vector<int>&v,int i)
{
    v[i] = INT_MAX;
    siftup(v,i);
    extract_max(v);
}
// Output Heap
void display(vector<int>&v)
{
    for(int i = 0 ; i < v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}
int main()
{
    vector<int>l;
    int y;
    for(int i = 0;i<5;i++)
    {
        cin>>y;
        insert(l,y);
    }    
    display(l);
    insert(l,20);
    display(l);
    cout<<extract_max(l)<<endl;
    display(l);
}