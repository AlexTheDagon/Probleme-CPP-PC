#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("disjoint.in");
ofstream out("disjoint.out");
int p[NM],h[NM],n,m,c,a,b;
int rad(int nod)
{
    int radacina=nod,aux;
    while(p[radacina]!=radacina)radacina=p[radacina];
    aux=nod;
    while(p[nod]!=nod)
    {
        aux=p[nod];
        p[nod]=radacina;
        nod=aux;
    }
    return radacina;
}
void unire(int nod1,int nod2)
{
    if(h[nod1]>h[nod2])p[nod2]=nod1;
    else p[nod1]=nod2;
    if(h[nod1]==h[nod2])++h[nod1];
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        h[i]=1;
        p[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        in>>c>>a>>b;
        if(c==2)
        {
            if(rad(a)==rad(b))out<<"DA"<<'\n';
            else out<<"NU"<<'\n';
        }
        else
        {
            unire(rad(a),rad(b));
        }
    }
    return 0;
}
