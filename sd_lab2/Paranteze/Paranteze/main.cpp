//
//  main.cpp
//  Paranteze
//
//  Created by Mara Dascalu on 18/03/2021.
//

#include <iostream>
#include <fstream>


using namespace std;

ifstream input("paranteze.in");
ofstream output("paranteze.out");

string sir;
stack <pair<char, int>> paranteze;
int n, l , lmax;
int lungime[1000001];

int main() {
    
    input>> n;
    input>>sir;
    input.close();
    
    for (int i = 0; i < sir.size(); i++)
    {
        if (sir[i] == '(' || sir[i] == '[' || sir[i] == '{')
        {
            paranteze.push({sir[i], i});
        }
        else
            if ( !paranteze.empty() && (paranteze.top().first == '(' && sir[i] ==')' || paranteze.top().first == '[' && sir[i] ==']') || paranteze.top().first == '{' && sir[i] =='}')
            {
                lungime[i] = lungime[paranteze.top().second] = 1;
                paranteze.pop();
            }
            else
                while(!paranteze.empty())
                    paranteze.pop();
            
    }
    
    for (int i = 0 ; i < n; i++)
    {
        if (lungime[i])
        {
            l++;
            lmax = max(lmax, l);
        }
        else l = 0;
    }
    cout<<lmax<<"\n";
//    output<<lmax;
    return 0;
}
