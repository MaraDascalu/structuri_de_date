//
//  main.cpp
//  Curatenie
//
//  Created by Mara Dascalu on 13/05/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("curatenie.in");
ofstream output("curatenie.out");

struct nod
{
    int val;
    nod* st;
    nod* dr;
};

int n, poz_rad = 1, val;


nod* build(int srd[], int valSt, int valDr)
{
    if (valSt > valDr)
        return NULL;
    
    nod* radacina = new nod();
    input>>radacina->val;
    radacina->st = NULL;
    radacina->dr = NULL;
    
    if(valSt == valDr) return radacina;
    
    int poz_rad_in_srd = srd[radacina->val];
    
    radacina->st = build(srd, valSt, poz_rad_in_srd - 1);
    radacina->dr = build(srd, poz_rad_in_srd + 1, valDr);
    
    return radacina;
}

void curatenie(nod* radacina, pair<int, int> ordine[])
{
    if (radacina == NULL)
        return;

    if (radacina->st == NULL)
        ordine[radacina->val].first = 0;
    else ordine[radacina->val].first = radacina->st->val;
    
    if (radacina->dr == NULL)
        ordine[radacina->val].second = 0;
    else ordine[radacina->val].second = radacina->dr->val;
    
    curatenie(radacina->st, ordine);
    curatenie(radacina->dr, ordine);
}

int main(int argc, const char * argv[]) {
    input>>n;
//    cout<<n<<"\n";
    pair<int, int> ordine[n+1];
    int srd[n+1];
    for (int i = 1; i <= n; i++)
    {
        input>>val;
        srd[val] = i;
    }
    
    nod* radacina = build(srd, 1, n);
    curatenie(radacina, ordine);
    
    for (int i = 1; i <= n; i++)
        output<<ordine[i].first<<" "<<ordine[i].second<<"\n";
}

