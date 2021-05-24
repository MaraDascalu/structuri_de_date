//
//  main.cpp
//  Pariuri
//
//  Created by Mara Dascalu on 09/04/2021.
//

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream input("pariuri.in");
ofstream output("pariuri.out");

unordered_map<int, int> v_hash;
int n, m, timp, bani;

int main()
{
    input>>n;
    for (int i = 0; i < n; i++)
    {
        input>>m;
        for (int j = 0 ; j < m ; j++)
        {
            input>>timp>>bani;
            if (v_hash.find(timp) == v_hash.end())
                v_hash[timp] = bani;
            else v_hash[timp] += bani;
        }
    }
    output<<v_hash.size()<<"\n";
    for (auto i = v_hash.begin() ; i != v_hash.end(); i++)
        output<<i -> first<<" "<<i -> second<<" ";
}

