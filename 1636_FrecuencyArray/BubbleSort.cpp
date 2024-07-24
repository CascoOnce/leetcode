// Problema: https://imgur.com/a/w0ll23Q
// Solución Hash con Bubble Sort
// Entradas:
    /*
    Caso 1:
    [1,1,2,2,2,3]
    Caso 2: 
    [2,3,1,3,2]
    Caso 3:
    [-1,1,-6,4,5,-6,1,4,1]
    */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector <int> output;
        unordered_map <int, int> frecuencia{};
        for(int num:nums) frecuencia[num]++;
        int size =  frecuencia.size();
        vector<pair<int, int>> numeroCant (size);
        int i = 0;
        for(auto cant: frecuencia){
            numeroCant[i].first = cant.first; // Key
            numeroCant[i].second = cant.second; // Repeticiones
            i++;
        }
        bubbleSort(size, numeroCant);
        for (int i = 0; i < size; i++){
            for(int j = 0; j < numeroCant[i].second; j++){
                output.push_back(numeroCant[i].first);
            }
        }
        return output;
    }
    void bubbleSort(int size, vector <pair<int, int>> &numeroCant){
        for(int i = size; i > 0; i--){
            for(int j = 0; j < i - 1; j++){
                if(numeroCant[j].second > numeroCant[j+1].second || 
                (numeroCant[j].second == numeroCant[j+1].second && numeroCant[j].first < numeroCant[j+1].first)){
                    pair<int,int> aux;
                    aux = numeroCant[j+1];
                    numeroCant[j+1] = numeroCant[j];
                    numeroCant[j] = aux;
                }
            }
        }
    }
};

int main (void){
    Solution caso;
    vector<int>input1 = {1,1,2,2,2,3}, input2 = {2,3,1,3,2}, input3 = {-1,1,-6,4,5,-6,1,4,1}, vCaso;
// Caso 1:
    for(int num:input1) cout << num << ' ';
    cout << endl;
    vCaso = caso.frequencySort(input1);
    for(int num:vCaso) cout << num << ' ';
    cout << endl;
// Caso 2:
    for(int num:input2) cout << num << ' ';
    cout << endl;
    vCaso = caso.frequencySort(input2);
    for(int num:vCaso) cout << num << ' ';
    cout << endl;
// Caso 3:
    for(int num:input3) cout << num << ' ';
    cout << endl;
    vCaso = caso.frequencySort(input3);
    for(int num:vCaso) cout << num << ' ';
    cout << endl;
    return 0;
}