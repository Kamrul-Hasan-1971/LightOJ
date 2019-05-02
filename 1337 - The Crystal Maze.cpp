#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define output freopen("output.txt","wt", stdout)
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
char ara[501][501];
int visited[501][501];
int cost[501][501];
int cnt,rw,cmn;
vector<int>v;

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};


bool valid(int x,int y)
{
    if(x>=0 && x<rw && y>=0 && y<cmn && ara[x][y]!='#' && visited[x][y]==0)
    {
        return 1;
    }
    return 0;
}


int DFS(int qr3,int qr4)
{
    int i;
    visited[qr3][qr4]=1;
    if(ara[qr3][qr4]=='C')
    {
        cnt++;
    }
    for(i=0; i<4; i++)
    {
        int u=qr3+fx[i];
        int v=qr4+fy[i];


        if(valid(u,v))
        {
            DFS(u,v);
        }
    }

    return cnt;
}


int main()
{
    int tc,i,j,k,l,query,qr1,qr2;
    char ch;
    scanf("%d", &tc);
    for(i=0; i<tc; i++)
    {
        scanf("%d %d %d", &rw, &cmn, &query);
        for(j=0; j<rw; j++)
        {
            scanf("%s", ara[j]);
        }




        printf("Case %d:\n", i+1);


        for(l=0; l<query; l++)
        {
            scanf("%d %d",&qr1, &qr2);
            qr1=qr1-1;
            qr2=qr2-1;

            if(cost[qr1][qr2]!=0)
            {
                printf("%d\n",cost[qr1][qr2]);
            }
            else
            {
                memset(visited,0,sizeof (visited));
                int res=DFS(qr1,qr2);
                printf("%d\n",res);
                for(int o=0; o<rw; o++)
                {
                    for(int p=0; p<cmn; p++)
                    {
                        if(visited[o][p]==1)
                        {
                            cost[o][p]=res;
                        }
                    }
                }
                cnt=0;
            }
        }
    memset(cost,0,sizeof(cost));

    }
    return 0;
}
