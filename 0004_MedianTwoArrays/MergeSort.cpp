// Problema: https://imgur.com/a/9tnPD3x
// Solución a Merge Sort
// Entradas:
    /*
    Caso 1:
    [1,3] / [2];
    Caso 2: 
    [1,2] / [3,4];
    */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        double mediana;
        vector <int> ordenado = mergeSort(nums1, nums2, size);
        if (size % 2 == 1) mediana = (double)ordenado[size/2];
        else mediana = ((double)ordenado[size/2] + ordenado[(size-1)/2])/2;
        return mediana;
    }
    vector <int> mergeSort(vector<int>& nums1, vector<int>& nums2, int size){
        int p = 0, q = 0, size1 = nums1.size(), size2 = nums2.size();
        vector <int> ordenado;
        for (int i = 0; i < size; i++){
            if (p < size1 && q < size2){
                if (nums1[p] < nums2[q]) ordenado.push_back(nums1[p++]);
                else ordenado.push_back(nums2[q++]);
            }else{
                if (p >= size1) ordenado.push_back(nums2[q++]);
                else ordenado.push_back(nums1[p++]);
            }
        }
        return ordenado;
    }
};

int main (void){
    cout << setprecision(2) << fixed;
    Solution caso1, caso2;
// Caso 1:
    vector <int> num11 = {1,3}, num12 = {2};
    cout << caso1.findMedianSortedArrays(num11, num12) << endl;
// Caso 2:
    vector <int> num21 = {1,2}, num22 = {3,4};
    cout << caso2.findMedianSortedArrays(num21, num22) << endl;
    return 0;
}