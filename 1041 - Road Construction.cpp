#include<bits/stdc++.h>
using namespace std;

#define pb push_back

string s1, s2, s3;
map<string,int>mp;
vector<int>vec[110];

struct edgeStructure
{
    int u;
    int v;
    int w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

int parent[110],visited[110],cnt2;

vector<edgeStructure>edgeVector;


void initializeSet(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}

int findParent(int x)
{
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

int kruskal(int n)
{
    initializeSet(n);
    sort(edgeVector.begin(),edgeVector.end());

    int ans = 0;
    int sz=edgeVector.size();

    for(int i=0; i<sz; i++)
    {
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            parent[uPr] = vPr;
            ans += edgeVector[i].w;
        }
    }
    return ans;
}

void dfs(int x)
{
    visited[x]=1;
    cnt2--;
    int i, sz = vec[x].size();
    for( i =0 ; i < sz ; i++)
    {
        int m = vec[x][i];
        if(visited[m]==0)
        {
            dfs(m);
        }
    }
}

int main()
{
    int  a,b,c,i,j=0,T;
    cin>>T;
    for( j = 1 ; j <= T ; j++)
    {
        cin >> b ;
        int cnt1 = 1 ;
        for( i = 0 ; i < b ; i++ )
        {
            cin >> s1>> s2 >> c ;
            if(!mp.count(s1))
            {
                mp[s1]=cnt1;
                cnt1++;
            }
            if(!mp.count(s2))
            {
                mp[s2]=cnt1;
                cnt1++;
            }
            edgeStructure x ;
            x.u = mp[s1];
            x.v = mp[s2];
            x.w = c ;
            edgeVector.pb(x);
            vec[x.u].pb(x.v);
            vec[x.v].pb(x.u);
        }
        cnt2 = cnt1-1;
        dfs(1);
        if(cnt2>0)
            printf("Case %d: Impossible\n",j);
        else
            printf("Case %d: %d\n",j,kruskal(cnt1-1));
        for( i = 1 ; i < cnt1 ; i++)
        {
            vec[i].clear();
            visited[i]=0;
        }
        edgeVector.clear();
        mp.clear();
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1041
