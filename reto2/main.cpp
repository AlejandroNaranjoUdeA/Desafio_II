#include <iostream>
#include "EstacionDeServicio.h"
#include "Surtidor.h"
#include "Tanque.h"

using namespace std;

void mostrarMenu() {
    cout << "=== Menu Principal ===" << endl;
    cout << "1. Agregar estacion de servicio" << endl;
    cout << "2. Eliminar estacion de servicio" << endl;
    cout << "3. Verificar fugas de combustible" << endl;
    cout << "4. Simular venta de combustible" << endl;
    cout << "5. Mostrar surtidores de una estacion" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    EstacionDeServicio** estaciones = new EstacionDeServicio*[10];  // Arreglo dinámico para estaciones de servicio
    int numEstaciones = 0;
    int capacidadEstaciones = 10;  // Capacidad inicial de estaciones

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar estación
            if (numEstaciones == capacidadEstaciones) {
                capacidadEstaciones *= 2;  // Duplicar la capacidad de estaciones
                EstacionDeServicio** nuevasEstaciones = new EstacionDeServicio*[capacidadEstaciones];
                for (int i = 0; i < numEstaciones; i++) {
                    nuevasEstaciones[i] = estaciones[i];
                }
                delete[] estaciones;
                estaciones = nuevasEstaciones;
            }
            int id;
            string nombre, ubicacion;
            cout << "Ingrese ID, nombre y ubicacion de la nueva estacion: ";
            cin >> id >> nombre >> ubicacion;
            Tanque* tanque = new Tanque(100, 200, 150);  // Tanque de ejemplo
            estaciones[numEstaciones] = new EstacionDeServicio(id, nombre, ubicacion, tanque);
            numEstaciones++;
            cout << "Estacion agregada con exito." << endl;
            break;
        }
        case 2: {
            // Eliminar estación
            int idEliminar;
            cout << "Ingrese el ID de la estacion a eliminar: ";
            cin >> idEliminar;
            bool eliminado = false;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == idEliminar) {
                    delete estaciones[i];  // Eliminar la estación
                    for (int j = i; j < numEstaciones - 1; j++) {
                        estaciones[j] = estaciones[j + 1];
                    }
                    numEstaciones--;
                    eliminado = true;
                    cout << "Estacion eliminada." << endl;
                        break;
                }
            }
            if (!eliminado) {
                cout << "Estacion no encontrada." << endl;
            }
            break;
        }
        case 3: {
            // Verificar fugas
            int id;
            cout << "Ingrese el ID de la estacion para verificar fugas: ";
            cin >> id;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == id) {
                    if (estaciones[i]->verificarFugas()) {
                        cout << "Se detecto una fuga en la estacion." << endl;
                    } else {
                        cout << "No se detectaron fugas." << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 4: {
            // Simular venta
            int id;
            cout << "Ingrese el ID de la estacion para simular venta: ";
            cin >> id;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == id) {
                    estaciones[i]->simularVenta();
                    break;
                }
            }
            break;
        }
        case 5: {
            // Mostrar surtidores
            int id;
            cout << "Ingrese el ID de la estacion: ";
            cin >> id;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == id) {
                    estaciones[i]->mostrarSurtidores();
                    break;
                }
            }
            break;
        }
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 6);

    // Liberar memoria al final del programa
    for (int i = 0; i < numEstaciones; i++) {
        delete estaciones[i];
    }
    delete[] estaciones;

    return 0;
}
