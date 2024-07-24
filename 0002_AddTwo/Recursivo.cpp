// Problema: https://imgur.com/a/NoMWaQn
// Solución por recursividad
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
        return recursivo(l1, l2, 0);
    }
    ListNode *recursivo(ListNode *l1, ListNode *l2, int carry){
        ListNode *nodo;
        if (!l1 && !l2){
            if (carry <= 0)  return nullptr;
            else return (nodo = new ListNode(carry));
        }
        int v1 = (l1 != nullptr)? l1->val: 0;
        int v2 = (l2 != nullptr)? l2->val: 0;
        int newCarry = (v1 + v2 + carry)/10;
        if (l1 && l2){
            nodo = recursivo(l1->next, l2->next, newCarry);
        }else if (l1){
            nodo = recursivo(l1->next, l2, newCarry);
        }else{
            nodo = recursivo(l1, l2->next, newCarry);
        }
        nodo = new ListNode((v1 + v2 + carry)%10, nodo);
        return nodo;
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