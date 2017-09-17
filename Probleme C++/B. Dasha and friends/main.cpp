#include <iostream>
#include <algorithm>
using namespace std;
int n,l,a[105],b[105],init[105],sem,semafor;
int verif()
{
    for(int i=1;i<=n;++i)if(a[i]!=init[i])return 0;
    return 1;
}
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)init[i]=a[i];
    sem=1;
    while(sem)
    {
        semafor=1;
        for(int i=1;i<=n;++i)
        {
            --a[i];
            if(a[i]<0)a[i]+=l;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i)if(a[i]!=b[i])semafor=0;
        if(semafor==1)
        {
            cout<<"YES";
            sem=0;
        }
        else
        {
            if(verif())
            {
                cout<<"NO";
                sem=0;
            }
        }

    }
    return 0;
}
