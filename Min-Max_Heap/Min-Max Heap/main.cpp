//
//  main.cpp
//  Min-Max Heap
//
//  Created by Mara Dascalu on 23/05/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("min-max.in");
ofstream output("min-max.out");

vector<int> MinMaxHeap;
int nrop, nrvalori, op, val, dimheap;

int level(int val){
    int level = 0, range = 1;
    while (range <= val)
    {
        level++;
        range *= 2;
    }
    return level - 1;
}

void pushDownMin(int val)
{
    if (val*2 <= dimheap)  //verificam daca nodul curent are copii
    {
        int poz_min;
        if (val*2 + 1 <= dimheap)
            if (MinMaxHeap[val*2 - 1] < MinMaxHeap[val*2]) poz_min = val*2; // calculam indicele celui mai mic copil
            else poz_min = val*2 + 1;
        else poz_min = val*2;
        
        bool isGrandChild = 0;
        
        if (val*4 <= dimheap) //calculam indicele celui mai mic nepot, daca exista
        {
            if (MinMaxHeap[poz_min - 1] > MinMaxHeap[val*4 - 1]){ //daca ne aflam pe un nivel par k, stranepotul lui k trebuie sa fie mai mic decat nepotul lui k
                poz_min = val*4;
                isGrandChild  = 1;
            }
             if (val*4 + 1 <= dimheap)
                 if (MinMaxHeap[poz_min - 1] > MinMaxHeap[val*4]){
                     poz_min = val*4 + 1;
                     isGrandChild  = 1;
                 }
        }
        if ((val*2 + 1) * 2 <= dimheap) //calculam indicele celui mai mic nepot, daca exista
        {
            if (MinMaxHeap[poz_min - 1] > MinMaxHeap[(val*2 + 1) * 2 - 1]){ //daca ne aflam pe un nivel par k, stranepotul lui k trebuie sa fie mai mic decat nepotul lui k
                poz_min = (val*2 + 1) * 2;
                isGrandChild  = 1;
            }
             if ((val*2 + 1) * 2 + 1 <= dimheap)
                 if (MinMaxHeap[poz_min - 1] > MinMaxHeap[(val*2 + 1) * 2]){
                     poz_min = (val*2 + 1) * 2 + 1;
                     isGrandChild  = 1;
                 }
        }
        
        if (isGrandChild)
        {
            if (MinMaxHeap[poz_min - 1] < MinMaxHeap[val - 1])
            {
                swap(MinMaxHeap[poz_min - 1], MinMaxHeap[val - 1]);
                if (MinMaxHeap[poz_min - 1] > MinMaxHeap[poz_min/2 - 1])
                    swap(MinMaxHeap[poz_min - 1], MinMaxHeap[poz_min/2 - 1]);
                pushDownMin(poz_min);
            }
        }
        else if (MinMaxHeap[poz_min - 1] < MinMaxHeap[val - 1]){
            swap(MinMaxHeap[poz_min - 1], MinMaxHeap[val - 1]);
        }
    }
}

void pushDownMax(int val)
{
    if (val*2 <= dimheap)  //verificam daca nodul curent are copii
    {
        int poz_max;
        if (val*2 + 1 <= dimheap)
            if (MinMaxHeap[val*2 - 1] > MinMaxHeap[val*2]) poz_max = val*2; // calculam indicele celui mai mic copil
            else poz_max = val*2 + 1;
        else poz_max = val*2;
        
        bool isGrandChild = 0;
        
        if (val*4 <= dimheap) //calculam indicele celui mai mic nepot, daca exista
        {
            if (MinMaxHeap[poz_max - 1] < MinMaxHeap[val*4 - 1]){ //daca ne aflam pe un nivel impar k, stranepotul lui k trebuie sa fie mai mare decat nepotul lui k
                poz_max = val*4;
                isGrandChild  = 1;
            }
             if (val*4 + 1 <= dimheap)
                 if (MinMaxHeap[poz_max - 1] < MinMaxHeap[val*4]){
                     poz_max = val*4 + 1;
                     isGrandChild  = 1;
                 }
        }
        if ((val*2 + 1) * 2 <= dimheap) //calculam indicele celui mai mic nepot, daca exista
        {
            if (MinMaxHeap[poz_max - 1] < MinMaxHeap[(val*2 + 1) * 2 - 1]){ //daca ne aflam pe un nivel par k, stranepotul lui k trebuie sa fie mai mic decat nepotul lui k
                poz_max = (val*2 + 1) * 2;
                isGrandChild  = 1;
            }
             if ((val*2 + 1) * 2 + 1 <= dimheap)
                 if (MinMaxHeap[poz_max - 1] < MinMaxHeap[(val*2 + 1) * 2]){
                     poz_max = (val*2 + 1) * 2 + 1;
                     isGrandChild  = 1;
                 }
        }
        
        if (isGrandChild)
        {
            if (MinMaxHeap[poz_max - 1] > MinMaxHeap[val - 1])
            {
                swap(MinMaxHeap[poz_max - 1], MinMaxHeap[val - 1]);
                if (MinMaxHeap[poz_max - 1] < MinMaxHeap[poz_max/2 - 1])
                    swap(MinMaxHeap[poz_max - 1], MinMaxHeap[poz_max/2 - 1]);
                pushDownMax(poz_max);
            }
        }
        else if (MinMaxHeap[poz_max - 1] > MinMaxHeap[val - 1]){
            swap(MinMaxHeap[poz_max - 1], MinMaxHeap[val - 1]);
        }
    }
}

