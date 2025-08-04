// Problema: https://imgur.com/a/YkanSAr
// Solución Sliding Window
// Entradas:
    /*
    Caso 1:
    [1,2,1]
    Caso 2: 
    [0,1,2,2]
    Caso 3:
    [1,2,3,2,2]
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, best = -1, size = fruits.size();
        // Variables que indican el tipo de fruta que almacena la canasta-
        int bas1 = -1, bas2 = -1;
        for(int right = 0; right < size; right++){
            // El arbol tiene frutas que no se han clasificado en las canastas
            if(fruits[right] != bas1 && fruits[right] != bas2){
                // Se agrega a la canasta (Si se puede)
                if(bas1 == -1) bas1 = fruits[right]; // Canasta 1
                else if(bas2 == -1) bas2 = fruits[right]; // Canasta 2
                else{
                    // NO SE PUEDE AGREGAR (Canastas llenas)
                    // Se quitan las frutas que no formen parte del ultimo arbol revisado
                    bas1 = fruits[right]; // Nuevo arbol
                    bas2 = fruits[right-1]; // Arbol previamente revisado
                    left = right-1; // Se guarda la posicion
                    while(fruits[left-1] == bas2) left--; // Hasta el ultimo arbol del mismo tipo
                }
            }
            // Se valida la mejor distancia (mas arboles)
            best = max(best, right - left + 1);
        }
        // cout << best << endl;
        return best;
    }
};

int main (void){
    Solution casoP;
    vector<int> v1 = {1,2,1}, v2 = {0,1,2,2}, v3 = {1,2,3,2,2};
    cout << casoP.totalFruit(v1) << endl;
    cout << casoP.totalFruit(v2) << endl;
    cout << casoP.totalFruit(v3) << endl;
    return 0;
}