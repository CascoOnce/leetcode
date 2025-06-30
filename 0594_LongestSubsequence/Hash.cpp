// Problema: https://imgur.com/a/7yug44d
// Solución Hash
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
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map <int, int> hash;
        for(int value :nums){
            hash[value]++;
        }
        int lastPos, value;
        int bestPos = -1, bestValue = -1;
        for(auto it = hash.begin(); it != hash.end(); ++it){
            lastPos = it->first - 1;
            value = it->second + hash[lastPos];
            if(value != it->second && value >= bestValue){
                bestValue = value, bestPos = lastPos;
            }
        }
        if(bestValue < 0) return 0; 
        else return bestValue;
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