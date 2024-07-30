// Problema: https://imgur.com/a/ykQ8do7
// Solución por Stack
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
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.length(), cuenta = 0;
        stack<int>pila;
        for(int i = 0; i < size; i++){
            if(!pila.empty() && s[i] == 'a' && pila.top() == 'b'){
                pila.pop();
                cuenta++;
            }else pila.push(s[i]);
        }
        return cuenta;
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