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

int parent[55],sum;
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
    int ini = findParent(1);
    for(int i = 1 ; i <= n ; i++ )
    {
        if(ini!=findParent(i))
        {
            return sum+1;
        }
    }
    return ans ;
}

int main()
{
    int  a,b,c,i,j=0,T,u,v,w,k;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++)
    {
        edgeVector.clear();
        sum = 0 ;
        scanf("%d",&a);
        for( j = 1 ; j <= a ; j++ )
        {
            for( k = 1 ; k <= a ; k++ )
            {
                scanf("%d",&b);
                if(j!=k && b!=0)
                {
                    edgeStructure x ;
                    x.u = j ;
                    x.v = k ;
                    x.w = b ;
                    edgeVector.pb(x);
                }
                sum += b ;
            }
        }
        printf("Case %d: %d\n",i,sum-kruskal(a));

    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1040
