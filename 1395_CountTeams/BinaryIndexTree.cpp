// Problema: https://imgur.com/a/qwMsAcQ
// Solución a Binary Index Tree: (https://www.youtube.com/watch?v=fPAEZloj2L0)
// Entradas:
    /*
    Caso 1:
    {2,5,3,4,1};
    Caso 2: 
    {2,1,3};
    Caso 3: 
    {1,2,3,4};
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maximo = 0, teams = 0;
        for(int value:rating) maximo = max(value, maximo);
        vector<int> leftBIT(maximo + 1, 0);
        vector<int> rightBIT(maximo + 1, 0);
        for(int value:rating) updateBIT(rightBIT, value, 1);
        for(int actual: rating){
            updateBIT(rightBIT, actual, -1);
            int smallerRatingsLeft = getPrefixSum(leftBIT, actual - 1);
            int smallerRatingsRight = getPrefixSum(rightBIT, actual - 1);
            int largerRatingsLeft = getPrefixSum(leftBIT, maximo) - getPrefixSum(leftBIT, actual);
            int largerRatingsRight = getPrefixSum(rightBIT, maximo) - getPrefixSum(rightBIT, actual);
            teams += (smallerRatingsLeft*largerRatingsRight);
            teams += (smallerRatingsRight*largerRatingsLeft);
            updateBIT(leftBIT, actual, 1);
        }
        return teams;
    }
private:
    void updateBIT(vector<int> &BIT, int index, int value){
        while(index < BIT.size()){
            BIT[index] += value;
            index += index &(-index);
        }
    }
    int getPrefixSum(vector<int>& BIT, int index){
        int sum = 0;
        while(index > 0){
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }
};

int main (void){
    Solution caso;
    vector<int>rating;
    // Caso 1:
    rating = {2,5,3,4,1};
    cout << caso.numTeams(rating) << endl;
    // Caso 2: 
    rating = {2,1,3};
    cout << caso.numTeams(rating) << endl;
    // Caso 3: 
    rating = {1,2,3,4};
    cout << caso.numTeams(rating) << endl;
    return 0;
}