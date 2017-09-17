#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("text3.in");
ofstream out("text3.out");
string s;
vector <string> v,sol;
int act=-1,maxx,ind;
int ultlit[150];
int curent[150];
int venit[20005];
int main()
{
    while(in>>s)
    {
        ++act;
        v.pb(s);
        if(ultlit[s[s.size()-1]]<(ultlit[s[0]]+1))
        {
            ultlit[s[s.size()-1]]=ultlit[s[0]]+1;
            venit[act]=curent[s[0]];
            curent[s[s.size()-1]]=act;
        }
    }
    out<<v.size()<<'\n';
    for(int i=1;i<=140;++i)
    {
        if(ultlit[i]>=maxx)
        {
            maxx=ultlit[i];
            ind=curent[i];
        }
    }
    out<<v.size()-maxx<<'\n';
    while(maxx)
    {
        --maxx;
        sol.pb(v[ind]);
        ind=venit[ind];
    }
    for(int i=sol.size()-1;i>=0;--i)out<<sol[i]<<'\n';
    return 0;
}
