#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>v[102];
vector<ll>cost[102];

ll distanc[102];

struct node
{
    ll u,w;
    node(ll a,ll b)
    {
        u=a;
        w=b;
    }
    bool operator <(const node &p)const
    {
        return w>p.w;
    }
};


void Dijsktra()
{
    for(ll i=0; i<102; i++)
    {
        distanc[i]=9999999999;
    }

    priority_queue<node>pq;
    pq.push(node(1,0));

    distanc[1]=0;

    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        ll u=top.u;

        for(ll j=0; j<v[u].size(); j++)
        {
            ll x=v[u][j];

            if(cost[u][j]+distanc[u]<distanc[x])
            {
                distanc[x]=cost[u][j]+distanc[u];
                pq.push(node(x,distanc[x]));
            }
        }
    }

}



int main()
{
    ll a,b,c,d,e,f,i,j;
    cin>>a;

    for(i=0; i<a; i++)
    {
        cin>>b>>c;
        for(j=0; j<c; j++)
        {
            cin>>d>>e>>f;
            v[d].push_back(e);
            v[e].push_back(d);
            cost[d].push_back(f);
            cost[e].push_back(f);
        }
        Dijsktra();

        if(distanc[b]==9999999999)
        {
            printf("Case %lld: Impossible\n",i+1);
        }
        else
        {
            printf("Case %lld: %lld\n",i+1,distanc[b]);
        }
        for(j=0; j<102; j++)
        {
            v[j].clear();
            cost[j].clear();
        }
    }
    return 0;
}
