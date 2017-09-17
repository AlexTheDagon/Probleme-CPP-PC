#include <iostream>

using namespace std;
char a[4][4];
int fr[300],sem[300];
int main()
{
    for(int i=1;i<=3;++i)
        for(int j=1;j<=3;++j)
        {
            cin>>a[i][j];
            ++fr[a[i][j]];
        }
    if(a[2][2]==a[1][1] && a[1][1]==a[3][3])sem[a[2][2]]=1;
    if(a[1][2]==a[2][2] && a[2][2]==a[3][2])sem[a[2][2]]=1;
    if(a[1][3]==a[2][2] && a[2][2]==a[3][1])sem[a[2][2]]=1;
    if(a[2][1]==a[2][2] && a[2][2]==a[2][3])sem[a[2][2]]=1;

    if(a[1][1]==a[1][2] && a[1][1]==a[1][3])sem[a[1][1]]=1;
    if(a[1][1]==a[2][1] && a[1][1]==a[3][1])sem[a[1][1]]=1;
    if(a[3][1]==a[3][2] && a[3][1]==a[3][3])sem[a[3][3]]=1;
    if(a[3][3]==a[1][3] && a[3][3]==a[2][3])sem[a[3][3]]=1;
    ///acum cazurile de final
    if(fr['X']-fr['0']<0 || fr['X']-fr['0']>1 || (sem['X']+sem['0']>1) || (sem['X'] && fr['X']==fr['0']) || (sem['0'] && fr['X']>fr['0']) )
    {
        cout<<"illegal";
        return 0;
    }
    if(sem['X'])
    {
        cout<<"the first player won";
        return 0;
    }
    if(sem['0'])
    {
        cout<<"the second player won";
        return 0;
    }
    if(fr['.']==0)
    {
        cout<<"draw";
        return 0;
    }
    if(fr['X']==fr['0'])cout<<"first";
    else cout<<"second";
    return 0;
}
