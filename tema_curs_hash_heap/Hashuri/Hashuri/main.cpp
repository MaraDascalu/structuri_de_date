//
//  main.cpp
//  Hashuri
//
//  Created by Mara Dascalu on 11/04/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("hashuri.in");
ofstream output("hashuri.out");

const int val_hash = 666013;
vector<int> vhash[val_hash];
int n, op, val;
bool gasit;

int main(int argc, const char * argv[]) {
    input>>n;
    for (int i = 0; i < n; i++)
    {
        input>>op>>val;
        int poz = val % val_hash;
        gasit = 0;
        if (op == 1)
        {
            for (int i = 0 ; i < vhash[poz].size() && !gasit; i++)
                if (vhash[poz][i] == val)
                    gasit = 1;
    
            if (!gasit)
                vhash[poz].push_back(val);
        }
        if (op == 2)
        {
            for (int i = 0 ; i < vhash[poz].size() && !gasit; i++)
                if (vhash[poz][i] == val){
                    vhash[poz][i] = 0;
                    gasit = 1;
                }
        }
        if(op == 3)
        {
            for (int i = 0 ; i < vhash[poz].size() && !gasit; i++)
                if (vhash[poz][i] == val)
                    gasit = 1;
            if (gasit)
                output<<1<<"\n";
            else output<<0<<"\n";
        }
    }
} 
