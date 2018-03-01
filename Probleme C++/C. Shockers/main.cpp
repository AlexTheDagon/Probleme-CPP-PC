#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set<char> lc,lg,ls;
string s;
char c,lit;
int n,cnt;
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(char i='a';i<='z';++i)lg.insert(i);
    for(int i=1;i<n;++i)
    {
        s="";
        cin>>c>>s;
        if(lg.size()==1)
        {
            if(c=='?' || c=='!')++cnt;
        }
        else
        {
            if(c=='?')
            {
                lit=s[0];
                if(lg.find(lit)!=lg.end())lg.erase(lit);///scoatem litera din cele gresite
                lc.insert(lit);///litera e buna
            }
            if(c=='!')///cuvant ce contine litera gresita
            {
                for(auto i:s)
                {
                    if(lc.find(i)!=lc.end() && lg.find(i)!=lg.end())lg.erase(lit);///stergem litera dintre cele rele daca e buna
                    if(lg.find(i)==lg.end())lc.insert(i);///daca nu e printre cele gresite litera e buna
                }
                for(auto i:s)ls.insert(i);///toate literele rele care nu apar in s devin litere bune
                for(char i='a';i<='z';++i)
                {
                    if(lg.find(i)!=lg.end() && ls.find(i)==ls.end())
                    {
                        lc.insert(i);
                        lg.erase(i);
                    }
                }
                ls.clear();
            }
            if(c=='.')
            {
                for(auto i:s)lc.insert(i);///litera e buna
                for(auto i:lc)if(lg.find(i)!=lg.end())lg.erase(i);///daca litera e buna o sterg dintre cele gresite
            }
        }
    }
    cout<<cnt;
    return 0;
}
