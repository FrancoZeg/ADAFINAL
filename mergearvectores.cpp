#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Función para mezclar dos vectores ordenados
vector<int> mergeTwoVectors(const vector<int> &vec1, const vector<int> &vec2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            merged.push_back(vec1[i++]);
        } else {
            merged.push_back(vec2[j++]);
        }
    }

    // Agregar elementos restantes
    while (i < vec1.size()) merged.push_back(vec1[i++]);
    while (j < vec2.size()) merged.push_back(vec2[j++]);

    return merged;
}

// Función recursiva de "Divide y Vencerás" para combinar k vectores
vector<int> mergeKSortedVectors(vector<vector<int>> &vectors, int left, int right) {
    if (left == right) return vectors[left]; // Caso base: un único vector

    int mid = left + (right - left) / 2;
    vector<int> leftMerged = mergeKSortedVectors(vectors, left, mid); // Mezclar la mitad izquierda
    vector<int> rightMerged = mergeKSortedVectors(vectors, mid + 1, right); // Mezclar la mitad derecha

    return mergeTwoVectors(leftMerged, rightMerged); // Combinar ambas mitades
}

// Ejecución principal
int main() {
    vector<vector<int>> vectors = {
        {1, 5, 9},
        {2, 6, 8},
        {3, 7, 10},
        {4, 11, 12}
    };

    cout << "Vectores originales:" << endl;
    for (const auto &vec : vectors) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }

    vector<int> result = mergeKSortedVectors(vectors, 0, vectors.size() - 1);

    cout << "Vector combinado ordenado:" << endl;
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
