#include<bits/stdc++.h>
using namespace std;

#define pb push_back

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

int parent[505],ans[505],home,a;;

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

void kruskal(int n)
{
    initializeSet(n);
    sort(edgeVector.begin(),edgeVector.end());

    int anss = -1;
    int sz=edgeVector.size();

    for(int i=0; i<sz; i++)
    {
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            parent[uPr] = vPr;
            if(edgeVector[i].w > anss)
            {
                anss = edgeVector[i].w;
            }
        }
        for(int j = 0 ; j < a ; j++)
        {
            if(findParent(j)==findParent(home) && ans[j]==-1)
            {
                ans[j]=anss;
            }
        }
    }
}

int main()
{
    int  b,c,i,j=0,T,u,v,w;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++)
    {
        scanf("%d%d",&a,&b);
        for( j = 0 ; j <= a ; j++ ) ans[j]=-1;
        edgeVector.clear();
        edgeStructure x ;
        for( j = 0 ; j < b ; j++ )
        {
            cin >> u>> v >> w ;
            x.u = u ;
            x.v = v ;
            x.w = w ;
            edgeVector.pb(x);
        }
        scanf("%d",&home);
        kruskal(a);
        printf("Case %d:\n",i);
        for( j = 0 ; j< a ; j++)
        {
            if(j==home)printf("0\n");
            else if(ans[j]==-1) printf("Impossible\n");
            else printf("%d\n",ans[j]);
        }
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1002
