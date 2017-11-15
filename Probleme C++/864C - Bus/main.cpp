#include <iostream>

using namespace std;
int dist,capat,a,b,f,k,minn,ramas;
int main()
{
    cin>>a>>b>>f>>k;
    if(b<f || (2*f>b && k>2) || (2*(a-f)>b))
    {
        if(!(k==1 && f<=b && a-f<=b))
        {
            cout<<"-1";
            return 0;
        }
    }
    ///capat 0 daca vin din 0 sau 1 daca vin din a
    ramas=b-f;
    for(int i=1;i<k;++i)
    {
        if(capat==0)dist=2*(a-f);
        else dist=2*f;
        if(dist>ramas)
        {
            ramas=b;
            ++minn;
        }
        ramas-=dist;
        capat=1-capat;
    }
    if(capat==0)dist=2*(a-f);
    else dist=2*f;
    dist/=2;
    if(dist>ramas)
    {
        ramas=b;
        ++minn;
    }
    cout<<minn<<endl;
    return 0;
}
