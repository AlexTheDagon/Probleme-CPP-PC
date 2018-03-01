#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 200005
using namespace std;
multiset<char> ms;
string s,s1;
int l,r,n,m,el;
vector<char> er[NM],add[NM];
char c;
int main()
{
    cin>>n>>m;
    cin>>s1;
    s="a"+s1;
    for(int i=1;i<=m;++i)
    {
        cin>>l>>r>>c;
        add[l].pb(c);
        er[r].pb(c);
    }
    for(int i=1;i<=n+el;++i)
    {
        for(auto cc:add[i-el])ms.insert(cc);
        if(ms.find(s[i])!=ms.end())
        {
            s[i]='*';
            ++el;
        }
        for(auto cc:er[i-el])ms.erase(cc);
    }
    for(int i=1;i<=n;++i)if(s[i]!='*')cout<<s[i];
    return 0;
}
