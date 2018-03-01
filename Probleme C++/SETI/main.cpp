#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#define NM 64*2050
#define LM 25
using namespace std;
ifstream in("seti.in");
ofstream out("seti.out");
char C[NM],P[30];
int n,act,tt,m;
string s;
unordered_map <string,int> mp;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>C+act;
        act+=64;
    }
    n=strlen(C+1);
    for(int i=1;i<=n;++i)
    {
        s="";
        for(int j=i;j<i+20 && j<=n;++j)
        {
            s+=C[j];
            if(mp.find(s)!=mp.end())mp[s]++;
            else mp[s]=1;
        }
    }
    in>>tt;
    while(tt--)
    {
        in>>s;
        if(mp.find(s)==mp.end())out<<"0"<<'\n';
        else out<<mp[s]<<'\n';
    }
    return 0;
}
