// Problema: https://imgur.com/a/9tnPD3x
// Solución por Particiones
// Entradas:
    /*
    Caso 1:
    [1,3] / [2];
    Caso 2: 
    [1,2] / [3,4];
    */

#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeA = nums1.size(), sizeB = nums2.size(), maxLA, minRA, maxLB, minRB;
        // if (sizeA > sizeB) return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = sizeA;
        bool seHaceOperacion = ((sizeA+sizeB)%2 != 1);
        while(right >= left){
            int parA = (right + left)/2;
            int parB = (sizeA + sizeB + 1)/2 - parA;
            maxLA = (parA == 0)? INT_MIN: nums1[parA - 1];
            minRA = (parA == sizeA)? INT_MAX: nums1[parA];
            maxLB = (parB == 0)? INT_MIN: nums2[parB - 1];
            minRB = (parB == sizeB)? INT_MAX: nums2[parB];

            if (maxLA <= minRB && maxLB <= minRA){
                if (seHaceOperacion) return (max(maxLA,maxLB) + min(minRA,minRB))/2.0; 
                else return max(maxLA,maxLB);
            }else if(maxLA > minRB) right = parA - 1;
            else left = parA + 1;
        }
        return 0;
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
// Caso 0:
    vector <int> num31 = {}, num32 = {1};
    cout << caso2.findMedianSortedArrays(num31, num32) << endl;
// Caso 0:
    vector <int> num41 = {2}, num42 = {};
    cout << caso2.findMedianSortedArrays(num41, num42) << endl;
    return 0;
}