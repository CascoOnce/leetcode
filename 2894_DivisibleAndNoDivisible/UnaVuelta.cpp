// Problema: https://imgur.com/a/GW4SM6Q
// Solución por logic
// Entradas:
    /*
    Caso 1:
    n = 10, m = 3;
    Caso 2: 
    n = 5, m = 6;
    Caso 2: 
    n = 5, m = 1;
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum = (i % m)? sum + i: sum - i;
        }
        return sum;
    }
};

int main(void){
    Solution caso;
    cout << caso.differenceOfSums(10, 3) << endl;
    cout << caso.differenceOfSums(5, 6) << endl;
    cout << caso.differenceOfSums(5, 1) << endl;
}