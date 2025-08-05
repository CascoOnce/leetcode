// Problema: https://imgur.com/a/f4z2htk
// Solución por uso de Array
// Entradas:
    /*
    Caso 1:
    fruits = [4,2,5], baskets = [3,5,4]
    Caso 2: 
    fruits = [3,6,1], baskets = [6,4,7]
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for(int value: fruits){
            bool found = false;
            for(int i = 0; i < baskets.size(); i++){
                if(value <= baskets[i] && baskets[i] != -1) {
                    baskets[i] = -1;
                    found = true;
                    break;
                } 
            }
            if(!found) count++;
        }
        return count;
    }
};

int main (void){
    Solution caso;
    vector<int> fruits1 = {4,2,5}, baskets1 = {3,5,4};
    vector<int> fruits2 = {3,6,1}, baskets2 = {6,4,7};
    cout << caso.numOfUnplacedFruits(fruits1, baskets1) << endl;
    cout << caso.numOfUnplacedFruits(fruits2, baskets2) << endl;
    return 0;
}