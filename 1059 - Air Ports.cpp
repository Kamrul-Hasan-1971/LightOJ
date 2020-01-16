#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define           zero(a)            memset(a,0,sizeof a)

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

int parent[10004],id,cnt1,c;
vector<edgeStructure>temp;
vector<int>vec[10004] ;

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

int kruskal(int n,vector<edgeStructure>&edgeVector)
{
    int ans = 0;
    sort(edgeVector.begin(),edgeVector.end());
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
    return ans ;
}

int visited[10004];
void dfs(int x)
{
    visited[x]=id;
    int i, sz= vec[x].size();
    for( i = 0 ; i < sz ; i++ )
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
    int  a,b,i,j=0,T,u,v,w,k;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++)
    {
        zero(visited);
        temp.clear();
        cnt1 = 0 ;
        id = 0;
        int sum = 0 ;
        scanf("%d%d%d",&a,&b,&c);
        initializeSet(a);
        for( j = 1 ; j <= b ; j++ )
        {
            scanf("%d%d%d",&u,&v,&w);
            edgeStructure x ;
            x.u = u ;
            x.v = v ;
            x.w = w ;
            if(w<c)
            {
                vec[u].pb(v);
                vec[v].pb(u);
                temp.pb(x);
            }
        }
        for( j = 1 ; j<= a ; j++)
        {
            if(visited[j]==0)
            {
                id++;
                dfs(j);
            }
            vec[j].clear();
        }
        vector<edgeStructure>edgeVector[id+2];
        for( j = 0 ; j < temp.size() ; j++ )
        {
            edgeVector[visited[temp[j].u]].pb(temp[j]);
        }
        for( j = 1 ; j <= id ; j++)
        {
            sum+=kruskal(a,edgeVector[j]);
            sum+=c;
            edgeVector[j].clear();
        }
        printf("Case %d: %d %d\n",i,sum,id);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1059
