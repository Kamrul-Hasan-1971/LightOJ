#include<bits/stdc++.h>
using namespace std;

#define           pb                 push_back

vector<int>v;

int fun( int n )
{
    stack<int>stk ;
    int i = 0 , ans = 0 ;
    while( i < n )
    {
        if(stk.empty() || v[stk.top()] <= v[i] )
        {
            stk.push(i++);
        }
        else
        {
            int x = stk.top();
            stk.pop();
            int area = v[x] * (stk.empty()? i : i - stk.top() - 1) ;
            ans = max( ans , area );
        }
    }
    while(!stk.empty())
    {
        int x = stk.top();
        stk.pop();
        int area = v[x] * (stk.empty()? i : i - stk.top() - 1) ;
        ans = max( ans , area );
    }
    return ans ;
}

int main()
{
    int  a,b,i,j,T;
    scanf("%d",&T);

    for( i = 1 ; i <= T ; i++ )
    {
        v.clear();
        scanf("%d",&a);
        for( j = 1 ; j <= a ; j++ )
        {
            scanf("%d",&b);
            v.pb(b);
        }
        printf("Case %d: %d\n",i,fun(a));
    }

    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1083
