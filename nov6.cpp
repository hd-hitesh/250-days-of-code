#include<bits/stdc++.h>
using namespace std;
#define fori(i,j,n) for(int i=j;i<n;i++)
#define ford(i,j,n) for(int i=j;i>=n;i--)
#define ll long long int

bool dfs(vector<vector<int>> v,int find,vector<int> &visited,int ele,vector<int> &ret)
{
    if(ele==find)
    {
        return 1;
    }
    visited[ele]=1;
    fori(i,0,v[ele].size())
    {
        if(v[ele][i]&&visited[v[ele][i]]==0)
        {
            ret.push_back(v[ele][i]);
            if(dfs(v,find,visited,v[ele][i],ret))
            return 1;
            ret.pop_back();
        }
    }
    return 0;
}
void testcase()
{
    int n,q;cin>>n>>q;
    int wt[n],query[q][2];
    fori(i,0,n)
    cin>>wt[i];
    vector<vector<int>> v(n);
    fori(i,1,n)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    fori(i,0,q)
    {
        cin>>query[i][0]>>query[i][1];
    }
    // cout<<"let's begin ";
    fori(i,0,q)
    {
        vector<int> v1={0},v2={0};
        vector<int> visited1(n,0),visited2(n,0);
        dfs(v,query[i][0]-1,visited1,0,v1);
        dfs(v,query[i][1]-1,visited2,0,v2);
        long long sum=0;
        fori(i,0,v1.size())
        {
            sum=(sum+(long)wt[v1[i]]*(long)wt[v2[i]])%4294967296;
        }
        cout<<sum<<endl;
    }
}

int main()
{
    testcase();
}