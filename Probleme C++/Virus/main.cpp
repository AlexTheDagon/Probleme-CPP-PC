#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("virus.in");
ofstream out("virus.out");

struct _nod{
    int nrSons=0,nrEnd=0,nrAp=0;
    _nod *SONS[2]={};
};
_nod *root= new _nod;

int n,qs,maxk;
int C[2];
string S;
vector<_nod*> VQ;

_nod* add(_nod *nod, string s){
    nod->nrSons++;
    for(auto c : s){
        if(!nod->SONS[c-'0'])
            nod->SONS[c-'0']=new _nod;
        nod=nod->SONS[c-'0'];
        nod->nrSons++;
    }
    nod->nrEnd++;
    return nod;
}
void update(_nod *nod, int start, int length){
    for(int i=0;i<length&&i+start<S.size();i++){
        if(!nod->SONS[S[start+i]-'0'])
            return;
        nod=nod->SONS[S[start+i]-'0'];
        nod->nrAp++;
    }
}
void read(){
    int x;
    int T[2]={0,0};
    string t;
    in>>n>>qs;
    in>>S;
    for(auto c : S)
        C[c-'0']++;
    for(int i=1;i<=qs;i++){
        in>>x>>t;
        for(auto c : t)
            T[c-'0']++;
        if(T[0]>C[0]||T[1]>C[1]){
            VQ.push_back(root);
            continue;
        }
        T[0]=T[1]=0;
        maxk=max(maxk,x);
        VQ.push_back(add(root,t));
    }
}
void solve(){
    for(int st=0;st<S.size();st++){
        update(root,st,maxk);
    }
    for(auto x : VQ){
        out<<x->nrAp<<"\n";
    }
}
int main(){
    for(int i=1;i<=100000;++i);
    read();
    solve();
    return 0;
}
