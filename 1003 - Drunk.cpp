#include<bits/stdc++.h>
using namespace std;
#define           all(v)             v.begin(),v.end()
#define           zero(a)            memset(a,0,sizeof a)


string s1, s2 ;
map< string, int > mp ;
vector<int>v[20005];
int visited[20005] , chk ;

void fun(int x)
{
    visited[x]=1;
    int i,l = v[x].size();
    for( i = 0 ; i < l ; i++ )
    {
        int y = v[x][i] ;
        if( !visited[y] ) fun(y);
        else if( visited[y] == 1) {
            chk = 1 ;
            return ;
        }
    }
    visited[x]=2;
}

int main()
{
    int T, i, n, j;
    scanf("%d", &T ) ;
    for( i = 1 ; i <= T ; i++ )
    {
        mp.clear(); zero(visited);
        int cnt = 1 ; chk = 0 ;
        scanf("%d",&n);
        for( j = 0  ; j < n ; j++ )
        {
            cin >> s1 >> s2 ;
            if( mp.count(s1)==0) mp[s1]=cnt++;
            if( mp.count(s2)==0) mp[s2]=cnt++;
            v[mp[s2]].emplace_back(mp[s1]);
        }
        for( j = 1 ; j < cnt ; j++ )
        {
            if(!visited[j]) fun(j);
            if(chk) break;
        }
        if( chk == 0) printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);
        for( j = 1 ; j<cnt ; j++) v[j].clear();
    }
    return 0 ;
}
//http://www.lightoj.com/volume_showproblem.php?problem=1003
