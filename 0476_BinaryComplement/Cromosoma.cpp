// Problema: https://imgur.com/a/p7Ofb9Z
// Solución Cromosoma
// Entradas:
    /*
    Caso 1:
    5
    Caso 2: 
    1
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long number = 0;
        vector<int> cromosoma; 
        while(num != 0){
            cromosoma.push_back(num%2);
            num /= 2;
        }
        long long pos = 1;
        for(int aux: cromosoma){
            if(aux == 0) number += pos;
            pos*=2;
        }
        return number;
    }
};

int main (void){
    Solution caso;
    cout << caso.findComplement(1) << endl;
    return 0;
}