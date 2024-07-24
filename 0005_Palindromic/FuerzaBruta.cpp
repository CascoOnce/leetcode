// Problema: https://imgur.com/a/s8b1BYG
// Solución por Fuerza Bruta
// Entradas:
    /*
    Caso 1:
    "babad";
    Caso 2: 
    "cbbd";
    */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int mayIni = 1, mayFin = 0, size = s.length();
        for(int i = 0; i < size; i++){
            for (int j = i; j < size; j++){
                if(esPalindromo(s, i, j) && j-i>mayFin-mayIni){
                    mayIni = i;
                    mayFin = j;
                }
            }
        }
        return s.substr(mayIni, mayFin - mayIni + 1);
        string palabra;
        // for(int i = mayIni; i <= mayFin; i++) palabra += s[i];
        // return palabra;
    }
    bool esPalindromo(string s, int ini, int fin){
        while(ini <= fin) if (s[ini++] != s[fin--]) return false;
        return true;
    }
};

int main (void){
    Solution caso;
    cout << caso.longestPalindrome("babad") << endl;
    cout << caso.longestPalindrome("cbbd") << endl;
    cout << caso.longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx") << endl;
    return 0;
}