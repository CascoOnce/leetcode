// Problema: https://imgur.com/a/VM2JswA
// Solución por cadena
// Entradas:
    /*
    Caso 1:
    121
    Caso 2: 
    -121
    Caso 3: 
    10
    */

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string numero = "";
        while(x != 0){
            numero = (char)((x%10) + '0') +  numero;
            x /= 10;
        }
        int size = numero.size();
        for(int i = 0; i < size/2; i++) if(numero[i] != numero[size-i-1]) return false;
        return true;
    }
};

int main (void){
    Solution caso;
    cout << caso.isPalindrome(121) << endl; // Caso 1;
    cout << caso.isPalindrome(-121) << endl; // Caso 1;
    cout << caso.isPalindrome(10) << endl; // Caso 1;
    return 0;
}