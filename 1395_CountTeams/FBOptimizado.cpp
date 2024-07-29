// Problema: https://imgur.com/a/qwMsAcQ
// Solución a Fuerza Bruta Optimizado
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
        for(int i = 0; i < size; i++){
            int leftSmaller = 0, rightLarger = 0;
            for(int j = i - 1; j >= 0; j--) if(rating[i] > rating[j]) leftSmaller++;
            for(int j = i + 1; j < size; j++) if(rating[i] < rating[j]) rightLarger++;
            teams += (leftSmaller*rightLarger);
            int leftLanger = (i - leftSmaller), rightSmaller = (size - 1 - i - rightLarger);
            teams += (leftLanger * rightSmaller);
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