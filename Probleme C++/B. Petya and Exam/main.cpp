#include <iostream>

using namespace std;
string s,in;
int a[300],n,sem,semm;
int main()
{
    cin>>s;
    for(auto c:s)a[c]=1;
    cin>>in>>n;
    for(auto c:in)if(c=='*')semm=1;
    for(int i=1;i<=n;++i)
    {
        s="";
        cin>>s;
        sem=1;
        if((s.size()+1==in.size() && !semm)||(s.size()<in.size()-1)||(s.size()>in.size()))sem=0;
        else
        {
            for(int i=0;i<s.size();++i)
            {
                if(isalpha(in[i]) && s[i]!=in[i])sem=0;
                if(in[i]=='?' && a[s[i]]==0)sem=0;
                if(in[i]=='*' && a[s[i]]==1 && a[s[i]]!=' ')sem=0;
            }
        }
        if(sem)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
