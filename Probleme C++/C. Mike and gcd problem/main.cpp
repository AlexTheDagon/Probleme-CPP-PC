#include <iostream>'

using namespace std;
int cmmdc(int a, int b)
{
    if(b==0)return a;
    return cmmdc(b,a%b);
}
int n,a,sol,cnt,d;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        d=cmmdc(d,a);
        if(a%2==1)++cnt;
        else
        {
            sol+=(cnt/2+2*(cnt%2));
            cnt=0;
        }
    }
    sol+=(cnt/2+2*(cnt%2));
    cout<<"YES"<<endl;
    if(d==1)cout<<sol;
    else cout<<"0";
    return 0;
}
