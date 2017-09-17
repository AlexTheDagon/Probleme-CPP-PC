#include <iostream>

using namespace std;
int cam,p,q,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>p>>q;
        if(q-p>1)++cam;
    }
    cout<<cam;
    return 0;
}
