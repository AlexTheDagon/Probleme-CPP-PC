#include <iostream>

using namespace std;
int n,k,cmin[505][505],sa[505],sn[505],c;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        sa[i]=sa[i-1];
        sn[i]=sn[i-1];
        if(c)sa[i]++;
        else sn[i]++;
    }
    for(int i=1;i<=n;++i)cmin[1][i]=sn[i]*sa[i];
    for(int i=2;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cmin[i][j]=1<<29;
            for(int h=0;h<j;++h)
            {
                cmin[i][j]=min(cmin[i][j],cmin[i-1][h]+(sn[j]-sn[h])*(sa[j]-sa[h]));
            }

        }
    }
    cout<<cmin[k][n];
    return 0;
}
