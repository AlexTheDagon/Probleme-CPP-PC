#include <iostream>

using namespace std;
int fol[30],sem;
string s;
int main()
{
    fol[0]=1;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(fol[s[i]-'a']==0)sem=1;
        else fol[s[i]-'a'+1]=1;
    }
    if(sem)cout<<"NO";
    else cout<<"YES";
    return 0;
}
