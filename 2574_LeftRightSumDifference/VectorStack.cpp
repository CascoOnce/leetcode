// Problema: https://imgur.com/a/ajI9jCn
// Solución por Vector y Stack
// Entradas:
    /*
    Caso 1:
    {10,4,8,3}
    Caso 2: 
    {1}
    Caso 3: 
    {1,1,0,0,1}
    */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftSum, difference;
        stack<int> rightSum;
        leftSum.push_back(0), rightSum.push(0);
        for(int i = 0; leftSum.size() < size; i++) leftSum.push_back(leftSum.back() + nums[i]);
        for(int i = size-1; rightSum.size() < size; i--) rightSum.push(rightSum.top() + nums[i]);
        for(int i = 0; rightSum.size() > 0; i++) {
            difference.push_back(rightSum.top() - leftSum[i]);
            if(difference[i] < 0) difference[i] = -difference[i];
            rightSum.pop();
        }
        return difference;
    }
};

int main (void){
    Solution caso;
    vector<int> nums, difference;
    // Caso_1
    nums = {10,4,8,3};
    difference = caso.leftRightDifference(nums);
    for(int dato:difference) cout << dato << ' ';
    cout << endl;
    // Caso_2
    nums = {1};
    difference = caso.leftRightDifference(nums);
    for(int dato:difference) cout << dato << ' ';
    cout << endl;
    return 0;
}