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

int parent[205];
vector<edgeStructure>edgeVector,temp;

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
    temp.clear();
    int ans = 0;
    sort(edgeVector.begin(),edgeVector.end());
    int sz=edgeVector.size();

    for(int i=0; i<sz; i++)
    {
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            temp.pb(edgeVector[i]);
            parent[uPr] = vPr;
            ans += edgeVector[i].w;
        }
    }
    edgeVector = temp ;
    int ini = findParent(1);
    for( int i = 1 ; i <= n ; i++)
    {
        if(findParent(i)!=ini)
        {
            return -1;
        }
    }
    return ans ;
}

int main()
{
    int  a,b,c,i,j=0,T,u,v,w;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++)
    {
        scanf("%d%d",&a,&b);
        edgeVector.clear();
        edgeStructure x ;
        printf("Case %d:\n",i);
        for( j = 1 ; j <= b ; j++ )
        {
            cin >> u>> v >> w ;
            x.u = u ;
            x.v = v ;
            x.w = w ;
            edgeVector.pb(x);
            printf("%d\n",kruskal(a));
        }
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1123
