//
//  main.cpp
//  Zeap
//
//  Created by Mara Dascalu on 14/05/2021.
//

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

ifstream input("zeap.in");
ofstream output("zeap.out");

string operatie;
int val, dif_min;
set<int> zeap;
int main(int argc, const char * argv[]) {
    while (input>>operatie)
    {
        if (operatie == "I")
        {
            input>>val;
            zeap.insert(val);
        }
        else if (operatie == "S"){
            input>>val;
            int rez = zeap.erase(val);
            if (!rez) output<<-1<<"\n";
        }
            else if (operatie == "C")
            {
                input>>val;
                auto itr = zeap.find(val);
                if (*itr == val) output<<1<<"\n";
                else output<<0<<"\n";
            }
                else if (operatie == "MAX"){
                    auto itr = zeap.begin();
                    auto itr2 = zeap.end(); itr2--;
                    output<<*itr2 - *itr<<"\n";
                }
                    else{
                        auto itr = zeap.end(); itr--;
                        dif_min = *itr;
                        for (auto itr2 = zeap.begin(); itr2 != itr;)
                        {
                            int dif_curr = abs(*itr2 - *(++itr2));
                            if (dif_min > dif_curr) dif_min = dif_curr;
                        }
                        output<<dif_min<<"\n";
                    }

    }
//    zeap.insert(10);
//    zeap.insert(5);
//    zeap.insert(19);
//    zeap.insert(224);
//    for (auto itr = zeap.begin(); itr != zeap.end(); itr++)
//        cout<<*itr<<" ";
//    val = zeap.erase(19);
//    cout<<val<<"\n";
//    for (auto itr = zeap.begin(); itr != zeap.end(); itr++)
//        cout<<*itr<<" ";
//    auto it = zeap.find(2343);
//    cout<<*it;
}
