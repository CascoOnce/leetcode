// Problema: https://imgur.com/a/7yug44d
// Solución Sliding Window
// Entradas:
    /*
    Caso 1:
    [1,3,2,2,5,2,3,7]
    Caso 2: 
    [1,2,3,4]
    Caso 3: 
    [1,1,1,1]
    Caso 4:
    [1,3,5,7,9,11,13,15,17]
    */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, best = 0;
        for(int right = 0; right < nums.size(); right++){
            // Mueve la izq hasta que tenga la distancia requerida
            while (nums[right] - nums[left] > 1) left++;
            if(nums[right] - nums[left] == 1) best = max(best, right - left + 1);
        }
        return best;
    }
};

int main (void){
    Solution caso1, caso2, caso3;
    vector <int> a = {1,3,2,2,5,2,3,7}, b = {1,2,3,4}, c = {1,1,1,1}, d = {1,2,2,3,4,5,1,1,1,1};
    cout << caso1.findLHS(a) << endl;
    cout << caso1.findLHS(b) << endl;
    cout << caso1.findLHS(c) << endl;
    cout << caso1.findLHS(d) << endl;
    return 0;
}