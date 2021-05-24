//
//  main.cpp
//  Sortare_prin_comparare
//
//  Created by Mara Dascalu on 07/04/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("algsort.in");
ofstream output("algsort.out");

int v[500001];
int n;

void coboara(int v[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < n && v[largest] < v[left])
        largest = left;
    if (right < n && v[largest] < v[right])
        largest = right;
    if (largest != i)
    {
        swap(v[largest], v[i]);
        coboara(v, n, largest);
    }
}

void heapSort (int v[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
        coboara(v, n, i);
    for (int i = n - 1; i > 0 ; i--)
    {
        swap(v[0], v[i]);
        coboara(v, i, 0);
    }
    
}

int main(int argc, const char * argv[]) {
    input>>n;
    for (int i = 0; i < n; i++)
        input>>v[i];
//    for (int i = 0; i < n; i++)
//        cout<<v[i]<<" ";
    
    heapSort(v, n);
    
    for (int i = 0; i < n; i++)
        output<<v[i]<<" ";
    
}
