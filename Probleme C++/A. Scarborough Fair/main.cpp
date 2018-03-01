#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int n,l,r,m;
char c1,c2;
int main()
{
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=m;++i)
    {
        cin>>l>>r>>c1>>c2;
        for(int j=l-1;j<r;++j)
            if(s[j]==c1)s[j]=c2;
    }
    cout<<s;
    return 0;
}
