// Problema: https://imgur.com/a/ZiGo3lm
// Solución por Floyd usando grafo con matriz
// Entradas:
    /*
    Caso 1:
        source = "abcd";
        target = "acbe";
        original = ['a','b','c','c','e','d'];
        changed = ['b','c','b','e','b','e'];
        cost = [2,5,5,1,2,20]
    Caso 2: 
        source = "aaaa";
        target = "bbbb";
        original = ['a','c'];
        changed = ['c','b'];
        cost = [1,2]
    Caso 3: 
        source = "abcd";
        target = "abce";
        original = ['a'];
        changed = ['e'];
        cost = [10000]
    */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long costo = 0;
        vector<vector<long long>> grafoMatriz(26, vector<long long>(26, INT_MAX)); // Matriz
        int size = original.size();
        for(int i = 0; i < size; ++i){
            int orig = original[i] - 'a', dest = changed[i] - 'a';
            grafoMatriz[orig][dest] = min(grafoMatriz[orig][dest], (long long)cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    grafoMatriz[i][j] = min(grafoMatriz[i][j], grafoMatriz[i][k] + grafoMatriz[k][j]);
                }
            }
        }
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                int orig = source[i] - 'a', dest = target[i] - 'a';
                if (grafoMatriz[orig][dest] >= INT_MAX) return -1;
                else costo += grafoMatriz[orig][dest];
            }
        }
        return costo;
    }
};

int main (void){
    Solution caso;
    vector<char> original, changed;
    vector<int> cost;
    // Caso_1
    original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
    cost = {2,5,5,1,2,20};
    cout << caso.minimumCost("abcd", "acbe", original, changed, cost) << endl;
    // Caso_2
    original = {'a','c'}, changed = {'c','b'};
    cost = {1,2};
    cout << caso.minimumCost("aaaa", "bbbb", original, changed, cost) << endl;
    // Caso_3
    original = {'a'}, changed = {'e'};
    cost = {10000};
    cout << caso.minimumCost("abcd", "abce", original, changed, cost) << endl;
    return 0;
}