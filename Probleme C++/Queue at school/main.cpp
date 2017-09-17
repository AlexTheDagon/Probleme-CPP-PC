#include <iostream>

using namespace std;
string s;
int t,aux,poz,n;
int main()
{
    cin>>n>>t;
    cin>>s;
    while(t)
    {
        --t;
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]=='B' && s[i+1]=='G')
            {
                swap(s[i],s[i+1]);
                --i;
            }
        }
    }
    cout<<s;
    return 0;
}
