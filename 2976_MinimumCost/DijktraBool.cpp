// Problema: https://imgur.com/a/ZiGo3lm
// Solución a Dijkstra por arreglo Booleano
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
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long costo = 0;
        vector<vector<int>> grafoMatriz(26, vector<int>(26, INT_MAX));
        int size = original.size();
        for(int i = 0; i < size; i++){
            int orig = original[i] - 'a', dest = changed[i] - 'a';
            grafoMatriz[orig][dest] = min(grafoMatriz[orig][dest], cost[i]);
        }
        size = source.length();
        int *distancias;
        for(int i = 0; i < size; i++){
            if(source[i] != target[i]){
                distancias = dijkstra(grafoMatriz, source[i] - 97, 26);
                if(distancias[target[i]-97] != INT_MAX) costo += distancias[target[i]-97];
                else return -1;
            }
        }
        return costo;
    }

    int *dijkstra(vector<vector<int>> grafoMatriz, int src, int V){
        int *dist = new int[V]; 
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
                if (!visitado[i] && grafoMatriz[u][i] && grafoMatriz[u][i] != INT_MAX
                    && dist[u] != INT_MAX
                    && dist[u] + grafoMatriz[u][i] < dist[i])
                    dist[i] = dist[u] + grafoMatriz[u][i];
        }
        return dist;
    }
    
    int mindistancia(int dist[], bool visitado[], int V){
        int indmin = -1, min = INT_MAX;
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