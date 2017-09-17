#include <iostream>
#include <fstream>
#define NM 255
using namespace std;
ifstream in("bile.in");
ofstream out("bile.out");
int p[NM*NM],h[NM*NM],n,b[NM][NM],l,c,ord[2][NM*NM],maxx,pas,ans[NM*NM];
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
    h[nod1]+=h[nod2];
    h[nod2]=h[nod1];
    maxx=max(maxx,h[nod1]);
}
int main()
{
    in>>n;
    for(int i=n*n;i>0;--i)
        in>>ord[0][i]>>ord[1][i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)b[i][j]=(i-1)*n+j;
    pas=n*n;
    maxx=1;
    for(int i=1;i<n*n;++i)
    {
        l=ord[0][i];
        c=ord[1][i];
        h[b[l][c]]=1;
        p[b[l][c]]=b[l][c];
        if(h[b[l-1][c]])
            if(rad(b[l][c])!=rad(b[l-1][c]))unire(rad(b[l][c]),rad(b[l-1][c]));
        if(h[b[l+1][c]])
            if(rad(b[l][c])!=rad(b[l+1][c]))unire(rad(b[l][c]),rad(b[l+1][c]));
        if(h[b[l][c-1]])
            if(rad(b[l][c])!=rad(b[l][c-1]))unire(rad(b[l][c]),rad(b[l][c-1]));
        if(h[b[l][c+1]])
            if(rad(b[l][c+1])!=rad(b[l][c]))unire(rad(b[l][c]),rad(b[l][c+1]));
        ans[--pas]=maxx;
    }
    for(int i=1;i<=n*n;++i)out<<ans[i]<<'\n';
    return 0;
}
