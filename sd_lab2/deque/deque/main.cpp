//
//  main.cpp
//  deque
//
//  Created by Mara Dascalu on 15/03/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream input("deque.in");
ofstream output("deque.out");

int n, k, st, dr, v[5000001], deq[5000001];
long long  sum = 0;

int main()
{
    input>>n>>k;
    for (int i = 1; i <= n; ++i)
        input>>v[i];
    st = 1;
    dr = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (st <= dr && v[i] < v[deq[dr]]) --dr;
        deq[++dr] = i;
        if (i - k == deq[st] && st <= dr) ++st;
        if(i >= k) sum += v[deq[st]];
    }
    cout<<sum;
//    output<<sum;
}
