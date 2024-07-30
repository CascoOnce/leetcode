// Problema: https://imgur.com/a/ykQ8do7
// Solución Fuerza Bruta Optimizada
// Entradas:
    /*
    Caso 1:
    "aababbab"
    Caso 2: 
    "bbaaaaabb"
    Caso 3:
    "aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa"
    */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.length(), bs = 0, maximo = 0;
        for(int i = 0; i < size; i++){
            if(s[i] == 'b') bs++;
            else maximo = min(maximo + 1, bs);
        }
        return maximo;
    }
};

int main (void){
    Solution caso;
    cout << caso.minimumDeletions("aababbab") << endl; //CASO_1
    cout << caso.minimumDeletions("bbaaaaabb") << endl; //CASO_2
    cout << caso.minimumDeletions("b") << endl; //CASO_3
    cout << caso.minimumDeletions("aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa") << endl; //CASO_4
    return 0;
}