void pushDown(int val){
    if (!level(val)%2) pushDownMin(val);
    else pushDownMax(val);
}

void build(int dim)
{
    for (int i = dim/2; i >= 1; i--)
        pushDown(i);
}


void pushUpMin(int idx){
    if (idx/4 && MinMaxHeap[idx - 1] < MinMaxHeap[idx/4 - 1])
    {
        swap(MinMaxHeap[idx - 1], MinMaxHeap[idx/4 - 1]);
        pushUpMin(idx/4);
    }
}

void pushUpMax(int idx){
    if (idx/4 && MinMaxHeap[idx - 1] > MinMaxHeap[idx/4 - 1])
    {
        swap(MinMaxHeap[idx - 1], MinMaxHeap[idx/4 - 1]);
        pushUpMax(idx/4);
    }
}

void pushUp(int idx)
{
    if (idx != 1)
    {
        if (!level(idx)%2)
        {
            if (MinMaxHeap[idx - 1] > MinMaxHeap[idx/2 - 1])
            {
                swap(MinMaxHeap[idx - 1], MinMaxHeap[idx/2 - 1]);
                pushUpMax(MinMaxHeap[idx/2]);
            }
            else pushUpMin(idx);
        }
        else {
            if (MinMaxHeap[idx - 1] < MinMaxHeap[idx/2 - 1])
            {
                swap(MinMaxHeap[idx - 1], MinMaxHeap[idx/2 - 1]);
                pushUpMin(MinMaxHeap[idx/2]);
            }
            else pushUpMax(idx);
        }
    }
}

void insert(int val){
    MinMaxHeap.push_back(val);
    dimheap++;
    pushUp(dimheap);
}

void printMin()
{
    output<<MinMaxHeap[0]<<"\n";
}
void printMax()
{
    if (dimheap == 1) output<<MinMaxHeap[0]<<"\n";
    else if (dimheap == 2) output<<MinMaxHeap[1]<<"\n";
    else output<<max(MinMaxHeap[1], MinMaxHeap[2])<<"\n";
}

void deleteMin()
{
    if (dimheap == 1) dimheap = 0;
    else {
        MinMaxHeap[0] = MinMaxHeap[dimheap - 1];
        dimheap--;
        pushDown(1);
    }
}

void deleteMax()
{
    if (dimheap <= 2) dimheap--;
    else
    {
        int poz_max;
        if (MinMaxHeap[1] > MinMaxHeap[2]) poz_max = 2;
        else poz_max = 3;
        MinMaxHeap[poz_max - 1] = MinMaxHeap[dimheap - 1];
        dimheap--;
        pushDown(poz_max);
    }
}

int main(int argc, const char * argv[]) {
    input>>nrop;
    
    for (int i = 1; i <= nrop; i++)
    {
        input>>op;
        if (op == 1)
        {
            input>>val;
            insert(val);
        }
        else if (op == 2)
        {
            if (!dimheap) cout<<"Eroare! Nu avem suficiente valori\n";
            else deleteMin();
        }
        else if (op == 3){
            if (!dimheap) cout<<"Eroare! Nu avem suficiente valori\n";
            else deleteMin();
        }
        else if (op == 4){
            if (!dimheap) cout<<"Eroare! Nu avem suficiente valori\n";
            else printMin();
        }
        else if (op == 5){
            if (!dimheap) cout<<"Eroare! Nu avem suficiente valori\n";
            else printMax();
        }
        else if (op == 6){
            input>>nrvalori;
            dimheap = nrvalori;
            for (int i = 1; i <= nrvalori; i++)
            {
                input>>val;
                MinMaxHeap.push_back(val);
            }
            build(dimheap);
        }
    }
}
