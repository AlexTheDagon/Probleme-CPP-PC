#include <iostream>
#include <fstream>
using namespace std;
ifstream in("furnica.in");
ofstream out("furnica.out");
char c;
long long sum,t;
int main()
{
    in>>c>>t;
    if(c=='C')out<<(t+1)*(t+1);
    else
    {
        if(t%2==0)out<<(t/2+1)*(t/2+1);
        else
        {
            out<<((t+1)*(t+2)/2)-((t+1)/2)*((t+1)/2);
        }
    }
    return 0;
}
