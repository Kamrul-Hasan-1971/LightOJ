#include<bits/stdc++.h>
using namespace std;

#define           pii                pair < double, double>
#define           pb                 push_back

map<pii,int>mp;

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

int parent[110];

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

    int sz=edgeVector.size();
    int ans=0;

    for(int i=0;i<sz;i++){
        int uPr = findParent(edgeVector[i].u);
        int vPr = findParent(edgeVector[i].v);
        if(uPr != vPr)
        {
            parent[uPr] = vPr;
            ans+=edgeVector[i].w;
        }
    }
    return ans;
}

int main()
{
    int  node,u,v,cost ,a,b,c,d,e,f,i,j=0,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    scanf("%d",&T);
    for( i = 1 ; i <= T ; i++)
    {
        edgeVector.clear();
        scanf("%d",&node);
        while(1)
        {
            scanf("%d%d%d",&u,&v,&cost);
            if(u==0 && v==0 && cost == 0 ) break;

            edgeStructure xx ;
            xx.u = u ;
            xx.v = v ;
            xx.w = cost ;
            edgeVector.pb(xx);
        }
        sort(edgeVector.begin(),edgeVector.end());
        int res1 = kruskal(node);
        reverse(edgeVector.begin(),edgeVector.end());
        int res2 = kruskal(node);
        res1+=res2;
        if(res1%2) printf("Case %d: %d/2\n",i,res1);
        else printf("Case %d: %d\n",i,res1/2);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1029
