#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura para representar un cliente
struct Cliente {
    int id;       // Identificador del cliente
    int tiempo;   // Tiempo de atención requerido
};

// Comparador para ordenar los clientes por tiempo de atención
bool comparar(const Cliente &a, const Cliente &b) {
    return a.tiempo < b.tiempo;
}

// Función para maximizar las propinas
void maximizarPropinas(vector<Cliente> &clientes) {
    // Ordenar los clientes por tiempo de atención
    sort(clientes.begin(), clientes.end(), comparar);

    int tiempoEspera = 0;
    double propinasTotales = 0.0;

    cout << "Orden de atención de los clientes:" << endl;
    for (const auto &cliente : clientes) {
        tiempoEspera += cliente.tiempo; // Tiempo acumulado de espera
        double propina = 1.0 / tiempoEspera; // Propina del cliente actual
        propinasTotales += propina;

        cout << "Cliente " << cliente.id
             << " (Tiempo: " << cliente.tiempo
             << ", Tiempo de espera acumulado: " << tiempoEspera
             << ", Propina: " << propina << ")" << endl;
    }

    cout << "Propinas totales: " << propinasTotales << endl;
}

// Ejecución principal
int main() {
    vector<Cliente> clientes = {
        {1, 3}, {2, 2}, {3, 1}, {4, 4}
    };

    maximizarPropinas(clientes);

    return 0;
}
