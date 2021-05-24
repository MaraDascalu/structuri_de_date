//
//  main.cpp
//  Timbre
//
//  Created by Mara Dascalu on 14/04/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

ifstream input("timbre.in");
ofstream output("timbre.out");

vector<pair<int, int>> vec;
int n, m, k, x, y;

int main(int argc, const char * argv[]) {
    input>>n>>m>>k;

    for (int i = 0; i < m; i++){
        input>>x>>y;
        vec.push_back({y, x});
    }
    make_heap(vec.begin(), vec.end());
    sort_heap(vec.begin(), vec.end());

    int nr_curent = n;
    long long cost = 0;
    for (int i = 0; i < m && nr_curent > 0; i++){
        cost += vec[i].first;
        nr_curent -= k;
    }
    output<<cost;
}
