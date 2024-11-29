#include <iostream>
#include <vector>
using namespace std;

// Función para particionar el vector
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Seleccionamos el último elemento como pivote
    int i = low - 1; // Índice del elemento más pequeño

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) { // Si el elemento es menor que el pivote
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    // Colocar el pivote en su posición correcta
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Función recursiva de Quicksort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Particionamos el vector

        // Ordenar recursivamente las partes izquierda y derecha
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Ejecución principal
int main() {
    vector<int> arr = {9, 1, 3, 5, 0, 4, 2, 6, 8, 7};

    cout << "Vector original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1); // Llamada inicial a Quicksort

    cout << "Vector ordenado: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
