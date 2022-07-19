#include<bits/stdc++.h>
using namespace std;

vector<int> longest(vector<int> a, vector<int> b) {
    int m = a.size(),n=b.size();
    vector<int>p;
    int v[m+1][n+1];
    for(int i = 0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(i==0 or j==0)
            {
                v[i][j]=0;
            }
            else if(a[i-1] == b[j-1])
            {
                v[i][j] = 1+v[i-1][j-1];                
            }
            else {
            v[i][j] =max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    int i = m,j = n;

    while(i> 0  and j> 0)
    {
        if(a[i-1]==b[j-1])
            {
                p.push_back(a[i-1]);
                j--;i--;
            }
        else if(v[i-1][j]>v[i][j-1])
            {
                i--;
            }
        else 
            {
                j--;
            }
    }
    reverse(p.begin(),p.end());
    return p;
}
int main()
{
    // Boilerplate for longest common questions.
    return 0;
}