#include <iostream>
#define M 1000000007
using namespace std;
string s;
int nrb,sol;
int main()
{
    cin>>s;
    for(int i=s.size()-1;i>=0;--i)
    {
        if(s[i]=='b')++nrb;
        else
        {
            sol+=nrb;
            sol%=M;
            nrb*=2;///toate b-urile de dupa a se dubleaza
            nrb%=M;
        }
    }
    cout<<sol;
    return 0;
}
