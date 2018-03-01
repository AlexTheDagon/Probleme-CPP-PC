#include <iostream>
#include <bits/stdc++.h>
#define NM 100005
#define LM 35
using namespace std;
ifstream in("fbsearch.in");
ofstream out("fbsearch.out");
struct trie
{
    int ind=0,val=0,maxval=0;
    trie *fiu[35]={0};
};
///adaugarea utilizatorilor
void adauga(char *p,trie *t,int nruser)
{
    if(*p==0)
    {
        t->ind=nruser;
        return;
    }
    int delta=(tolower(*p));
    delta-='_';
    if(t->fiu[delta]==0)
        t->fiu[delta]=new trie;
    adauga(p+1,t->fiu[delta],nruser);
}
///actualizarea relevantei
int r;
void act(char *p,trie *t)
{
    if(*p==0)
    {
        t->val+=r;
        t->maxval=max(t->maxval,t->val);
        return;
    }
    int delta=(tolower(*p));
    delta-='_';
    act(p+1,t->fiu[delta]);
    t->maxval=max(t->maxval,t->fiu[delta]->maxval);
}
///cautare
int caut(char *p,trie *t)
{
    if(*p==0)
    {
        if(t->ind&&t->maxval==t->val)
            return t->ind;
        for(int i=0;i<33;++i)
            if(t->fiu[i]!=0)
                if(t->fiu[i]->maxval==t->maxval)
                    return caut(p,t->fiu[i]);
        return 0;
    }
    int delta=(tolower(*p));
    delta-='_';
    if(t->fiu[delta])
        return caut(p+1,t->fiu[delta]);
    return 0;
}
trie *T=new trie;
void del(trie *t)
{
    for(int i=0;i<33;++i)
    {
        if(t->fiu[i])
        {
            del(t->fiu[i]);
            t->fiu[i]=0;
        }
    }
    t->val=t->maxval=t->ind=0;
    if(T!=t)
        delete t;
}
int t,n,m,sol;
char U[NM][LM],S[LM],c,USER[LM];

int main()
{
    in>>t;
    while(t>0)
    {
        --t;
        in>>n>>m;
        for(int i=1;i<=n;++i)
        {
            in>>U[i];
            adauga(U[i],T,i);
        }
        for(int i=1;i<=m;++i)
        {
            in>>c>>USER;
            if(c=='U')
            {
                in>>r;
                act(USER,T);
            }
            else
            {
                sol=caut(USER,T);
                if(sol==0)
                    out<<"Search Bing for "<<USER<<'\n';
                else out<<U[sol]<<'\n';
            }
        }
        del(T);
    }
    return 0;
}

