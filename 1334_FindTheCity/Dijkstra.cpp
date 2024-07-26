// Problema: https://imgur.com/a/a0wNS6D
// Solución a Dijkstra
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
        vector<vector<int>> grafoMatriz(n, vector<int>(n));
        int a, b;
        for(vector<int> aux: edges){
            a = aux[0];
            b = aux[1];
            grafoMatriz[a][b]=aux[2];
            grafoMatriz[b][a]=aux[2];
        }
        vector<int>distancias(n);
        for(int i = 0; i < n; i++) distancias[i] = dijkstra(grafoMatriz, i, n, distanceThreshold);
        int min = INT_MAX, home;
        for(int i = 0; i < n; i++){
            if(distancias[i] <= min){
                min = distancias[i];
                home = i;
            }
        }
        return home;
    }
    int dijkstra(vector<vector<int>> grafoMatriz, int src, int V, int max){
        int dist[V]; 
        bool visitado[V];
        for (int i = 0; i < V; i++){
            dist[i] = INT_MAX;
            visitado[i] = false;
        }    
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++) {
            int u = mindistancia(dist, visitado, V);
            visitado[u] = true;
            for (int i = 0; i < V; i++)
                if (!visitado[i] && grafoMatriz[u][i]
                    && dist[u] != INT_MAX
                    && dist[u] + grafoMatriz[u][i] < dist[i])
                    dist[i] = dist[u] + grafoMatriz[u][i];
        }
        int ciudades = -1;
        for(int i = 0; i < V; i++){
            if(dist[i] <= max) ciudades++;
        }
        return ciudades;
    }
    int mindistancia(int dist[], bool visitado[], int V){
        int indmin,min = INT_MAX;
        for (int i = 0; i < V; i++)
            if (visitado[i] == false && dist[i] <= min){
                min = dist[i];
                indmin = i;
            }    
        return indmin;
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