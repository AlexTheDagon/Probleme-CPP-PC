#include <iostream>

using namespace std;
int n,a[25],cmin[1<<21],sol;
int impuscaturi[25];
void solve(int conf,int confact)
{
    if(confact==sol)
    {
        cmin[sol]=min(cmin[sol],cmin[conf]);
    }
    else
    {
        int dmg=0;
        for(int i=0;i<n;++i)if((confact & (1<<i))==0)dmg=dmg+a[i];
        if(dmg+cmin[conf]<cmin[confact] | cmin[confact]==0)
        {
            cmin[confact]=dmg+cmin[conf];
            for(int i=0;i<n;++i)
            {
                if(confact|impuscaturi[i]!=confact)solve(confact,confact|impuscaturi[i]);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sol=(1<<n)-1;

    impuscaturi[0]=7;
    for(int i=1;i<n-2;++i)impuscaturi[i]=(impuscaturi[i-1]<<1);
    impuscaturi[n-2]=(1<<(n-1))+3;
    impuscaturi[n-1]=(1<<(n-1))+(1<<(n-2))+1;///bine

    cmin[sol]=1<<25;
    if(n==3)cout<<"0";
    else
    {
        for(int i=0;i<n;++i)
        {
            solve(0,impuscaturi[i]);
        }
        cout<<cmin[sol];
    }
    return 0;
}
