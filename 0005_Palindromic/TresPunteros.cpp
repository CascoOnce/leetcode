// Problema: https://imgur.com/a/s8b1BYG
// Solución por Uso de 3 punteros
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
        string palabra = "";
        int size = s.length();
        if (size == 0) return "";
        int mayIni = 0, mayFin = 0;
        char first, second, third;
        for (int i = 2; i <= size; i++){
            third = s[i], second = s[i-1], first = s[i-2];
            if (first != second && third != first);
            else{
                if (first == second) mayorPalindromo(i-2,i-1,s,size,mayIni,mayFin);
                if (first == third) mayorPalindromo(i-2,i,s,size,mayIni,mayFin);
            }
        }
        return s.substr(mayIni, mayFin - mayIni + 1);
    }
    void mayorPalindromo(int ini, int fin, string s, int size, int &mayIni, int & mayFin){
        longitudPalindromo(ini, fin, s, size);
        if (fin - ini > mayFin - mayIni){
            mayFin = fin;
            mayIni = ini;
        }
    }
    void longitudPalindromo(int &ini, int &fin, string s, int size){
        while(true){
            if (ini != 0 && fin != size){
                if (s[ini - 1] != s[fin + 1]) return;
                else ini--, fin++;
            }else return;
        }
    }
};

int main (void){
    Solution caso;
    cout << caso.longestPalindrome("babad") << endl;
    cout << caso.longestPalindrome("cbbd") << endl;
    cout << caso.longestPalindrome("abb") << endl;
    cout << caso.longestPalindrome("aaaa") << endl;
    cout << caso.longestPalindrome("ccc") << endl;
    cout << caso.longestPalindrome("ccd") << endl;
    cout << caso.longestPalindrome("abcda") << endl;
    cout << caso.longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx") << endl;
    return 0;
}