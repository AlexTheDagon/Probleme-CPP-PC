#include <iostream>

using namespace std;
int n,c,a[200005],maresauegal[200005],mic[200005],di;
int main()
{
    cin>>n;
    for(int i=0;i<=n+1;++i)
    {
        maresauegal[i]=(-1<<30);
        mic[i]=1<<30;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>c>>di;
        a[i]=a[i-1]+c;
        if(di==1)maresauegal[i-1]=max(maresauegal[i-1],-a[i-1]);
        else mic[i-1]=min(mic[i-1],-a[i-1]);
        maresauegal[i]=maresauegal[i-1];
        mic[i]=mic[i-1];
    }
    for(int i=n+1;i<=n+1;++i)
    {
        maresauegal[i-1]=max(maresauegal[i-1],-a[i-1]);
        mic[i-1]=min(mic[i-1],-a[i-1]);
    }
    for(int i=1;i<=n;++i)cout<<maresauegal[i]<<" "<<mic[i]<<endl;
    if(mic[n]==1<<30 || maresauegal[n]==(-1<<30))cout<<"Infinity";
    else
    {
        if(mic[n]<=maresauegal[n])cout<<"Impossible";
        else cout<<a[n]+mic[n]+1899;
    }
    return 0;
}
