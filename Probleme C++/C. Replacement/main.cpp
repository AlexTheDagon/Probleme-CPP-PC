#include <iostream>

using namespace std;
string s,ss;
int n,m,p,gr,pt,s1,s2;
char c;
int main()
{
    cin>>n>>m>>ss;
    s='a'+ss;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='.')
        {
            ++pt;
            if(i==n || s[i+1]!='.')++gr;
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>p>>c;
        s1=(s[p]=='.');
        s2=(c=='.');
        if(s1!=s2)
        {
            if(s[p-1]=='.' && s[p+1]=='.' && !s2)gr++;
			if(s[p-1]=='.' && s[p+1]=='.' && s2)gr--;
			if(s[p-1]!='.' && s[p+1]!='.' && !s2)gr--;
			if(s[p-1]!='.' && s[p+1]!='.' && s2)gr++;
            if(s1)--pt;
            else ++pt;
        }
        s[p]=c;
        cout<<pt-gr<<'\n';
    }
    return 0;
}
