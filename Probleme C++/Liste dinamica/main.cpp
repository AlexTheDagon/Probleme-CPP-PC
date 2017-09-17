#include <iostream>

using namespace std;
struct elem
{
    int val;
    elem *urm;
};

elem* prim = new elem;
elem* ultim = prim;

void add_IN_SPATE(int nr)
{
      elem *nou = new elem;
      nou->val = nr;
      nou->urm = NULL;
      ultim->urm=nou;
      ultim=nou;
}

void add_IN_FATA(int nr)
{
    elem *nou = new elem;
    nou->val = nr;
    nou->urm = prim;
    prim = nou;
}

void remove_IN_SPATE()
{
    elem *penultim = prim;

    while (penultim->urm->urm != NULL)
        penultim = penultim->urm;

    delete ultim;
    penultim->urm = NULL;
}

void remove_IN_FATA()
{
    elem *aux=prim;
    prim=prim->urm;
    delete aux;
}


int main()
{
    int n;
    prim->urm=NULL;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        add_IN_SPATE(i);
    }
    while(prim->urm!=NULL)
    {
        cout<<prim->urm->val<<" ";
        prim=prim->urm;
    }
    return 0;
}
