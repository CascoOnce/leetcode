// Problema: https://imgur.com/a/ZiGo3lm
// Solución a Dijkstra por Cola por Prioridad
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
        const int alphabet = 26;
        long long costo = 0;
        vector<vector<pair<int, int>>> listaAdyacente(alphabet);
        int size = original.size();
        for(int i = 0; i < size; i++){
            char orig = original[i], dest = changed[i];
            listaAdyacente[orig - 'a'].push_back({dest - 'a',cost[i]});
        }
        vector<vector<long long>> costosMinimos(alphabet, vector<long long>(alphabet));
        for(int i = 0; i < alphabet; i++) costosMinimos[i] = dijkstra(listaAdyacente, i);

        size = source.length();
        for(int i = 0; i < size; i++){
            if(source[i] != target[i]){
                long long costoConversion = costosMinimos[source[i]-'a'][target[i]-'a'];
                if(costoConversion != -1) costo += costoConversion;
                else return -1;
            }
        }
        return costo;
    }

    vector<long long> dijkstra(vector<vector<pair<int, int>>> &listaAdyacente, int source){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> colaPrioridad;
        colaPrioridad.push({0, source});
        vector<long long> costosMinimos(26, -1);
        while(!colaPrioridad.empty()){
            long long costo = colaPrioridad.top().first;
            long long letra = colaPrioridad.top().second;
            colaPrioridad.pop();
            if(costosMinimos[letra] != -1 && costosMinimos[letra] < costo) continue;
            for(auto &[destino, costoConversion]: listaAdyacente[letra]){
                long long nuevoCosto = costo + costoConversion;
                if(costosMinimos[destino] == -1 || nuevoCosto < costosMinimos[destino]){
                    costosMinimos[destino] = nuevoCosto;
                    colaPrioridad.push({nuevoCosto, destino});
                }
            }
        }
        return costosMinimos;
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