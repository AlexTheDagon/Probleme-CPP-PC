#include <iostream>

using namespace std;
int a[5][5],sem;
char c;
int main()
{
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=4;++j)
        {
            cin>>c;
            if(c=='x')a[i][j]=1;
            if(c=='o')a[i][j]=-1;
        }
    }
    for(int i=1;i<=4;++i)
    {
        if(a[1][i]+a[2][i]+a[3][i]==2 || a[4][i]+a[2][i]+a[3][i]==2)sem=1;
        if(a[i][1]+a[i][2]+a[i][3]==2 || a[i][4]+a[i][2]+a[i][3]==2)sem=1;
    }
    for(int i=2;i<4;++i)
    {
        for(int j=2;j<4;++j)
        {
            if(a[i][j]+a[i-1][j-1]+a[i+1][j+1]==2 || a[i][j]+a[i-1][j+1]+a[i+1][j-1]==2)sem=1;
        }
    }
    if(sem==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}
