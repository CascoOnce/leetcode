// Problema: https://imgur.com/a/CuBIQ0Q
// Solución a Programacion Dinamica
// Entradas:
    /*
    Caso 1:
    {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}} / 4;
    Caso 2: 
    {{1,3},{2,4},{3,2}} / 6
    Caso 3: 
    {{7,3},{8,7},{2,7},{2,5}} / 10
    */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidht){
        vector<vector<int>> memoria(books.size(), vector<int>(shelfWidht + 1, 0));
        return estantesDinamica(books, memoria, 0, shelfWidht, shelfWidht, 0);
    }
private:
    int estantesDinamica(vector<vector<int>> &books, 
            vector<vector<int>> &memoria, int posicion, int anchoDisponible, int anchoMaximo, int altoMaximo){
        vector<int>libro = books[posicion];
        int alturaActualizada = max(altoMaximo, libro[1]);
        if(posicion == books.size() - 1){
            if(anchoDisponible >= books[posicion][0]) return alturaActualizada;
            else return altoMaximo + libro[1];
        }
        if(memoria[posicion][anchoDisponible] != 0) return memoria[posicion][anchoDisponible];
        int opcion1 =  altoMaximo + estantesDinamica(books, memoria, posicion+1, anchoMaximo - libro[0], anchoMaximo, libro[1]);
        if(anchoDisponible >= libro[0]){
            int opcion2 = estantesDinamica(books, memoria, posicion + 1, anchoDisponible - books[posicion][0], anchoMaximo, alturaActualizada);
            memoria[posicion][anchoDisponible] = min(opcion1, opcion2);
            return memoria[posicion][anchoDisponible];
        }
        memoria[posicion][anchoDisponible] = opcion1;
        return memoria[posicion][anchoDisponible];
    }
};

int main (void){
    Solution caso;
    vector<vector<int>> books;
    // Caso_1
    books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << caso.minHeightShelves(books, 4) << endl;
    // Caso_2
    books = {{1,3},{2,4},{3,2}};
    cout << caso.minHeightShelves(books, 6) << endl;
    // Caso_3
    books = {{7,3},{8,7},{2,7},{2,5}};
    cout << caso.minHeightShelves(books, 10) << endl;
    return 0;
}