#include <iostream>

using namespace std;
int m,d,zile,x[]={0,31,28,31,30,31,30,31,31,30,31,30,31},z[8][8],col;
int main()
{
    cin>>m>>d;
    zile=x[m];
    for(int i=d;i<=7;++i)
    {
        z[i][1]=1;
        --zile;
    }
    for(int j=2;zile;++j)
    {
        for(int i=1;i<=7 && zile;++i)
        {
            z[i][j]=1;
            --zile;
        }
    }
    for(int i=2;i<=6;++i)if(z[1][i])++col;
    col++;
    cout<<col;
    return 0;
}
