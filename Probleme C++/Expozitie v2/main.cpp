#include <iostream>
#include <fstream>
using namespace std;
ifstream in("expozitie.in");
ofstream out("expozitie.out");
int n,d,ap,k,t;
long long a[255][255];
long long s;


int main()
{
    in>>n>>d>>ap;
    if(n<d*ap)out<<"0";
    else
    {
        n=n-d*ap;
        if(n==0)out<<"1";
        else
        {
            for(int i=1;i<=d;++i)a[1][i]=1;
            for(int i=2;i<=n;++i)
            {
                for(int j=1;j<=d;++j)
                {
                    a[i][j]=a[i-1][j]+a[i][j-1];
                }
            }
            for(int i=1;i<=d;++i)s+=a[n][i];
            out<<s;
        }
    }
    return 0;
}
///dp[i][j]--->ultimul desen put pe primele i scanduri e de tip j
///dp[i][j]=dp[i-1][j]+dp[i][j-1];

