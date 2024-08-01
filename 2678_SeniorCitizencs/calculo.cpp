// Problema: https://imgur.com/a/GQZ2zes
// Solución por calculo
// Entradas:
    /*
    Caso 1:
    {"7868190130M7522","5303914400F9211","9273338290F4010"};
    Caso 2: 
    {"1313579440F2036","2921522980M5644"};
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int countSeniors(vector<string>& details){
        int senior = 0, edad;
        for(int i = 0; i < details.size(); i++){
            edad = (details[i][11]-'0')*10 + (details[i][12]-'0');
            if(edad > 60) senior++;
        }
        return  senior;
    }
};

int main (void){
    Solution caso;
    vector<string> details;
    // Caso_1
    details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << caso.countSeniors(details) << endl;
    // Caso_2
    details = {"1313579440F2036","2921522980M5644"};
    cout << caso.countSeniors(details) << endl;
    return 0;
}