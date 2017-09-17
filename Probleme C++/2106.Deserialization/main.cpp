#include <iostream>
#include <string>
#include <vector>
#include <map>
#define NM 245
#define LM 1005
using namespace std;
int n,l,ns,poz,spatii,codul,ultim;

map<int,string> name;
map<string,int> code;
map<int,vector<int> > members;
vector <int> v;

string encoding,line,nume;
int toint(char c)
{
    if(isalpha(c))return c-'A'+10;
    return c-'0';
}
long long next_int()
{
    long long rez=0;
    for(int i=poz;i<poz+8;++i)rez=16*rez+toint(encoding[i]);
    poz+=8;
    return rez;
}
char next_char()
{
    poz+=2;
    return (char)(16*toint(encoding[poz-2])+toint(encoding[poz-1]));
}
string next_string()
{
    string s;
    long long lungime=next_int();
    for(int i=1;i<=lungime;++i)s+=next_char();
    return s;
    ///de verif + implementat next char
}
void pars_struc(long long id)
{
    for(int mem=0;mem<members[id].size();++mem)
    {
        if(members[id][mem]==code["int"])
        {
            for(int i=0;i<spatii;++i)cout<<" ";
            cout<<"int ";
            cout<<next_int();
            cout<<'\n';
        }
        else
        {
            if(members[id][mem]==code["string"])
            {
                for(int i=0;i<spatii;++i)cout<<" ";
                cout<<"string ";
                cout<<next_string();
                cout<<'\n';
            }
            else
            {
                for(int i=0;i<spatii;++i)cout<<" ";
                cout<<name[members[id][mem]]<<'\n';
                ++spatii;
                pars_struc(members[id][mem]);
                --spatii;
            }
        }
    }
}
int main()
{
    cin>>n>>l;
    code["int"]=-1;
    code["string"]=0;
    for(int i=1;i<=l;++i)
    {
        cin>>line;
        if(line=="struct")
        {
            cin>>nume;
            name[++ultim]=nume;
            code[nume]=ultim;
        }
        else members[ultim].push_back(code[line]);
    }
    cin>>encoding;
    while(poz<encoding.size())
    {
        ultim=next_int();
        cout<<name[ultim]<<endl;
        ++spatii;
        pars_struc(ultim);
        --spatii;
    }
    return 0;
}

/// -1        -int
///  0        -string
///  1->m     -struct de alt tip
