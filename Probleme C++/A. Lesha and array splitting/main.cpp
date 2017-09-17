#include <iostream>
#include <fstream>
#include <queue>
#define mm make_pair
using namespace std;
int a[105],l,r,n,nr,s,ind;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s!=0)
    {
        cout<<"YES"<<'\n'<<"1"<<'\n'<<"1 "<<n;
    }
    else
    {
        s=0;
        for(int i=1;i<=n && ind==0;++i)
        {
            s+=a[i];
            if(s!=0)ind=i;
        }
        if(ind==0)cout<<"NO";
        else
        {
            cout<<"YES"<<'\n'<<"2"<<'\n'<<"1 "<<ind<<'\n'<<ind+1<<" "<<n;
        }
    }
    return 0;
}
