// Problema: https://imgur.com/a/RIkQHkx
// Solución por manejo de Strings
// Entradas:
    /*
    Caso 1:
        "abbcccc"
    Caso 2: 
        "abcd"
    Caso 3: 
        "aaaa"
    */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int options = 1;
        for(int l = 0, i = 1; i < word.length(); i++, l++){ // aaaaa
            if (word[l] != word[i]) options--;
            options++;
        }
        return options;
    }
};

int main (void){
    Solution caso;
    cout << caso.possibleStringCount("abbcccc") << endl;
    cout << caso.possibleStringCount("abcd") << endl;
    cout << caso.possibleStringCount("aaaa") << endl;
    return 0;
}