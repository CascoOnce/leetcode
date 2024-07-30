// Problema: https://imgur.com/a/ykQ8do7
// Solución Fuerza Bruta con Pilas
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
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size();
        stack<int>a, b;
        for(int i = 0, j = size-1; i < size && j >= 0; i++, j--){
            if(s[i] == 'a') a.push(i);
            if(s[j] == 'b') b.push(j);  
        }
        int minimo = min(b.size(), a.size()), sizeB = b.size(), bfueras = 0;
        while(!b.empty()){
            int index = b.top(), changes = 0 + bfueras;
            stack<int> aux = a;
            while(!aux.empty() && index <= aux.top()) aux.pop(), changes++;
            if(changes < minimo) minimo = changes;
            b.pop();
            bfueras++;
        }
        return minimo;
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