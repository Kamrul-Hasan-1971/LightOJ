#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define         output             freopen("output.txt","wt", stdout)
vector<int>adj[20005];
//vector<int>cost[30005];
int visited[20005];
//int visited1[30005];
int b;

int BFS(int s)
{
    int cnt1=0,cnt2=0;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    cnt1++;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                if(visited[u]==1){
                    visited[v]=2;
                    cnt2++;
                }
                else{
                    visited[v]=1;
                    cnt1++;
                }
            }

        }
    }
    int u=max(cnt1,cnt2);
    cnt1=0,cnt2=0;
    return u;
}


int main()
{
    //output;
    int a,c,d,e,x=0,y=0,i,j,s,t,sum=0;
    scanf("%d", &a);
    for(i=0; i<a; i++)
    {
        scanf("%d", &b);
        for(j=0; j<b; j++)
        {
            scanf("%d %d", &c,&d);
            adj[c].push_back(d);
            adj[d].push_back(c);
        }

        for(int e=0;e<20001;e++){
            if(visited[e]==0 && adj[e].size()!=0){
                sum=sum+BFS(e);
            }
        }
        printf("Case %d: %d\n",i+1,sum);

        x=0;
        y=0;
        for(s=0; s<20001; s++)
        {
            adj[s].clear();
        }
        memset(visited,0,sizeof(visited));
        sum=0;
    }
    return 0;
}
