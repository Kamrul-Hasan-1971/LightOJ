#include <bits/stdc++.h>
using namespace std;

vector<int>v[105];
int visited[105];
int distance1[105];
int distance2[105];
int indx;

int BFS(int x,int level[])
{
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    int i,mx=0;
    queue<int>q;
    q.push(x);
    visited[x]=1;
    level[x]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(i=0;i<v[u].size();i++){
            int x=v[u][i];
            if(visited[x]==0){

                visited[x]=1;
                level[x]=level[u]+1;
                q.push(x);
            }
        }
    }

    for(i=0;i<102;i++){
        if(level[i]>mx){
            mx=level[i];
            indx=i;
        }
    }
}

int main()
{
    int a,b,c,i,j,e,f,g,h,s,n,mx1=0,sum=0;
    scanf("%d", &a);
    for(i=0;i<a;i++){
        scanf("%d %d", &b, &c);
        for(j=0;j<c;j++){
           scanf("%d %d",&e, &f);
            v[e].push_back(f);
            v[f].push_back(e);
        }
        scanf("%d %d", &g, &h);
        BFS(g,distance1);
        BFS(h,distance2);
        for(j=0;j<b;j++){
            sum=distance1[j]+distance2[j];
            if(sum>mx1){
                mx1=sum;
            }
        }
        printf("Case %d: %d\n", i+1, mx1);

        for(j=0;j<b;j++){
            v[j].clear();
        }
        sum=0,mx1=0;

    }
    return 0;
}
