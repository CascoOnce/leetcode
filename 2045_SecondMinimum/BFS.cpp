// Problema: https://imgur.com/a/V1cE7NH
// Solución por BFS
// Entradas:
    /*
    Caso 1:
    5 / {{1,2},{1,3},{1,4},{3,4},{4,5}} / 3 / 5
    Caso 2: 
    2 / {{1,2}} / 3 / 2
    */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> listaAdyacencia(n+1);
        for(vector<int>pareja: edges){
            listaAdyacencia [pareja[0]].push_back(pareja[1]);
            listaAdyacencia [pareja[1]].push_back(pareja[0]);
        }
        return BFS(listaAdyacencia, n, change, time);
    }
private:
    int BFS(vector<vector<int>> listaAdyacencia ,int n, int change, int time){
        queue<pair<int, int>>cola;
        vector<int> dist1(n+1, -1), dist2(n+1, -1);
        cola.push({1,1});
        dist1[1] = 0;
        while(!cola.empty()){
            pair<int, int>actual = cola.front(); // {N°Nodo, Frequencia}
            cola.pop();
            int tiempo = actual.second==1? dist1[actual.first]: dist2[actual.first];
            if((tiempo/change)%2) tiempo = change*(tiempo/change + 1) + time; // Impar
            else tiempo += time;
            for(int vecino: listaAdyacencia[actual.first]){
                if(dist1[vecino] == -1){
                    dist1[vecino]=tiempo;
                    cola.push({vecino, 1});
                }else if(dist2[vecino] == -1 && dist1[vecino] != tiempo){
                    if(vecino == n) return tiempo;
                    dist2[vecino] = tiempo;
                    cola.push({vecino, 2});
                }
            }
        }
        return 0;
    }
};

int main (void){
    Solution caso;
    vector<vector<int>> edges;
    // Caso 1:
    edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    cout << caso.secondMinimum(5, edges, 3, 5) << endl;
    // Caso 2:
    edges = {{1,2}};
    cout << caso.secondMinimum(2, edges, 3, 2) << endl;
    return 0;
}