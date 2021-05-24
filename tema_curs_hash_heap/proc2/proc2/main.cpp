//
//  main.cpp
//  proc2
//
//  Created by Mara Dascalu on 17/04/2021.
//

#include<bits/stdc++.h> 
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


ifstream input("proc2.in");
ofstream output("proc2.out");

int n, m, inceput, durata, gata, liber;
priority_queue<pair<int, int>>proc_folosit;
priority_queue<int> proc_liber;

int main(int argc, const char * argv[]) {
    input>>n>>m;
    for (int i = 1; i <= n; i++)
        proc_liber.push(-i);
    
    for (int i = 0; i < m; i++)
    {
        input>>inceput>>durata;
        while (!proc_folosit.empty() && -proc_folosit.top().first <= inceput)
        {
            gata = proc_folosit.top().second;
            proc_folosit.pop();
            proc_liber.push(gata);
        }
        
        liber = proc_liber.top();
        proc_liber.pop();
        output<<-liber<<"\n";
        proc_folosit.push({-(durata + inceput), liber});
    }
    
}
