#include "EstacionDeServicio.h"
#include <iostream>

EstacionDeServicio::EstacionDeServicio(int _id, string _nombre, string _ubicacion, Tanque* _tanque)
    : id(_id), nombre(_nombre), ubicacion(_ubicacion), tanque(_tanque), numSurtidores(0) {}

void EstacionDeServicio::agregarSurtidor(Surtidor* nuevoSurtidor) {
    if (numSurtidores < 12) {
        surtidores[numSurtidores] = nuevoSurtidor;
        numSurtidores++;
    } else {
        std::cout << "Máximo número de surtidores alcanzado." << std::endl;
    }
}

void EstacionDeServicio::mostrarSurtidores() const {
    for (int i = 0; i < numSurtidores; i++) {
        std::cout << "Surtidor ID: " << surtidores[i]->obtenerID() << std::endl;
        surtidores[i]->mostrarTransacciones();
    }
}

bool EstacionDeServicio::verificarFugas() const {
    return tanque->verificarFuga();
}
