// https://imgur.com/a/p1IibKR
// Solución por Suma Antecesora
// Entradas:
    /*
    Caso 1:
    {1,3,4,8}, {{0,1}, {1,2}, {0,3}, {3,3}}
    Caso 2: 
    {4,8,2,10}, {{2,3}, {1,3}, {0,0}, {0,3}}
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> solution, summatory;
        summatory.push_back(0);
        for(int aux: arr) summatory.push_back(summatory.back() ^ aux);
        for(vector<int> pairV: queries){
            int vStart = summatory[pairV[0]], vEnd = summatory[pairV[1] + 1];
            int xo = vStart ^ vEnd;
            solution.push_back(xo);
        }
        return solution;
    }
};

int main (void){
    Solution caso;
    vector<int> arr, solution;
    vector<vector<int>> queries; 
    // Caso 1:
    arr = {1,3,4,8}, queries = {{0,1}, {1,2}, {0,3}, {3,3}};
    solution = caso.xorQueries(arr, queries);
    for(int aux: solution) cout << aux << ' ';
    cout << endl;
    // Caso 2:
    arr = {4,8,2,10}, queries = {{2,3}, {1,3}, {0,0}, {0,3}};
    solution = caso.xorQueries(arr, queries);
    for(int aux: solution) cout << aux << ' ';
    cout << endl;
    return 0;
}