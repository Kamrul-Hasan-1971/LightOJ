#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

int main()
{
    ll a,b,c,i,p,q,r,s,d,e;
    char ch;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>ch>>c>>ch>>d>>ch>>e;
        cin>>p>>ch>>q>>ch>>r>>ch>>s;
        p=binaryToDecimal(p);
        q=binaryToDecimal(q);
        r=binaryToDecimal(r);
        s=binaryToDecimal(s);
        if(b==p && c==q && r==d && e==s){
            printf("Case %lld: Yes\n",i+1);
        }
        else{
            printf("Case %lld: No\n",i+1);
        }
    }
    return 0;
}
