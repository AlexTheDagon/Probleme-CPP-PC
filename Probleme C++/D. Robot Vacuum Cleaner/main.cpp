#include <iostream>
#include <algorithm>
#define NM 100005
using namespace std;
string s[NM],act;
long long nrs,sol,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=0;j<s[i].size();++j)
        {
            if(s[i][j]=='s')s[i][j]='a';
            else s[i][j]='b';
        }
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;++i)act+=s[i];
    for(auto c:act)
    {
        if(c=='a')++nrs;
        else sol+=nrs;
    }
    cout<<sol;
    return 0;
}
