#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define         output             freopen("output.txt","wt", stdout)
vector<int>adj[30005];
vector<int>cost[30005];
int visited[30005];
int visited1[30005];
int b;

int BFS(int s)
{
    int maxDis,nodeIdx;
    memset(visited,-1,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==-1)
            {
                q.push(v);
                visited[v]=visited[u]+ cost[u][i];
            }

        }
    }
    for(int i=0; i<q.size(); i++)
    {
        q.pop();
    }
    maxDis=0;
    nodeIdx;

    for(int i=0; i<b; i++)
    {
        if(visited[i]>maxDis)
        {
            maxDis=visited[i];
            nodeIdx=i;
        }
    }
    return nodeIdx;
}


void BFS2(int s)
{
    memset(visited1,-1,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited1[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited1[v]==-1)
            {
                q.push(v);
                visited1[v]=visited1[u]+ cost[u][i];
            }

        }
    }
    return ;
}

int main()
{
    //output;
    int a,c,d,e,x,y,i,j,s,t;
    scanf("%d", &a);
    for(i=0; i<a; i++)
    {
        scanf("%d", &b);
        for(j=0; j<b-1; j++)
        {
            scanf("%d %d %d", &c,&d,&e);
            adj[c].push_back(d);
            adj[d].push_back(c);
            cost[c].push_back(e);
            cost[d].push_back(e);

        }
        x=BFS(0);
        y=BFS(x);
        BFS2(y);
        printf("Case %d:\n",i+1);
        for(int r=0; r<b; r++)
        {
            t=max(visited[r],visited1[r]);
            printf("%d\n",t);
        }
        for(s=0; s<b; s++)
        {
            adj[s].clear();
            cost[s].clear();
        }
    }
    return 0;
}
