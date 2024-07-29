// Problema: https://imgur.com/a/qwMsAcQ
// Solución a Fuerza Bruta
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
        int size = rating.size(), teams = 0;
        for(int i = 0; i < size-2; i++){
            for(int j = i + 1; j < size - 1; j++){
                for(int k = j + 1; k < size; k++){
                    if((rating[i] < rating[j] && rating[j] < rating[k]) ||
                        (rating[i] > rating[j] && rating[j] > rating[k])) teams++;
                }
            }
        }
        return teams;
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