// Problema: https://imgur.com/a/p4cHJOp
// Solución por Sliding Window
// Entradas:
    /*
    Caso 1:
    {0,1,0,1,1,0,0}
    Caso 2: 
    {0,1,1,1,0,0,1,1,0}
    Caso 3: 
    {1,1,0,0,1}
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int os = cambiosMinimos(nums, 0), is = cambiosMinimos(nums, 1);
        return min(os, is);
    }
private:
    int cambiosMinimos(vector<int>nums, int value){
        int size = nums.size();
        vector<int> rightSum(size+1, 0);
        for(int i = size-1; i >= 0; i--){
            rightSum[i] = rightSum[i+1];
            if(nums[i] == value^1) rightSum[i]++;
        }
        int cambiosNecesarios = rightSum[0], cambios = 0;
        int cambiosMinimos = cambiosNecesarios - rightSum[size - cambiosNecesarios];
        for(int i = 0; i < cambiosNecesarios; i++){
            if(nums[i] == value^1) cambios++;
            int temp = (cambiosNecesarios - i - 1);
            int cambiosrequeridos = ((i+1) - cambios) + (temp - rightSum[size-temp]);
            cambiosMinimos = min(cambiosMinimos, cambiosrequeridos);
        }
        return cambiosMinimos;
    }
};

int main (void){
    Solution caso;
    vector<int> nums;
    // Caso_1
    nums = {0,1,0,1,1,0,0};
    cout << caso.minSwaps(nums) << endl;
    // Caso_2
    nums = {0,1,1,1,0,0,1,1,0};
    cout << caso.minSwaps(nums) << endl;
    // Caso_3
    nums = {1,1,0,0,1};
    cout << caso.minSwaps(nums) << endl;
    return 0;
}