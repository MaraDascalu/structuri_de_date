//
//  main.cpp
//  Stramosi
//
//  Created by Mara Dascalu on 21/05/2021.
//

#include <iostream>
#include <fstream>
 
using namespace std;

ifstream input("stramosi.in");
ofstream output("stramosi.out");
 
const int n_max = 250000;
int n, m, ordin, nod, stramosi[19][n_max+1];

void aflaStramosi()
{
    int range = 4;
    for (int i = 2; range <= n; i++)
    {
        range *= 2;
//        cout<<i<<" "<<range<<" "<<n<<"\n";
        for (int j = 1; j <= n; j++)
            stramosi[i][j] = stramosi[i-1][stramosi[1][j]];
    }
}

int main(){
    input>>n>>m;
    for (int i = 1; i <= n; i++)
        input>>stramosi[1][i];
    aflaStramosi();
//    for (int i=1, range = 2; range <= n; i++, range *= 2)
//    {
//        for (int j = 1; j <= n; j++)
//        cout<<stramosi[i][j]<<" ";
//        cout<<"\n";
//    }
    for (int i = 1; i <= m; i++)
    {
        input>>nod>>ordin;
        output<<stramosi[ordin][nod]<<"\n";
    }
}
