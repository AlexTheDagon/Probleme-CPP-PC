#include <iostream>
#include <stack>
#define mp make_pair
#define pp pair<char,int>
#define x first
#define y second
using namespace std;
stack<pp> s;
int st[1000005],n,stmax=1,maxx,i,nr,sem[1000005];
string ss;
int main()
{
    cin>>ss;
    for(auto c:ss)
    {
        ++i;
        if(c==')')
        {
            if(!s.empty())
            {
                if(s.top().x=='(')
                {
                    if(st[s.top().y-1])st[i]=st[s.top().y-1];
                    else st[i]=s.top().y;
                    if(maxx<i-st[i]+1)maxx=i-st[i]+1;
                    s.pop();
                }
            }
        }
        else s.push(mp('(',i));
    }
    for(int j=i;j>0;--j)
    {
        if(st[j])
        {
            if(maxx==j-st[j]+1)++nr;
            j=st[j];
        }
    }
    if(nr==0)++nr;
    cout<<maxx<<" "<<nr;
    return 0;
}
