#include "EstacionDeServicio.h"
#include <iostream>

// Constructor con inicialización dinámica
EstacionDeServicio::EstacionDeServicio(int _id, std::string _nombre, std::string _ubicacion, Tanque* _tanque)
    : id(_id), nombre(_nombre), ubicacion(_ubicacion), tanque(_tanque), numSurtidores(0), capacidadSurtidores(12) {
    surtidores = new Surtidor*[capacidadSurtidores];  // Asignar memoria para el arreglo dinámico
}

// Destructor para liberar la memoria dinámica
EstacionDeServicio::~EstacionDeServicio() {
    for (int i = 0; i < numSurtidores; i++) {
        delete surtidores[i];  // Liberar memoria de cada surtidor
    }
    delete[] surtidores;  // Liberar el arreglo dinámico
}

// Método para agregar surtidores dinámicamente
void EstacionDeServicio::agregarSurtidor(Surtidor* nuevoSurtidor) {
    if (numSurtidores == capacidadSurtidores) {
        capacidadSurtidores *= 2;  // Duplicar la capacidad
        Surtidor** nuevoArreglo = new Surtidor*[capacidadSurtidores];
        for (int i = 0; i < numSurtidores; i++) {
            nuevoArreglo[i] = surtidores[i];  // Copiar surtidores existentes
        }
        delete[] surtidores;  // Liberar el arreglo antiguo
        surtidores = nuevoArreglo;  // Actualizar el puntero
    }
    surtidores[numSurtidores++] = nuevoSurtidor;
}

// Mostrar surtidores
void EstacionDeServicio::mostrarSurtidores() const {
    for (int i = 0; i < numSurtidores; i++) {
        std::cout << "Surtidor ID: " << surtidores[i]->obtenerID() << std::endl;
        surtidores[i]->mostrarTransacciones();
    }
}

// Verificar fugas de combustible
bool EstacionDeServicio::verificarFugas() const {
    return tanque->verificarFuga();
}

// Simulación de venta de combustible
void EstacionDeServicio::simularVenta() {
    if (numSurtidores == 0) {
        std::cout << "No hay surtidores disponibles para simular venta." << std::endl;
        return;
    }
    int surtidorSeleccionado = rand() % numSurtidores;
    Surtidor* surtidor = surtidores[surtidorSeleccionado];

    double litrosVendidos = 3 + (rand() % 18); // entre 3 y 20 litros
    CategoriaCombustible categoria = static_cast<CategoriaCombustible>(rand() % 3);
    double precioPorLitro = 5000; // Precio de ejemplo
    double monto = litrosVendidos * precioPorLitro;

    Transaccion* nuevaTransaccion = new Transaccion(surtidor->obtenerID(), "12/10/2024", litrosVendidos, categoria, monto);
    surtidor->venderCombustible(nuevaTransaccion);
    tanque->extraerCombustible(categoria, litrosVendidos);

    std::cout << "Venta simulada en surtidor " << surtidor->obtenerID() << ": " << litrosVendidos << " litros vendidos." << std::endl;
}

// Getter para obtener ID
int EstacionDeServicio::getId() const {
    return id;
}
