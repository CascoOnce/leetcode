// Problema: https://imgur.com/a/a0wNS6D
// Solución a Floyd
// Entradas:
    /*
    Caso 1:
    4 / [[0,1,3],[1,2,1],[1,3,4],[2,3,1]] / 4;
    Caso 2: 
    5 / [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]] / 2
    */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<int>> grafoMatriz(n, vector<int>(n, 1e9 + 7));
        int a, b;
        for(int i = 0; i < n; i++) grafoMatriz[i][i] = 0;
        for(vector<int> aux: edges){
            a = aux[0];
            b = aux[1];
            grafoMatriz[a][b]=aux[2];
            grafoMatriz[b][a]=aux[2];
        }
        floyd(n, grafoMatriz);
        return menorDistancia(n, grafoMatriz, distanceThreshold);
    }
    void floyd(int n, vector<vector<int>> &grafoMatriz){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    grafoMatriz[j][k] = 
                        min(grafoMatriz[j][k], 
                            grafoMatriz[j][i] + grafoMatriz[i][k]);
                }
            }
        }
    }
    int menorDistancia(int n, vector<vector<int>> grafoMatriz, int maximo){
        int min = INT_MAX, home;
        for(int i = 0; i < n; i++){
            int ciudades = 0;
            for(int j = 0; j < n; j++){
                if(i != j && grafoMatriz[i][j] <= maximo) ciudades++;
            }
            if(ciudades <= min){
                min = ciudades;
                home = i;
            }
        }
        return home;
    }
};

int main (void){
    Solution caso;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << caso.findTheCity(4, edges1, 4) << endl;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout << caso.findTheCity(5, edges2, 2) << endl;
    return 0;
}