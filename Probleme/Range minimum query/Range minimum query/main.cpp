//
//  main.cpp
//  Range minimum query
//
//  Created by Mara Dascalu on 19/05/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input("rmq.in");
ofstream output("rmq.out");

const int n_max = 100005;
int n, m, rmq[20][n_max], lg[n_max],x, y;

int main(){
    input>>n>>m;
    for (int i = 1; i <= n; i++)
        input>>rmq[0][i];

    //calculam log2 pentru numerele de la 1 la n
    for (int i = 2; i <= n_max; i++)
        lg[i] = lg[i/2] + 1;

    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1<<(i-1))]);// selectam minimul dintre minimul din prima parte a intervalului si minimul din cea de a doua

    for (int i = 1; i <= m; i++)
    {
        input>>x>>y;
        int poz = lg[y-x+1];//calculam linia din matrice
        output<<min(rmq[poz][x], rmq[poz][y - (1 << poz)+1])<<"\n";// minimul dintre minimele celor 2 intervale de lungime x
    }
}

//const int n_max = 100000;
//int n,m, intervSt, intervDr, val, arbint[n_max*4+1], val_max;
//
//void build(int nod, int valSt, int valDr, int poz, int val){
//    if (valSt == valDr)
//    {
//        arbint[nod] = val;
//        return;
//    }
//    int mij = (valSt + valDr) / 2;
//    if (poz <= mij)
//        build(2*nod, valSt, mij, poz, val);
//    else build(2*nod+1, mij + 1, valDr, poz, val);
//
//    arbint[nod] = min(arbint[2*nod], arbint[2*nod+1]);
//}
//
//void query (int nod, int valSt, int valDr, int limitaSt, int limitaDr, int& minim){
//    if (limitaSt <= valSt && valDr <= limitaDr){
//        if (minim >= arbint[nod]) minim = arbint[nod];
//        return;
//    }
//        int mij = (valSt + valDr) / 2;
//        if (limitaSt <= mij)
//            query(2*nod, valSt, mij, limitaSt, limitaDr, minim);
//        if (mij < limitaDr)
//            query(2*nod+1, mij+1, valDr, limitaSt, limitaDr, minim);
//
//}
//
//int main(int argc, const char * argv[]) {
//    input>>n>>m;
//    for (int i = 1; i <= n; i++)
//    {
//        input>>val;
//        if (val > val_max) val_max = val;
//        build(1,1,n,i,val);
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        input>>intervSt>>intervDr;
//        int min = val_max;
//        query(1,1,n,intervSt,intervDr, min);
//        output<<min<<"\n";
//    }
//
//}
