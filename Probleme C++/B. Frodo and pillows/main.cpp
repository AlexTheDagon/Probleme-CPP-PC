#include <iostream>

using namespace std;
long long n,m,k,dr,st,perne,fr,d,s;
int main()
{
    cin>>n>>m>>k;
    fr=1;
    m=m-n;
    dr=n-k;
    st=k-1;
    while(d+s<m && (d<dr || s<st))
    {
        m=m-1-s-d;
        ++fr;
        if(d<dr)++d;
        if(s<st)++s;
    }
    fr=fr+m/n;
    cout<<fr;
    return 0;
}
