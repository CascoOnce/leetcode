// Problema: https://imgur.com/a/WetmFy0
// Solución por Colas
// Entradas:
    /*
    Caso 1:
    "PAYPALISHIRING" / 3;
    Caso 2: 
    "PAYPALISHIRING" / 4;
    */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<queue<char>>letras(numRows);
        int size = s.length();
        int j = 0, desc = 1;
        for(int i = 0; i < size; i++){
            if(numRows > 1){
                if (j == numRows - 1) desc = -1;
                if (j == 0) desc = 1;
            }else desc = 0;
            letras[j].push(s[i]);
            j += desc;
        }
        string convertido = "";
        for(int i = 0; i < numRows; i++){
            queue<char>fila = letras[i];
            while(!fila.empty()){
                convertido += fila.front();
                fila.pop();
            }
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