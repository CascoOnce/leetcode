// Problema: https://imgur.com/a/mR6BE1k
// Solución a Fuerza Bruta
// Entradas:
    /*
    Caso 1:
    [2,7,11,15] / target = 9;
    Caso 2: 
    [3,2,4] / target = 6
    Caso 3:
    [3,3] / target = 6
    */

#include <vector>
#include <iostream>
using namespace std;

class Solucion {
public:
    vector <int> twoSum (vector<int>& nums, int target) {
        vector<int>two;
        int ai, aj, size = nums.size();
        for (int i = 0; i < size - 1; i++){
            ai = nums.at(i);
            for (int j = i + 1; j < size; j++){
                aj = nums.at(j);
                if (ai + aj == target){
                    two.push_back(i);
                    two.push_back(j);
                }
            }
        }
        return two;
    }
};

int main (void){
    Solucion caso1, caso2, caso3;
    // Caso 1:
    vector <int> acaso1 = {2,7,11,15};
    vector <int> vcaso1 = caso1.twoSum(acaso1 , 9);
    for(auto ind:vcaso1) cout << ind << ' ';
    cout << endl;
    // Caso 2:
    vector <int> acaso2 = {3,2,4};
    vector <int> vcaso2 = caso2.twoSum(acaso2 , 6);
    for(auto ind:vcaso2) cout << ind << ' ';
    cout << endl;
    // Caso 3:
    vector <int> acaso3 = {3,3};
    vector <int> vcaso3 = caso3.twoSum(acaso3 , 6);
    for(auto ind:vcaso3) cout << ind << ' ';
    cout << endl;
    return 0;
}