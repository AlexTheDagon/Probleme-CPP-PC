#include <iostream>
#include <algorithm>
using namespace std;
long long a,b,c,t,x[4],dif;
int main()
{
    cin>>x[1]>>x[2]>>x[3];
    sort(x+1,x+4);
    if(x[3]>x[1]+x[2]+x[1]+x[2])
        x[3]=2*(x[1]+x[2]);
    cout<<(x[1]+x[2]+x[3])/3<<endl;
    return 0;
}
