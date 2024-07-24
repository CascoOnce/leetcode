// Problema: https://imgur.com/a/WetmFy0
// Solución por string
// Entradas:
    /*
    Caso 1:
    "PAYPALISHIRING" / 3;
    Caso 2: 
    "PAYPALISHIRING" / 4;
    */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>letras(numRows);
        int size = s.length();
        for(int i = 0; i < numRows; i++) letras[i] = "";
        int j = 0, desc = 1;
        for(int i = 0; i < size; i++){
            if(numRows > 1){
                if (j == numRows - 1) desc = -1;
                if (j == 0) desc = 1;
            }else desc = 0;
            letras[j] += s[i];
            j += desc;
        }
        string convertido = "";
        for(int i = 0; i < numRows; i++){
            convertido += letras[i];
        }
        return convertido;
    }
};

int main (void){
    Solution caso;
    cout << caso.convert("PAYPALISHIRING", 3) << endl;
    cout << caso.convert("PAYPALISHIRING", 4) << endl;
    cout << caso.convert("A", 1) << endl;
    cout << caso.convert("AB", 1) << endl;
    return 0;
}