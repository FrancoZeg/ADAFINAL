#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Función para particionar el vector
int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right]; // Elegimos el último elemento como pivote
    int i = left; // Índice para elementos menores al pivote

    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[right]); // Colocamos el pivote en su posición final
    return i;
}

// Función recursiva para encontrar el k-ésimo menor elemento
int quickSelect(vector<int> &arr, int left, int right, int k) {
    if (left == right) return arr[left]; // Caso base: un solo elemento

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k]; // El pivote es el k-ésimo menor
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k); // Buscar en la izquierda
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k); // Buscar en la derecha
    }
}

// Ejecución principal
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k;
    cout << "Ingrese el valor de k: ";
    cin >> k;

    if (k < 1 || k > arr.size()) {
        cout << "Valor de k fuera de rango." << endl;
        return 1;
    }

    int result = quickSelect(arr, 0, arr.size() - 1, k - 1);
    cout << "El " << k << "-ésimo menor elemento es: " << result << endl;

    return 0;
}
