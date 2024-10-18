#include "Tanque.h"
#include <iostream>

Tanque::Tanque(double regular, double premium, double ecoExtra) {
    capacidadOriginal[Regular] = regular;
    capacidadOriginal[Premium] = premium;
    capacidadOriginal[EcoExtra] = ecoExtra;

    combustibleAlmacenado[Regular] = regular;
    combustibleAlmacenado[Premium] = premium;
    combustibleAlmacenado[EcoExtra] = ecoExtra;
}

double Tanque::obtenerCombustibleAlmacenado(CategoriaCombustible categoria) const {
    return combustibleAlmacenado[categoria];
}

void Tanque::extraerCombustible(CategoriaCombustible categoria, double cantidad) {
    if (combustibleAlmacenado[categoria] >= cantidad) {
        combustibleAlmacenado[categoria] -= cantidad;
    } else {
        std::cout << "No hay suficiente combustible para la categoria seleccionada." << std::endl;
    }
}

bool Tanque::verificarFuga() const {
    for (int i = 0; i < 3; i++) {
        if ((combustibleAlmacenado[i]) < (0.95 * capacidadOriginal[i])) {
            return true; // Hay fuga
        }
    }
    return false; // No hay fuga
}
