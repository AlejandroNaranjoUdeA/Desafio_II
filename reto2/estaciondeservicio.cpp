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

// Implementacion del getter para obtener el ID
int EstacionDeServicio::getId() const {
    return id;
}

void EstacionDeServicio::simularVenta() {
    if (numSurtidores == 0) {
        std::cout << "No hay surtidores disponibles para simular venta." << std::endl;
        return;
    }

    // Simulación de venta: selecciona aleatoriamente un surtidor
    int surtidorSeleccionado = rand() % numSurtidores;
    Surtidor* surtidor = surtidores[surtidorSeleccionado];

    // Simular litros vendidos
    double litrosVendidos = 3 + (rand() % 18); // entre 3 y 20 litros
    CategoriaCombustible categoria = static_cast<CategoriaCombustible>(rand() % 3);
    double precioPorLitro = 5000; // Ejemplo de precio
    double monto = litrosVendidos * precioPorLitro;

    // Crear una nueva transacción
    Transaccion* nuevaTransaccion = new Transaccion(contadorTransacciones + 1, "12/10/2024", litrosVendidos, categoria, monto);
    surtidor->venderCombustible(nuevaTransaccion);

    // Actualizar el tanque
    tanque->extraerCombustible(categoria, litrosVendidos);

    std::cout << "Venta simulada en surtidor " << surtidor->obtenerID() << ": " << litrosVendidos << " litros vendidos." << std::endl;
}

