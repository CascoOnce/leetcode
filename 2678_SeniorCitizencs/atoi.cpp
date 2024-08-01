// Problema: https://imgur.com/a/GQZ2zes
// Solución por atoi
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
        int size = details.size(), senior = 0, edad;
        for(int i = 0; i < size; i++){
            char *number = new char[3]{};
            string cadena = details[i];
            number[0] = cadena[11];
            number[1] = cadena[12];
            edad = atoi(number);
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