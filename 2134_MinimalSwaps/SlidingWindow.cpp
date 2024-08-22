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
        int op1 = minSwapsHelper(nums, 0), op2 = minSwapsHelper(nums, 1);
        return min(op1, op2);
    }
private:
    int minSwapsHelper(vector<int>& data, int val) {
        int length = data.size(),  totalValCount = 0;
        for (int i = length - 1; i >= 0; i--)  if (data[i] == val) totalValCount++;
        if (totalValCount == 0 || totalValCount == length) return 0;
        int start = 0, end = 0, maxValInWindow = 0, currentValInWindow = 0;
        while (end < totalValCount) if (data[end++] == val) currentValInWindow++;
        maxValInWindow = max(maxValInWindow, currentValInWindow);
        while (end < length) {
            if (data[start++] == val) currentValInWindow--;
            if (data[end++] == val) currentValInWindow++;
            maxValInWindow = max(maxValInWindow, currentValInWindow);
        }
        return totalValCount - maxValInWindow;
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