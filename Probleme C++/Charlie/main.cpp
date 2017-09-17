#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
using namespace std;
ifstream in("charlie.in");
ofstream out("charlie.out");
int v,l=2,lmax,i=1,s,x[100005];
char a[100005],c;
stack <char> s1;
int main()
{
    in>>v;
    in>>a;
    if(v==1)
    {
        while(a[i]!='\0')
        {
            if((a[i]<a[i-1] && a[i]<a[i+1])||(a[i]>a[i-1] && a[i+1]<a[i]))x[i]=1;
            ++i;
        }
        i=1;
        while(a[i]!='\0')
        {
            if(x[i]==1)
            {
                ++l;
                if(x[i-1]==0 && a[i-1]>a[i])++l;
                if(x[i+1]==0 && a[i+1]>a[i])++l;
            }
            else l=0;
            lmax=max(l,lmax);
            ++i;
        }
        if(lmax==2)lmax=0;
        out<<lmax;
    }
    else
    {
        l=strlen(a);
        s1.push(a[l-1]);
        c=a[l-2];
        for(int j=l-3;j>=0;--j)
        {
            while(a[j]>c && !s1.empty() && s1.top()>c)
            {
                s+=max(s1.top()-'a'+1,a[j]-'a'+1);
                c=s1.top();
                s1.pop();
            }
            s1.push(c);
            c=a[j];
        }
        out<<c;
        while(!s1.empty())
        {
            out<<s1.top();
            s1.pop();
        }
        out<<'\n'<<s;
    }
    return 0;
}
