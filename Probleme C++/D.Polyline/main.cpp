#include <iostream>
using namespace std;
int x[3],y[3];

int verif(int a,int b,int c)
{
    return(min(a, b)<= c && c<=max(a, b));
}
int f(int i,int j,int k)
{
    return((x[k]==x[i] || x[k]==x[j]) && verif(y[i],y[j],y[k])||(y[k]==y[i] || y[k]==y[j]) && verif(x[i],x[j],x[k]));
}
int main()
{
    for(int i=0;i<3;i++)cin>>x[i]>>y[i];
    if (x[0]==x[1] && x[1]==x[2] || y[0]==y[1] && y[1]==y[2])cout<<"1";
    else
    {
        if(f(0,1,2) || f(0,2,1) || f(1,2,0)) cout << "2";
        else cout<<"3";
    }
    return 0;
}
///editorial+sursa editorial
