// Problema: https://imgur.com/a/6tcS1mH
// Solución con Merge Sort
// Entradas:
    /*
    Caso 1:
    [5,2,3,1]
    Caso 2: 
    [5,1,1,2,0,0]
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
    void mergeSort(int ini, int fin, vector<int>& nums){
        if(ini == fin) return;
        int medio = (ini+fin)/2;
        mergeSort(ini, medio, nums);
        mergeSort(medio+1, fin, nums);
        merge(ini, fin, medio, nums);
    }
    void merge(int ini, int fin, int medio, vector<int>& nums){
        int jerarquia1[medio - ini + 2], jerarquia2[fin - medio + 1];
        for(int i = ini; i <= medio; i++) jerarquia1[i-ini] = nums[i];
        for(int i = medio+1; i <= fin; i++) jerarquia2[i-medio-1] = nums[i];
        jerarquia1[medio - ini + 1] = INT_MAX;
        jerarquia2[fin - medio] = INT_MAX;
        int p = 0, q = 0;
        for(int i = ini; i <= fin; i++){
            if (jerarquia1[p] >= jerarquia2[q]){
                nums[i] = jerarquia2[q];
                q++;
            }else if (jerarquia1[p] < jerarquia2[q]){
                nums[i] = jerarquia1[p];
                p++;
            }
        }
    }
};

int main (void){
    Solution caso;
    vector<int>resultados = {5,2,3,1};
    caso.sortArray(resultados);
    for(int aux:resultados) cout << aux << ' ';
    cout << endl;
    return 0;
}