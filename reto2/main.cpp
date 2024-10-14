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
    int opcion;
    EstacionDeServicio* estaciones[10]; // Por ejemplo, máximo 10 estaciones
    int numEstaciones = 0;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar estación
            int id;
            string nombre, ubicacion;
            cout << "Ingrese ID, nombre y ubicacion de la nueva estacion: ";
            cin >> id >> nombre >> ubicacion;
            Tanque* tanque = new Tanque(100, 200, 150);  // Ejemplo de tanque
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
                        estaciones[j] = estaciones[j + 1];  // Reajustar el array
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
            cout << "Ingrese el ID de la estación para verificar fugas: ";
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
            cout << "Ingrese el ID de la estación para simular venta: ";
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

    return 0;
}
