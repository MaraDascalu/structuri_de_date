//
//  main.cpp
//  Arbori de intervale
//
//  Created by Mara Dascalu on 18/05/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input ("arbint.in");
ofstream output ("arbint.out");

const int n_max = 100000;
int n, m, op, interv_st, interv_dr, poz, val, maxim;
int arbint[4*n_max + 1];

void update(int nod, int valSt, int valDr, int poz, int val){
    if (valSt == valDr)
    {
        arbint[nod] = val;
        return;
    }
    int mij = (valSt + valDr) / 2;
    if (poz <= mij)
        update(2*nod, valSt, mij, poz, val);
    else update(2*nod+1, mij + 1, valDr, poz, val);
    
    arbint[nod] = max(arbint[2*nod], arbint[2*nod+1]);
}

void query (int nod, int valSt, int valDr, int limitaSt, int limitaDr, int& maxim){
    if (limitaSt <= valSt && valDr <= limitaDr){
        if (maxim <= arbint[nod]) maxim = arbint[nod];
        return;
    }
        int mij = (valSt + valDr) / 2;
        if (limitaSt <= mij)
            query(2*nod, valSt, mij, limitaSt, limitaDr, maxim);
        if (mij < limitaDr)
            query(2*nod+1, mij+1, valDr, limitaSt, limitaDr, maxim);
    
}

int main(int argc, const char * argv[]) {
    input>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        input>>val;
        update(1,1,n,i,val);
    }
    for (int i = 1; i <= m; i++)
    {
        input>>op;
        if (!op)
        {
            input>>interv_st>>interv_dr;
            maxim = -1;
            query(1,1,n,interv_st,interv_dr,maxim);
            output<<maxim<<"\n";
        }
        else
        {
            input>>poz>>val;
            update(1,1,n,poz,val);
        }
    }
}
