// Problema: https://imgur.com/a/ndevm5i
// Solución Arreglos
// Entradas:
    /*
    Caso 1:
    5
    Caso 2: 
    1
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> later = {1, 1}, aux;
        vector<vector<int>> result;
        // result.push_back(later);
        for(int i = 0; i < numRows; i++){
            if(i == 0) result.push_back({1});
            else if(i == 1) result.push_back(later);
            else{
                later = sum(later);
                result.push_back(later);
            }
        }
        return result;
    }
private:
    vector<int> sum(vector<int> prev) {
        int size = prev.size();
        vector<int> calculate;
        calculate.push_back(1);
        for(int i = 0, j = 1; j < size; i++, j++){
            calculate.push_back(prev[i] + prev[j]);
        }
        calculate.push_back(1);
        return calculate;
    }
};

int main (void){
    Solution caso;
    // caso.generate(5);
    vector<vector<int>> a1, a2;
    a1 = caso.generate(5);
    for(int i = 0; i < a1.size(); i++){
        for(int j = 0; j < a1[i].size(); j++) cout << a1[i][j] << ' ';
        cout << endl;
    }
    a2 = caso.generate(1);
    return 0;
}