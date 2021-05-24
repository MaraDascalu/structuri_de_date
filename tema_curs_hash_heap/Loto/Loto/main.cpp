//
//  main.cpp
//  Loto
//
//  Created by Mara Dascalu on 07/04/2021.
//


//
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>
using namespace std;

ifstream input("loto.in");
ofstream output("loto.out");

unordered_map<int, tuple<int, int, int>> v_hash;
int nr, suma;
int v[101];
bool gasit;

int main(){
    input>>nr>>suma;
    for (int i = 0; i < nr; i++)
        input>>v[i];
    for (int i = 0; i < nr; i++)
        for (int j = i ; j < nr; j++)
            for (int k = j ; k < nr; k++)
                if (v[i] + v[j] + v[k] <= suma)
                v_hash[v[i] + v[j] + v[k]] = {v[i], v[j], v[k]};


    for (int l = 0; l < nr && !gasit; l++)
        for (int m = 0; m < nr && !gasit; m++)
            for (int n = 0; n < nr && !gasit; n++)
            {
                int s = v[l] + v[m] + v[n];
                s = suma - s;
                if (v_hash.find(s) != v_hash.end())
                {
                    output<<v[l]<<" "<<v[m]<<" "<<v[n]<<" "<<get<0>(v_hash[s])<<" "<<get<1>(v_hash[s])<<" "<<get<2>(v_hash[s]);
                    gasit = 1;
                }
            }
    if (!gasit) output<<-1;

}

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <tuple>
//#include <utility>
//#include <unordered_map>
//
//using namespace std;
//
//ifstream input("loto.in");
//ofstream output("loto.out");
//
//
//unordered_map<int, tuple<int, int, int>> vhash;
//bool gasit;
//int vec[101];
//int nr, suma;
//int main() {
//    input>>nr>>suma;
//    for(int i = 0; i < nr; i ++)
//        input>>vec[i];
//
//    for(int i = 0; i < nr; i++)
//        for(int j = i; j < nr; j++)
//            for(int k  = j; k < nr; k ++) {
//                vhash[vec[i] + vec[j] + vec[k]] = make_tuple(vec[i], vec[j], vec[k]);
//            }
//    for(int a = 0; a < nr && !gasit; a++)
//        for(int b = a; b < nr && !gasit; b++)
//            for (int c = b; c < nr && !gasit; c++)
//                if (vhash.find(suma - (vec[a] + vec[b] + vec[c])) != vhash.end()) {
//                    output<< nr[d] << " " << nr[e] << " " << nr[f]<< " "<<get<0>(vhash[S - (nr[d] + nr[e] + nr[f])]) << " "
//                    << get<1>(vhash[S - (nr[d] + nr[e] + nr[f])]) << " "
//                    << get<2>(vhash[S - (nr[d] + nr[e] + nr[f])]) << "\n";
//                    gasit = 1;
//                }
//    if (!gasit)
//        output<<-1;
//
//    return 0;
//}
