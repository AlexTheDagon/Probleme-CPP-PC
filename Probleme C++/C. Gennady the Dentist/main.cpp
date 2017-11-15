#include <iostream>
#define NM 5005
using namespace std;
long long n,d[NM],v[NM],p[NM],vindecati,fuge,sol[NM],aux,minp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>v[i]>>d[i]>>p[i];
    for(int fuge=1;fuge<=n;++fuge)
    {
        if(p[fuge]>=0)
        {
            sol[++vindecati]=fuge;
            aux=v[fuge];
            minp=0;
            for(int i=fuge+1;i<=n;++i)
            {
                if(p[i]>=0)
                {
                    p[i]-=(minp+aux);
                    if(aux>0)--aux;
                    if(p[i]<0)minp+=d[i];
                }
            }
        }
    }
    cout<<vindecati<<'\n';
    for(int i=1;i<=vindecati;++i)cout<<sol[i]<<" ";
    return 0;
}
