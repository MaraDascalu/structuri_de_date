//
//  main.cpp
//  vila_2
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input("vila2.in");
ofstream output("vila2.out");

int n, k, val, v[100001], deq_min[100001], deq_max[100001], st_min = 1, dr_min , st_max = 1, dr_max , maxim, minim, dif_max;

int main()
{
    input>>n>>k;
    for (int i = 1; i <= n; i++)
        input>>v[i];
    input.close();
    
    for (int i = 1; i <= n; i++)
    {
        while (st_min <= dr_min && v[i] <= v[deq_min[dr_min]]) dr_min--;
        deq_min[++dr_min] = i;
        if (i - deq_min[st_min] == k + 1) st_min++;
        minim = v[deq_min[st_min]];
        
        while (st_max <= dr_max && v[i] >= v[deq_max[dr_max]]) dr_max--;
        deq_max[++dr_max] = i;
        if (i - deq_max[st_max] == k + 1) st_max++;
        maxim = v[deq_max[st_max]];
        
        dif_max = max(maxim - minim, dif_max);
    }
    output<<dif_max;
    return 0;
}
