#include <iostream>

using namespace std;
int n,m,im,p,cnt;
int main()
{
    cin>>n>>m;
    im=n*m+1;
    p=im-1;
    im=1;
    p=m*n-(m*n)%2;
    if(n<=3 && m<=3)cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(cnt%2)cout<<p--<<" ";
                else cout<<im++<<" ";
                ++cnt;
            }
            cout<<'\n';
        }
    }
    return 0;
}
