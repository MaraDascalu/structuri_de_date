//
//  main.cpp
//  MIT
//
//  Created by Mara Dascalu on 19/05/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input("mit.in");
ofstream output("mit.out");

const int n_max = 100000;
int n, m, op, nota, intervSt, intervDr, pct_bonus, arbint[n_max*4+1], lazy[n_max*4+1];

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

    arbint[nod] = max(arbint[2*nod],arbint[2*nod + 1]);
}

void query (int nod, int valSt, int valDr, int limitaSt, int limitaDr, int& maxim){
    
    if (lazy[nod])
    {
        arbint[nod] += lazy[nod];
        if (valSt != valDr)
        {
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if (valSt > valDr || valSt>limitaDr || valDr < limitaSt)
        return;
    
    if (limitaSt <= valSt && valDr <= limitaDr)
    {
        if(arbint[nod] > maxim) maxim = arbint[nod];
        return;
    }
    int mij = (valSt + valDr) / 2;
    if (limitaSt <= mij) query(2*nod, valSt, mij, limitaSt, limitaDr, maxim);
    if (mij < limitaDr) query(2*nod+1, mij+1, valDr, limitaSt, limitaDr, maxim);
    
}

void bonus(int nod, int valSt, int valDr, int limitaSt, int limitaDr, int pct_bonus)
{
    if (lazy[nod])
    {
        arbint[nod] += lazy[nod];
        if (valSt != valDr)
        {
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    
    if (valSt > valDr || valSt>limitaDr || valDr < limitaSt)
        return;

    if (limitaSt <= valSt && valDr <= limitaDr)
    {
        arbint[nod] += pct_bonus;
        if (valSt != valDr)
        {
            lazy[nod*2] += pct_bonus;
            lazy[nod*2+1] += pct_bonus;
        }
        return;
    }
    
    int mij = (valSt + valDr) / 2;
    
    bonus(2*nod, valSt, mij, limitaSt, limitaDr, pct_bonus);
    bonus(2*nod+1, mij+1, valDr, limitaSt, limitaDr, pct_bonus);
    
    arbint[nod] = max(arbint[2*nod], arbint[2*nod+1]);
}

int main(int argc, const char * argv[]) {
    input>>n>>m;
    for (int i = 1; i <=n; i++)
    {
        input>>nota;
        build(1,1,n,i,nota);
    }

    for (int i = 1; i <= m; i++)
    {
        input>>op>>intervSt>>intervDr;
        if (op == 1)
        {
            int maxim = -1;
            query(1,1,n,intervSt, intervDr, maxim);
            output<<maxim<<"\n";
        }
        else
        {
            input>>pct_bonus;
            bonus(1,1,n,intervSt, intervDr, pct_bonus);
        }
    }
}




//void build(int nod, int valSt, int valDr, int poz, int val)
//{
//    if (valSt == valDr)
//    {
//        arbint[nod] = val;
//        return;
//    }
//    int mij = (valSt + valDr) / 2;
//    if (poz <= mij) build(2*nod, valSt, mij, poz, val);
//    else build(2*nod + 1, mij + 1, valDr, poz, val);
//
//    arbint[nod] = max(arbint[2*nod],arbint[2*nod + 1]);
//}
//
//void query (int nod, int valSt, int valDr, int limitaSt, int limitaDr, int& maxim){
//    if (limitaSt <= valSt && valDr <= limitaDr){
//        if (maxim <= arbint[nod]) maxim = arbint[nod];
//        return;
//    }
//        int mij = (valSt + valDr) / 2;
//        if (limitaSt <= mij)
//            query(2*nod, valSt, mij, limitaSt, limitaDr, maxim);
//        if (mij < limitaDr)
//            query(2*nod+1, mij+1, valDr, limitaSt, limitaDr, maxim);
//
//}
//
//void bonus(int nod, int valSt, int valDr,int poz, int pct_bonus)
//{
//    if (valSt == valDr)
//    {
//        arbint[nod] += pct_bonus;
//        return;
//    }
//
//    int mij = (valSt + valDr) / 2;
//    if (poz <= mij) bonus(2*nod, valSt, mij, poz , pct_bonus);
//    if (mij < poz) bonus(2*nod+1, mij+1, valDr,poz, pct_bonus);
//
//    arbint[nod] = max(arbint[2*nod],arbint[2*nod + 1]);
//}
//
//int main(int argc, const char * argv[]) {
//    input>>n>>m;
//    for (int i = 1; i <=n; i++)
//    {
//        input>>nota;
//        build(1,1,n,i,nota);
//    }
//    for(int i = 1; i<=2*n; i++)
//    cout<<arbint[i]<<" ";
//    cout<<"\n";
//
//    for (int i = 1; i <= m; i++)
//    {
//        input>>op>>intervSt>>intervDr;
//        if (op == 1)
//        {
//            int maxim = -1;
//            query(1,1,n,intervSt, intervDr, maxim);
//            output<<maxim<<"\n";
//        }
//        else
//        {
//            input>>pct_bonus;
//            for (int poz = intervSt; poz <= intervDr; poz++)
//                bonus(1,1,n,poz, pct_bonus);
//            for(int i = 1; i<=2*n; i++)
//            cout<<arbint[i]<<" ";
//            cout<<"\n";
//        }
//    }
//}
