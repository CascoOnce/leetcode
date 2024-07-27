// Problema: https://imgur.com/a/1R47Pnc
// Solución por matematicas
// Entradas:
    /*
    Caso 1:
    "42"
    Caso 2: 
    "   -042"
    Caso 3: 
    "1337c0d3"
    Caso 4: 
    "0-1"
    Caso 5: 
    "words and 987"
    Caso 6: 
    "-91283472332"
    */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        char *c = new char[s.size()+1];
        for(int i = 0; i < s.size(); i++){
            c[i] = s[i];
        }
        long long valor = atol(c);
        if(valor > INT_MAX) valor = INT_MAX;
        else if(valor < INT_MIN) valor = INT_MIN;
        return valor;
    }
};

int main (void){
    Solution caso;
    cout << caso.myAtoi("42") << endl;
    cout << caso.myAtoi("   -042") << endl;
    cout << caso.myAtoi("1337c0d3") << endl;
    cout << caso.myAtoi("0-1") << endl;
    cout << caso.myAtoi("words and 987") << endl;
    cout << caso.myAtoi("-91283472332") << endl;
    return 0;
}