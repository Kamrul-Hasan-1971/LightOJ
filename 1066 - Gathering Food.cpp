#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define         output             freopen("output.txt","wt", stdout)
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char ara[15][15];
int visited[15][15];
int level[15][15];
int z,indx1,indx2,dis;
char ch;
string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


bool isvalid(int x,int y)
{
    if(x>=0 && x<z && y>=0&&y<z  &&ara[x][y]!='#' && visited[x][y]==0  && ((ara[x][y]==ch) || (ara[x][y]=='.')))
    {
        return true;
    }
    else
    {
        return false;
    }
}



int BFS(int idx1,int idx2)
{
    //cout<<"-------------------------------------------:\n";
    queue<pii>q;
    for(int i=0; i<q.size(); i++)
    {
        q.pop();
    }
    visited[idx1][idx2]=1;
    level[idx1][idx2]=0;
    q.push(pii(idx1,idx2));

    while(!q.empty())
    {
        pii p=q.front();
        q.pop();

        int a=p.first;
        int b=p.second;



        for(int i=0; i<4; i++)
        {
            int xx=a+fx[i];
            int yy=b+fy[i];

            if(isvalid(xx,yy))
            {
                level[xx][yy]=level[a][b]+1;
                visited[xx][yy]=1;
                q.push(pii(xx,yy));
                if(ara[xx][yy]==ch)
                {
                    indx1=xx;
                    indx2=yy;
                    dis=level[xx][yy];
                    ara[xx][yy]='.';
                    return 0;
                }
            }
        }
    }
    return 1;


}

int main()
{

    int a,c,i,j,k,n,t=0,sum=0, l=0,w=0,x=0;
    cin>>a;

    for(j=0; j<a; j++)
    {
        sum=0;
        l=0;
        w=0;

        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));
        t=0;
        cin>>z;
        ch=s[z-1];

        for(k=0; k<z; k++)
        {
            cin>>ara[k];
            for(n=0; n<z; n++)
            {
                if(ara[k][n]!='.' && ara[k][n]!='#')
                {
                    l++;
                }
                if(ara[k][n]=='A')
                {
                    indx1=k;
                    indx2=n;
                    ara[indx1][indx2]='.';
                }
            }
        }
        int r=1;
        for(i=0; i<l-1; i++)
        {
            ch=s[r];
            w=BFS(indx1,indx2);
            r++;
            sum=sum+dis;
            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
            if(w==1)
            {
                printf("Case %d: Impossible\n", j+1);
                break;
            }

        }
        if(w==1)
        {
            continue;
        }
        printf("Case %d: %d\n", j+1, sum);
    }

    return 0;
}
