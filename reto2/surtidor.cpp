#include "Surtidor.h"
#include <iostream>

Surtidor::Surtidor(int _id, string _modelo) : id(_id), modelo(_modelo), contadorTransacciones(0) {}

bool Surtidor::venderCombustible(Transaccion* nuevaTransaccion) {
    if (contadorTransacciones < 100) {
        transacciones[contadorTransacciones] = nuevaTransaccion;
        contadorTransacciones++;
        return true;
    } else {
        std::cout << "Máximo número de transacciones alcanzado." << std::endl;
            return false;
    }
}

void Surtidor::mostrarTransacciones() const {
    for (int i = 0; i < contadorTransacciones; i++) {
        transacciones[i]->mostrarTransaccion();
    }
}
