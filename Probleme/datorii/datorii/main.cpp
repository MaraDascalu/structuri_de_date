//
//  main.cpp
//  datorii
//
//  Created by Mara Dascalu on 19/05/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input ("datorii.in");
ofstream output ("datorii.out");

const int n_max = 15000;
int n, m, op, neachitat, ziua, achitat, arbint[n_max*4 + 1], intervSt, intervDr;

void build(int nod, int valSt, int valDr, int poz, int val)
{
    if (valSt == valDr)
    {
        arbint[nod] = val;
        return;
    }
    int mij = (valSt + valDr) / 2;
    if (poz <= mij) build(2*nod, valSt, mij, poz, val);
    else build(2*nod + 1, mij + 1, valDr, poz, val);

    arbint[nod] = arbint[2*nod] + arbint[2*nod + 1];
}

void update(int nod, int valSt, int valDr, int poz, int val){
    if (valSt == valDr)
    {
        arbint[nod] -= val;
        return;
    }
    int mij = (valSt + valDr) / 2;
    if (poz <= mij)
        update(2*nod, valSt, mij, poz, val);
    else update(2*nod+1, mij + 1, valDr, poz, val);
    
    arbint[nod] = arbint[2*nod] + arbint[2*nod+1];
}

void query(int nod, int valSt, int valDr, int intervSt, int intervDr, int& suma)
{
    if (intervSt <= valSt && valDr <= intervDr)
    {
        suma += arbint[nod];
        return;
    }
        int mij = (valSt + valDr) / 2;
        if (intervSt <= mij) query(2*nod, valSt, mij, intervSt, intervDr, suma);
        if (mij < intervDr) query(2*nod + 1, mij + 1, valDr, intervSt, intervDr, suma);
}


int main(int argc, const char * argv[]) {
    input>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        input>>neachitat;
        build(1,1,n,i,neachitat);
    }

    for (int i = 1; i <= m; i++)
    {
        input>>op;
        if (!op)
        {
            input>>ziua>>achitat;
            update(1,1,n,ziua,achitat);
        }
        else
        {
            input>>intervSt>>intervDr;
            int suma = 0;
            query(1,1,n,intervSt, intervDr, suma);
            output<<suma<<"\n";
        }
    }
}

