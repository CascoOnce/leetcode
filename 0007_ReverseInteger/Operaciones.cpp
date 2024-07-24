// Problema: https://imgur.com/a/9Rpu8CT
// Solución por matematicas
// Entradas:
    /*
    Caso 1:
    123
    Caso 2: 
    -123
    Caso 3: 
    -120
    */

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x != 0){
            if (reverse > INT_MAX/10 || reverse < INT_MIN/10) return 0;
            reverse = (reverse*10) + x %10;
            x = x / 10;
        }
        return reverse;
    }
};

int main (void){
    Solution caso;
    cout << 123 << "->" << caso.reverse(123) << endl;
    cout << -123 << "->" << caso.reverse(-123) << endl;
    cout << 120 << "->" << caso.reverse(120) << endl;
    cout << 1534236469 << "->" << caso.reverse(1534236469) << endl;
    return 0;
}