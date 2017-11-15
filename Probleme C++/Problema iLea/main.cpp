#include <iostream>

using namespace std;
int a[10][10],n,m,fol[100];
long long mod;
int back(int i,int j)
{
    if(i==j && i==n)
    {
        a[n][n]=n*n;
        int sem=1;
        for(int ii=1;ii<=n;++ii)
            for(int jj=1;jj<=n;++jj)if(a[ii][jj]<a[ii][jj-1] || a[ii][jj]<a[ii-1][jj])sem=0;
        mod+=sem;
    }
    else
    {
        for(int e=i*j;e<=(n*n)-(n-i+1)*(n-j+1)+1;++e)
        {
            if(!fol[e])
            {
                a[i][j]=e;
                fol[e]=1;
                if(j==n)back(i+1,1);
                else back(i,j+1);
                fol[e]=0;
            }
        }
    }
}
int main()
{
    fol[1]=1;
    a[1][1]
=1;    cin>>n;
    back(1,2);
    cout<<mod;
    return 0;
}
