#include <iostream>
#include <fstream>
using namespace std;
ifstream in("xormax.in");
ofstream out("xormax.out");
int n,a[100005],rev,st,fn,poz,sol=-100000000,act;
struct trie
{
    trie *fiu[2]={0};
    int terminal=0;
};
void adauga(trie *T,int nr,int grad,int ind)
{
    if(grad==-1)
    {
        T->terminal=ind;
        return;
    }
    bool bit=nr&(1<<grad);
    if(T->fiu[bit]==0)T->fiu[bit]=new trie;
    adauga(T->fiu[bit],nr,grad-1,ind);
}
int cauta(trie *T,int nr,int grad)
{
    if(grad<0)return T->terminal;
    bool bit=nr&(1<<grad);
    if(T->fiu[!bit]==0)
        return cauta(T->fiu[bit],nr,grad-1);
    return cauta(T->fiu[!bit],nr,grad-1);
}
trie *T=new trie;
int main()
{
    adauga(T,0,21,0);
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        a[i]^=a[i-1];
        poz=cauta(T,a[i],21);
        act=a[i]^a[poz];
        if(act>sol)
        {
            sol=act;
            st=poz+1;
            fn=i;
        }
        adauga(T,a[i],21,i);
    }
    out<<sol<<" "<<st<<" "<<fn;
    return 0;
}
