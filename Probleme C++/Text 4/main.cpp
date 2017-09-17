#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#define pb push_back
using namespace std;
ifstream in("text4.in");
ofstream out("text4.out");
string s;
int maxx,cmax,sem;
vector <string> v;
int spatii,rest;
string a;
int main()
{
    in>>maxx;
    cmax=maxx;
    while(in>>s)
    {

                    if(s.size()+v.size()<=cmax)
                    {
                        v.pb(s);
                        cmax-=s.size();
                    }
                    else
                    {
                        spatii=0;
                        rest=0;
                        if(v.size()>1)
                        {
                            spatii+=cmax/(v.size()-1);
                            rest=cmax%(v.size()-1);
                        }
                        for(int i=0;i<v.size()-1;++i)
                        {
                            out<<v[i];
                            for(int j=0;j<spatii;++j)out<<" ";
                            if(rest)
                            {
                                out<<" ";
                                --rest;
                            }
                        }
                        out<<v[v.size()-1]<<'\n';
                        v.clear();
                        v.pb(s);
                        cmax=maxx;
                    }

    }
    for(int i=0;i<v.size()-1;++i)out<<v[i]<<" ";
    out<<v[v.size()-1];
    return 0;
}
