// Problema: https://imgur.com/a/NoMWaQn
// Solución con iterativa
// Entradas: 
    /*
    Caso 1:
    [2,4,3] / [5,6,4]
    Caso 2:
    [0] / [0]
    Caso 3:
    [9,9,9,9,9,9,9] / [9,9,9,9]
    */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int suma = 0;
        ListNode *listaSuma = new ListNode(0), *listaCabeza = listaSuma;
        while (l1 || l2){
            if (l1){
                suma += l1->val;
                l1 = l1->next;
            }
            if (l2){
                suma += l2->val;
                l2 = l2->next;
            }
            listaSuma->next = new ListNode(suma%10);
            listaSuma = listaSuma->next;
            suma = (suma/10)? 1: 0;
        }
        if (suma){
            listaSuma->next = new ListNode(suma);
        }
        return listaCabeza->next;
    }
};


int main (void){
    Solution caso1, caso2, caso3;
//CASO 1:
    ListNode *l1_1 = nullptr, *l1_2 = nullptr, *lfinal1;
    vector<int>vcaso1_1 = {2,4,3}, vcaso1_2 = {5,6,4};
    for (int dato:vcaso1_1) l1_1 = new ListNode(dato, l1_1);
    for (int dato:vcaso1_2) l1_2 = new ListNode(dato, l1_2);
    lfinal1 = caso1.addTwoNumbers(l1_1,l1_2);
    while (lfinal1){
        cout << lfinal1->val << ' ';
        lfinal1 = lfinal1->next;
    }
    cout << endl;
// CASO 2:
    ListNode *l2_1 = nullptr, *l2_2 = nullptr, *lfinal2;
    vector<int>vcaso2_1 = {0}, vcaso2_2 = {0};
    for (int dato:vcaso2_1) l2_1 = new ListNode(dato, l2_1);
    for (int dato:vcaso2_2) l2_2 = new ListNode(dato, l2_2);
    lfinal2 = caso2.addTwoNumbers(l2_1,l2_2);
    while (lfinal2){
        cout << lfinal2->val << ' ';
        lfinal2 = lfinal2->next;
    }
    cout << endl;
// CASO 3:
    ListNode *l3_1 = nullptr, *l3_2 = nullptr, *lfinal3;
    vector<int>vcaso3_1 = {9,9,9,9,9,9,9}, vcaso3_2 = {9,9,9,9};
    for (int dato:vcaso3_1) l3_1 = new ListNode(dato, l3_1);
    for (int dato:vcaso3_2) l3_2 = new ListNode(dato, l3_2);
    lfinal3 = caso3.addTwoNumbers(l3_1,l3_2);
    while (lfinal3){
        cout << lfinal3->val << ' ';
        lfinal3 = lfinal3->next;
    }
    cout << endl;
    return 0;
}