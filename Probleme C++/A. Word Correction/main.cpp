#include <iostream>

using namespace std;
int isvowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}
int main()
{
    char S[105];
    int n;
    cin>>n;
    cin>>S+1;
    for(int i=1;i<=n;++i)
    {
        if(!isvowel(S[i-1]) && isvowel(S[i])||(!isvowel(S[i])))cout<<S[i];
    }

    return 0;
}
