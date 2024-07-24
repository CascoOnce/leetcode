// Problema: https://imgur.com/a/bwXN1zm
// Solución por Bubble Sort
// Entradas:
    /*
    Caso 1:
    [8,9,4,0,2,1,3,5,7,6] / [991,338,38]
    Caso 2: 
    [2,3,1,3,2] / [789,456,123]
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
        bubbleSort(nuevoOrden, nums);
        return nums;
    }
    int cambiarNumero(vector<int>mapping, int numero){
        if(numero == 0) return 0;
        return mapping[numero%10] + cambiarNumero(mapping, numero/10)*10;
    }
    void bubbleSort(vector<int>& nuevoOrden, vector<int>& nums){
        for(int j = nuevoOrden.size() - 1; j > 0; j--){
            for(int i = 0; i < j; i++){
                if(nuevoOrden[i] > nuevoOrden[i+1]){
                    int aux = nuevoOrden[i+1];
                    nuevoOrden[i+1] = nuevoOrden[i];
                    nuevoOrden[i] = aux;
                    aux = nums[i+1];
                    nums[i+1] = nums[i];
                    nums[i] = aux;
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