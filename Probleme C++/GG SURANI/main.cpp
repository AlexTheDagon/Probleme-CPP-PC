#include <iostream>
#include <vector>
using namespace std;
int minim,minimi,repoz;
#define pb push_back
class ForwardMancala
{
	public:
	vector<int>findMoves(vector<int> start)
	{
		vector<int>afis;
		minim=1<<30;
		for(int i=0;i<start.size();++i)
		{
			if(start[i]!=0)repoz++;
			if(start[i]<minim)
			{
				minim=start[i];
				minimi=i;
			}
		}
		repoz--;
		while(repoz)
		{
			cout<<minimi<<" ";
			afis.pb(minimi);
			start[minimi]=0;repoz--;
			for(int i=minimi;i<=minimi+start[minimi];++i)
			{
				if(start[i%start.size()]==0)repoz++;
				start[i%(start.size())]++;
				if(start[i%start.size()]<minim && start[i%start.size()]!=0)
				{
					minim=start[i];
					minimi=i;
				}
			}
		}
		return afis;
	}
};
