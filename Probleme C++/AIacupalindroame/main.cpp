#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream in("aiacupalindroame.in");
ofstream out("aiacupalindroame.out");
vector<int> v[100005];
int n,q,x,y,poz[100005],frg;
string s;
struct trie
{
    trie *fiu[30];
    int fr;
    trie()
    {
        fr=++frg;
        memset(fiu,0,sizeof(fiu));
    }
};
void dfs(int nod,trie *t)
{
    poz[nod]=t->fr;
    for(auto i:v[nod])
    {
        int delta=s[i-2]-'a';
        if(t->fiu[delta]==NULL)
            t->fiu[delta]=new trie;
        dfs(i,t->fiu[delta]);
    }
}
trie *t=new trie;
int main()
{
    in>>n>>q;
    for(int i=2;i<=n;++i)
    {
        in>>x;
        v[x].pb(i);
    }
    in>>s;
    dfs(1,t);
    for(int i=1;i<=q;++i)
    {
        in>>x>>y;
        if(poz[x]==poz[y])out<<"1";
        else out<<"0";
        out<<'\n';
    }
    return 0;
}
