#include <iostream>

using namespace std;
int a,b,ta,tb,ca,cb,c[100005],n;
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<"1 0";
        return 0;
    }
    for(int i=1;i<=n;++i)cin>>c[i];
    a=1;
    ta=c[1];
    tb=c[n];
    b=n;
    ca=1;
    cb=1;
    while(a<b-1)
    {
        if(ta<=tb)
        {
            ++a;
            ta+=c[a];
            ++ca;
        }
        else
        {
            --b;
            tb+=c[b];
            ++cb;
        }
    }
    cout<<ca<<" "<<cb;
    return 0;
}
