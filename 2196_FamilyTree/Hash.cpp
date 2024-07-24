// Problema: https://imgur.com/a/CWCmmW2
// Solución por uso de Hash y puntero ligado
// Entradas:
    /*
    Caso 1:
    [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]];
    Caso 2: 
    [[1,2,1],[2,3,0],[3,4,1]];
    */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // [parent] [child] [isLeft]
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map <int,pair<TreeNode*, int>> hashFamilia; // codigo [hijos,padres]
        int size = descriptions.size(), padre, hijo;
        TreeNode *aHijo, *aPadre;
        for(int i = 0; i < size; i++){
            padre = descriptions[i][0];
            hijo = descriptions[i][1];
            bool izq = (descriptions[i][2])? true : false;
            if (hashFamilia.find(hijo) == hashFamilia.end()) hashFamilia[hijo].first = new TreeNode(hijo); // Se crea al hijo
            aHijo = hashFamilia[hijo].first;
            if (hashFamilia.find(padre) == hashFamilia.end()){
                if (izq) aPadre = new TreeNode(padre, aHijo, nullptr);
                else aPadre = new TreeNode(padre, nullptr, aHijo);
                hashFamilia[padre].first = aPadre;
                hashFamilia[padre].second = 0;
                hashFamilia[hijo].second = padre;
            }else{
                aPadre = hashFamilia[padre].first;
                if (izq) aPadre->left = aHijo;
                else aPadre->right = aHijo;
                hashFamilia[hijo].second = padre;
            } 
        }
        int pos = hashFamilia[padre].second, anterior = padre;
        while(pos != 0){
            anterior = pos;
            pos = hashFamilia[anterior].second;
        }
        return hashFamilia[anterior].first;
    }
};

void imprimirPorAmplitud(TreeNode *nodo){
    stack <TreeNode*> pilaValores;
    stack <TreeNode*> temporal;
    pilaValores.push(nodo);
    while(!pilaValores.empty()){
        while(!pilaValores.empty()){
            TreeNode *familiar = pilaValores.top();
            pilaValores.pop();
            cout << familiar->val << ",";
            if (familiar->left) temporal.push(familiar->left); 
            if (familiar->right) temporal.push(familiar->right); 
        }
        while(!temporal.empty()){
            pilaValores.push(temporal.top());
            temporal.pop();
        }
    }
    cout << endl;
}

int main (void){
    Solution caso;
    TreeNode *nodo = nullptr;
// Caso 1:
    vector <vector <int>> vcaso1 = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    nodo = caso.createBinaryTree(vcaso1);
    imprimirPorAmplitud(nodo);
// Caso 2:
    vector <vector <int>> vcaso2 = {{1,2,1},{2,3,0},{3,4,1}};
    nodo = caso.createBinaryTree(vcaso2);
    imprimirPorAmplitud(nodo);
// Caso 3:
    vector <vector <int>> vcaso3 = {{39,70,1},{13,39,1},{85,74,1},{74,13,1},{38,82,1},{82,85,1}};
    nodo = caso.createBinaryTree(vcaso3);
    imprimirPorAmplitud(nodo);
    return 0;
}

