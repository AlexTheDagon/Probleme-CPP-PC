#include <iostream>
#include <fstream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;
ifstream in("dir.in");
ofstream out("dir.out");
string v[105],a,b;
stack <string> s,aux,copie;
char d=char(92);
int st=-1,l,fisier,folder,ind;
int main()
{
    in>>a;
    for(int i=0;i<a.size();++i)
    {
        if(isdigit(a[i]) || isalpha(a[i]))
        {
            if(st==-1)st=i;
            ++l;
            if(isalpha(a[i]))
            {
                if(islower(a[i]))fisier=1;
            }
        }
        else
        {
            if(st!=-1)
            {
                b="";
                b.append(a,st,l);
                st=-1;
                l=0;
                s.push(b);
                if(fisier==1)
                {
                    copie=s;
                    while(!copie.empty())
                    {
                        aux.push(copie.top());
                        copie.pop();
                    }
                    ++ind;
                    v[ind].append(aux.top());
                    aux.pop();
                    while(!aux.empty())
                    {
                        v[ind]+=d;
                        v[ind].append(aux.top());
                        aux.pop();
                    }
                    if(a[i]==',' || a[i]==')')s.pop();
                    fisier=0;
                }
            }
            if(a[i]==')')s.pop();
        }
    }
    out<<ind<<'\n';
    sort(v+1,v+ind+1);
    for(int i=1;i<=ind;++i)out<<v[i]<<'\n';
    return 0;
}
