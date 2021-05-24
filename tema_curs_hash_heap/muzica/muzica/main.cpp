#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream input("muzica.in");
ofstream output("muzica.out");
 
const int val_hash = 100003;
vector<int> vhash[val_hash];
int n, m, a, b, c, d, e, melodie, la_fel;
 
bool verificare (int x)
{
    int poz = x % val_hash;
    for (int i = 0; i < vhash[poz].size(); i++)
    {
        if (vhash[poz][i] == x){
            vhash[poz][i] = vhash[poz][vhash[poz].size() - 1];
            vhash[poz].pop_back();
            return true;
        }
            
    }
    return false;
}
 
int main(int argc, const char * argv[]) {
    input>>n>>m;
    input>>a>>b>>c>>d>>e;
    for (int i = 0; i < n; i++)
    {
        input>>melodie;
        vhash[melodie % val_hash].push_back(melodie);
    }
    if (verificare(a)) la_fel++;
    if (verificare(b)) la_fel++;
 
    for (int i = 2; i < m ; i++)
    {
        melodie = (1LL * c * b + 1LL* d * a) % e;
        if (verificare(melodie)) la_fel++;
        a = b;
        b = melodie;
    }
    output<<la_fel;
}
