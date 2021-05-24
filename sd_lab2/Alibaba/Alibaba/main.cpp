#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

 
using namespace std;
 
ifstream input("alibaba.in");
ofstream output("alibaba.out");
 
int n, k;
vector<int> sol_final;
stack<int> solutie;
string val;
 
 
int main(int argc, const char * argv[]) {
    input>>n>>k;
    input>>val;
 
    for (int i = 0; i < n; i++)
    {
        if (solutie.empty())
            solutie.push(val[0] - '0');
        else
        {
            while (!solutie.empty() && solutie.top() < (val[i] - '0') && k) {
                solutie.pop();
                k--;
            }
            solutie.push(val[i] - '0');
        }
    }

    while (k && !solutie.empty())
    {
        k--;
        solutie.pop();
    }
    
    while (!solutie.empty()){
        sol_final.push_back(solutie.top());
        solutie.pop();
    }
    
    for (int i = sol_final.size() - 1 ; i >= 0; i--)
        output<<sol_final[i];
    
}
