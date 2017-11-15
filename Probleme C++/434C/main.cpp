#include <iostream>

using namespace std;
string s,s2;
int nc=0;
char c1,c2;
int voc(char c)
{
	return(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
int main()
{
	cin>>s;
	for (int i=0;i<s.size();++i) {
		if(voc(s[i]))
        {
			nc=0;
			s2+=s[i];
		}
		else
        {
			if(nc>=2)
			{
				if(c1==s[i] && c2==s[i])
				{
					++nc;
					s2+=s[i];
				}
				else
                {
					cout<<s2<<" ";
					s2="";
					nc=1;
					c1=c2=s[i];
					s2+=s[i];
				}
			}
			else
            {
                if(nc==1)
                {
                    ++nc;
                    c2=s[i];
                    s2+=s[i];
                }
                else
                {
                    nc=1;
                    c1=c2=s[i];
                    s2+=s[i];
                }
			}
		}
	}
	if(s2!="")cout<<s2;
	return 0;
}
