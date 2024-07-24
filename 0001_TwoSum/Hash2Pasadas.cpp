// Problema: https://imgur.com/a/mR6BE1k
// Solución con Hash a 2 pasadas
// Entradas:
    /*
    Caso 1:
    [2,7,11,15] / target = 9;
    Caso 2: 
    [3,2,4] / target = 6
    Caso 3:
    [3,3] / target = 6
    */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solucion{
    public:
    vector <int> twoSum (vector<int>& nums, int target){
        map <int, int> hash;
        int size = nums.size();
        for (int i = 0; i < size; i++){
            hash[nums[i]] = i;
        }
        for (int i = 0; i < size; i++){
            int complemento = target - nums[i];
            if (hash.find(complemento) != hash.end() && hash[complemento] != i){
                return {i, hash[complemento]};
            }
        }
        return {};
    }
};

int main (void){
    Solucion caso1, caso2, caso3;
    // Caso 1:
    vector <int> acaso1 = {2,7,11,15};
    vector <int> vcaso1 = caso1.twoSum(acaso1 , 9);
    for(auto ind:vcaso1) cout << ind << ' ';
    cout << endl;
    // Caso 2:
    vector <int> acaso2 = {3,2,4};
    vector <int> vcaso2 = caso2.twoSum(acaso2 , 6);
    for(auto ind:vcaso2) cout << ind << ' ';
    cout << endl;
    // Caso 3:
    vector <int> acaso3 = {3,3};
    vector <int> vcaso3 = caso3.twoSum(acaso3 , 6);
    for(auto ind:vcaso3) cout << ind << ' ';
    cout << endl;
    return 0;
}