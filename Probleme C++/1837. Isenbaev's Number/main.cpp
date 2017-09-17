#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define NM 310
using namespace std;
map<string,int> m;
int n,p,viz[NM],fol[NM],val[NM];
vector<int> v[305];
vector<string> s;
string s1,s2,s3;
queue<int> q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s1>>s2>>s3;
        if(m.find(s1)==m.end())m[s1]=++p;
        if(m.find(s2)==m.end())m[s2]=++p;
        if(m.find(s3)==m.end())m[s3]=++p;
        v[m[s1]].pb(m[s2]);
        v[m[s1]].pb(m[s3]);
        v[m[s2]].pb(m[s1]);
        v[m[s2]].pb(m[s3]);
        v[m[s3]].pb(m[s1]);
        v[m[s3]].pb(m[s2]);
        if(fol[m[s1]]==0)
        {
            fol[m[s1]]=1;
            s.pb(s1);
        }
        if(fol[m[s2]]==0)
        {
            fol[m[s2]]=1;
            s.pb(s2);
        }
        if(fol[m[s3]]==0)
        {
            fol[m[s3]]=1;
            s.pb(s3);
        }
    }
    q.push(m["Isenbaev"]);
    viz[m["Isenbaev"]]=1;
    val[m["Isenbaev"]]=0;
    while(!q.empty())
    {
        for(auto i:v[q.front()])
        {
            if(!viz[i])
            {
                viz[i]=1;
                val[i]=val[q.front()]+1;
                q.push(i);
            }
        }
        q.pop();
    }
    sort(s.begin(),s.end());
    for(auto ss:s)
    {
        if(val[m[ss]]!=0 || ss=="Isenbaev")cout<<ss<<" "<<val[m[ss]]<<'\n';
        else cout<<ss<<" undefined"<<'\n';
    }
    return 0;
}
