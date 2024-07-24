// Problema: https://imgur.com/a/WkRjHKL
// Solución con Hash para cada letra
// Entradas: 
    /*
    Caso 1:
    abcabcbb
    Caso 2:
    bbbbb
    Caso 3:
    pwwkew
    */

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> hash;
        hash[s[0]] = 0;
        int Mini = 0, Mfin = 0, ini = 0, fin = 0, size = s.length();
        if (size == 0) return 0;
        for(int i = 1; i < size; i++){
            if (hash.find(s[i]) != hash.end()){
                int posVal = hash[s[i]];
                if (posVal >= ini) ini = posVal + 1;
            }
            hash[s[i]] = i;
            fin++;
            if (fin - ini> Mfin - Mini){
                Mini = ini;
                Mfin = fin;
            }
        }
        return Mfin - Mini + 1;
    }
};

int main (void){
    Solution caso1, caso2, caso3;
    string s1, s2, s3;
//CASO 1:
    s1 = "abcabcbb";
    cout << caso1.lengthOfLongestSubstring(s1);
    cout << endl;
// CASO 2:
    s2 = "bbbbb";
    cout << caso2.lengthOfLongestSubstring(s2);
    cout << endl;
// CASO 3:
    s3 = "pwwkew";
    cout << caso3.lengthOfLongestSubstring(s3);
    cout << endl;
    return 0;
}