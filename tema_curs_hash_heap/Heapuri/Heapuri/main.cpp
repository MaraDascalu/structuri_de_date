//
//  main.cpp
//  Heapuri
//
//  Created by Mara Dascalu on 12/04/2021.
//

#include <iostream>
#include <fstream>
#include <set>


using namespace std;

ifstream input("heapuri.in");
ofstream output("heapuri.out");

set<int> heap;
int poz[200001], n, op, ins, val;

int main(int argc, const char * argv[]) {
    input>>n;

    for (int i = 0; i < n;  i++){
        input>>op;
        if (op == 1)
        {
            input>>val;
            poz[++ins] = val;
            heap.insert(val);
        }
        else if (op == 2)
            {
                input>>val;
                heap.erase(poz[val]);
            }
        else {
                output<<*heap.begin()<<"\n";
            }
        }
}
