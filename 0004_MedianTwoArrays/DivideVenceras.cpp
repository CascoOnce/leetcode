// Problema: https://imgur.com/a/9tnPD3x
// Solución por Divide y Venceras
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
        int finA = nums1.size(), finB = nums2.size();
        int pos = (finA + finB);
        if (pos % 2 == 1){
            return (double)busquedaMediana(nums1, nums2, (pos/2), 0, finA - 1, 0, finB - 1);
        }else{
            double x1, x2; 
            x1 = (double)busquedaMediana(nums1, nums2, pos/2 - 1, 0, finA - 1, 0, finB - 1);
            x2 = (double)busquedaMediana(nums1, nums2, pos/2, 0, finA - 1, 0, finB - 1);
            return (x1 + x2)/2;
        }
    }
    int busquedaMediana(vector <int> nums1, vector <int> nums2, int k, int iniA, int finA, int iniB, int finB){
        if (finA < iniA) return nums2[k - iniA];
        if (finB < iniB) return nums1[k - iniB];
        int medioA = (iniA + finA)/2, medioB = (iniB + finB)/2;
        if (k > medioA+medioB){
            if (nums1[medioA] > nums2[medioB]){
                return busquedaMediana(nums1, nums2, k, iniA, finA, medioB + 1, finB);
            }else{
                return busquedaMediana(nums1, nums2, k, medioA + 1, finA, iniB, finB);
            }
        }else{
            if (nums1[medioA] > nums2[medioB]){
                return busquedaMediana(nums1, nums2, k, iniA, medioA - 1, iniB, finB);
            }else{
                return busquedaMediana(nums1, nums2, k, iniA, finA, iniB, medioB - 1);
            }
        }
        return -1;
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