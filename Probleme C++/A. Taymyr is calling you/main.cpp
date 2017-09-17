#include <iostream>

using namespace std;
int z,n,m,tn,tm,ucis;
int main()
{
    cin>>n>>m>>z;
    tn=n;
    tm=m;
    while(tn<=z && tm<=z)
    {
        if(tn==tm)++ucis;
        if(tn>tm)tm+=m;
        else tn+=n;
    }
    cout<<ucis;
    return 0;
}
