#include <iostream>
#include <fstream>
using namespace std;
ifstream in("submultimi.in");
ofstream out("submultimi.out");
int n;
int main()
{
    long long a=(1LL<<62);
    cout<<a<<endl;
    in>>n;
    for(int i=1;i<(1<<n);++i)
    {
        for(int j=0;j<n;++j)if(i&(1<<j))out<<j+1<<" ";
        out<<'\n';
    }
    return 0;
}
