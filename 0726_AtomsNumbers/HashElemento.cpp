// Problema: https://imgur.com/a/wpGjTON
// Solución Hash Suma Elemento
// Entradas:
    /*
    Caso 1:
    "H2O"; => H2O
    Caso 2: 
    "Mg(OH)2" => H2MgO2
    Caso 3:
    "K4(ON(SO3)2)2" => K4N2O14S4
    */

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int ini = 0, size = formula.size();
        string resultado = "";
        map <string, int> lElementos = listAtomos(ini, size, formula);
        for(auto elemento: lElementos){
            resultado += elemento.first;
            if (elemento.second > 1){
                resultado += numberToString(elemento.second);
            }
        }
        return resultado;
    }
    map <string, int> listAtomos(int &ini, int fin, string formula){
        map <string, int> elementos{};
        string elemento;
        int nElementos = 0, nSub;
        while(ini < fin && formula[ini] != ')'){
            char letter;
            if (formula[ini] == '('){
                map <string, int> subFormula{};
                subFormula = listAtomos(++ini, fin, formula);
                nSub = stringToInt(++ini, fin, formula);
                for (auto sub:subFormula){
                    elementos[sub.first] += sub.second*nSub;
                }
            }else{
                letter = formula[ini];
                elemento = letter;
                if(formula[ini+1] >= 'a' && formula[ini+1] <= 'z'){
                    letter = formula[++ini];
                    elemento += letter;
                }
                nElementos = stringToInt(++ini, fin, formula);
                elementos[elemento] += nElementos;
            }
        }
        return elementos;
    }
    int stringToInt(int &ini, int fin, string formula){
        int n = 0;
        for(; ini < fin && formula[ini] >= '0' && formula[ini] <= '9'; ini++){
            n = n*10 + formula[ini] - '0';
        }
        if (n == 0) return 1;
        else return n;
    }
    string numberToString(int num){
        string number;
        if (num/10 == 0){ //130 => 30
            char caracter = num + '0';
            number = caracter;
            return number;
        }
        return numberToString(num/10) + numberToString(num%10);
    }
};

int main (void){
    Solution casoP;
    cout << casoP.countOfAtoms("H2O") << endl;
    cout << casoP.countOfAtoms("Mg(OH)2") << endl;
    cout << casoP.countOfAtoms("K4(ON(SO3)2)2");
    return 0;
}