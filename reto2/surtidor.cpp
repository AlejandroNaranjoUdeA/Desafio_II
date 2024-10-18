#include "Surtidor.h"
#include <iostream>

Surtidor::Surtidor(int _id, std::string _modelo)
    : id(_id), modelo(_modelo), contadorTransacciones(0), capacidadTransacciones(100) {
    transacciones = new Transaccion*[capacidadTransacciones]; // Asignar memoria para transacciones
}

Surtidor::~Surtidor() {
    for (int i = 0; i < contadorTransacciones; i++) {
        delete transacciones[i]; // Liberar cada transacción
    }
    delete[] transacciones; // Liberar el arreglo dinámico
}

bool Surtidor::venderCombustible(Transaccion* nuevaTransaccion) {
    if (contadorTransacciones < capacidadTransacciones) {
        transacciones[contadorTransacciones++] = nuevaTransaccion;
        return true;
    } else {
        std::cout << "Maximo numero de transacciones alcanzado." << std::endl;
            return false;
    }
}

void Surtidor::mostrarTransacciones() const {
    for (int i = 0; i < contadorTransacciones; i++) {
        transacciones[i]->mostrarTransaccion();
    }
}

// Calcular total de ventas
double Surtidor::calcularVentasTotales() const {
    double total = 0.0;
    for (int i = 0; i < contadorTransacciones; i++) {
        total += transacciones[i]->getMonto(); // Usar el método getter para acceder al monto
    }
    return total;
}

// Calcular litros vendidos por categoría
double Surtidor::calcularLitrosVendidos(CategoriaCombustible categoria) const {
    double total = 0.0;
    for (int i = 0; i < contadorTransacciones; i++) {
        if (transacciones[i]->getCategoria() == categoria) { // Usar el método getter para acceder a la categoría
            total += transacciones[i]->getLitros(); // Usar el método getter para acceder a los litros
        }
    }
    return total;
}
