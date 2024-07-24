// Problema: https://imgur.com/a/bwXN1zm
// Solución por MergeSort con Pair
// Entradas:
    /*
    Caso 1:
    [8,9,4,0,2,1,3,5,7,6] / [991,338,38]
    Caso 2: 
    [2,3,1,3,2]
    Caso 3:
    [-1,1,-6,4,5,-6,1,4,1]
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int size = nums.size(), num;
        vector<int> nuevoOrden(size);
        for(int i = 0; i < size; i++){
            num = nums[i];
            if(num == 0) nuevoOrden[i] = mapping[0];
            else nuevoOrden[i] = (cambiarNumero(mapping, nums[i])); 
        }
        mergeSort(0, size-1, nuevoOrden, nums);
        return nums;
    }
    int cambiarNumero(vector<int>mapping, int numero){
        int num = 0, multiplicador = 1;
        while(numero!=0){
            num += mapping[numero%10]*multiplicador;
            numero /= 10;
            multiplicador *= 10;
        }
        return num;
    }
    void mergeSort(int ini, int fin, vector<int>& nuevoOrden, vector<int>& nums){
        if(ini == fin) return;
        int medio = (ini+fin)/2;
        mergeSort(ini, medio, nuevoOrden, nums);
        mergeSort(medio+1, fin, nuevoOrden, nums);
        merge(ini, fin, medio, nuevoOrden, nums);
    }
    void merge(int ini, int fin, int medio, vector<int>& nuevoOrden, vector<int>& nums){
        pair <int, int> Inicio[medio - ini + 2], Final[fin-medio+1];
        for(int i = ini; i <= medio; i++) Inicio[i-ini] = {nuevoOrden[i], nums[i]};
        for(int i = medio+1; i <= fin; i++) Final[i-medio-1] = {nuevoOrden[i], nums[i]};
        Inicio[medio-ini+1] = {INT_MAX, INT_MAX};
        Final[fin-medio] = {INT_MAX, INT_MAX};
        int p = 0, q = 0;
        for(int i = ini; i <= fin; i++){
            if (Inicio[p].first > Final[q].first){
                nuevoOrden[i] = Final[q].first;
                nums[i] = Final[q].second;
                q++;
            }else if (Inicio[p].first < Final[q].first){
                nuevoOrden[i] = Inicio[p].first;
                nums[i] = Inicio[p].second;
                p++;
            }else{
                if(Inicio[p].first != INT_MAX || Final[q].first == INT_MAX){
                    nuevoOrden[i] = Inicio[p].first;
                    nums[i] = Inicio[p].second;
                    p++;
                }else{
                    nuevoOrden[i] = Final[q].first;
                    nums[i] = Final[q].second;
                    q++;
                }
            }
        }
    }
};

int main (void){
    Solution caso;
    vector<int>map1 = {8,9,4,0,2,1,3,5,7,6};
    vector<int>cas1 = {991,338,38};
    for (int dato:caso.sortJumbled(map1, cas1)){
        cout << dato << ' ';
    }
    cout << endl;
    vector<int>map2 = {0,1,2,3,4,5,6,7,8,9};
    vector<int>cas2 = {789,456,123};
    for (int dato:caso.sortJumbled(map2, cas2)){
        cout << dato << ' ';
    }
    cout << endl;
    vector<int>map3 = {9,8,7,6,5,4,3,2,1,0};
    vector<int>cas3 = {0,1,2,3,4,5,6,7,8,9};
    for (int dato:caso.sortJumbled(map3, cas3)){
        cout << dato << ' ';
    }
    cout << endl;
    return 0;
}