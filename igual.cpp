#include <iostream>
#include <vector>
using namespace std;

// Función recursiva para buscar el índice fijo
int fixedPoint(vector<int> &arr, int left, int right) {
    if (left > right) return -1; // Caso base: no encontrado

    int mid = left + (right - left) / 2;

    if (arr[mid] == mid) return mid; // Encontramos el índice fijo
    else if (arr[mid] > mid) return fixedPoint(arr, left, mid - 1); // Buscar en la izquierda
    else return fixedPoint(arr, mid + 1, right); // Buscar en la derecha
}

// Ejecución principal
int main() {
    vector<int> arr = {-10, -5, 0, 3, 7, 9}; // Ejemplo de entrada
    int n = arr.size();

    int result = fixedPoint(arr, 0, n - 1);

    if (result != -1) {
        cout << "Índice fijo encontrado: X[" << result << "] = " << result << endl;
    } else {
        cout << "No existe índice fijo." << endl;
    }

    return 0;
}
