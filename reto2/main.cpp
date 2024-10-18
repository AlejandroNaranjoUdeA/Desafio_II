#include <iostream>
#include "EstacionDeServicio.h"
#include "Surtidor.h"
#include "Tanque.h"

using namespace std;

void mostrarMenu() {
    cout << "=== Menu Principal ===" << endl;
    cout << "1. Agregar estacion de servicio" << endl;
    cout << "2. Agregar surtidor a estacion" << endl;
    cout << "3. Eliminar surtidor de estacion" << endl;
    cout << "4. Eliminar estacion de servicio" << endl;
    cout << "5. Verificar fugas de combustible" << endl;
    cout << "6. Simular venta de combustible" << endl;
    cout << "7. Mostrar surtidores de una estacion" << endl;
    cout << "8. Calcular monto total de ventas" << endl;
    cout << "9. Fijar precios del combustible" << endl;
    cout << "10. Salir" << endl;
}

int main() {
    EstacionDeServicio** estaciones = new EstacionDeServicio*[10]; // Arreglo dinámico para estaciones de servicio
    int numEstaciones = 0;
    int capacidadEstaciones = 10; // Capacidad inicial de estaciones

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: { // Agregar estación
            if (numEstaciones == capacidadEstaciones) {
                capacidadEstaciones *= 2; // Duplicar la capacidad de estaciones
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
            Tanque* tanque = new Tanque(100, 200, 150); // Tanque de ejemplo
            estaciones[numEstaciones] = new EstacionDeServicio(id, nombre, ubicacion, tanque);
            numEstaciones++;
            cout << "Estacion agregada con exito." << endl;
                break;
        }
        case 2: { // Agregar surtidor
            int idEstacion;
            cout << "Ingrese el ID de la estacion a la que desea agregar un surtidor: ";
            cin >> idEstacion;

            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == idEstacion) {
                    int idSurtidor;
                    string modelo;
                    cout << "Ingrese ID y modelo del surtidor: ";
                    cin >> idSurtidor >> modelo;
                    Surtidor* nuevoSurtidor = new Surtidor(idSurtidor, modelo);
                    estaciones[i]->agregarSurtidor(nuevoSurtidor); // Agregar surtidor a la estación
                    cout << "Surtidor agregado con exito." << endl;
                    break;
                }
            }
            break;
        }
        case 3: { // Eliminar surtidor
            int idEstacion;
            cout << "Ingrese el ID de la estación de la que desea eliminar un surtidor: ";
            cin >> idEstacion;

            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == idEstacion) {
                    int idSurtidor;
                    cout << "Ingrese el ID del surtidor a eliminar: ";
                    cin >> idSurtidor;
                    estaciones[i]->eliminarSurtidor(idSurtidor); // Eliminar surtidor de la estación
                    cout << "Surtidor eliminado con exito." << endl;
                    break;
                }
            }
            break;
        }
        case 4: { // Eliminar estación
            int idEliminar;
            cout << "Ingrese el ID de la estacion a eliminar: ";
            cin >> idEliminar;
            bool eliminado = false;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == idEliminar) {
                    delete estaciones[i]; // Eliminar la estación
                    for (int j = i; j < numEstaciones - 1; j++) {
                        estaciones[j] = estaciones[j + 1]; // Desplazar
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
        case 5: { // Verificar fugas
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
        case 6: { // Simular venta
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
        case 7: { // Mostrar surtidores
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
        case 8: { // Calcular monto total de ventas
            int id;
            cout << "Ingrese el ID de la estacion para calcular ventas: ";
            cin >> id;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == id) {
                    double totalVentas = estaciones[i]->calcularVentasTotales();
                    cout << "Monto total de ventas en la estacion: $" << totalVentas << endl;
                    break;
                }
            }
            break;
        }
        case 9: { // Fijar precios del combustible
            int id;
            double precioRegular, precioPremium, precioEcoExtra;
            cout << "Ingrese el ID de la estacion para fijar precios: ";
            cin >> id;
            cout << "Ingrese precios para Regular, Premium y EcoExtra: ";
            cin >> precioRegular >> precioPremium >> precioEcoExtra;
            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i]->getId() == id) {
                    estaciones[i]->fijarPrecios(precioRegular, precioPremium, precioEcoExtra);
                    cout << "Precios fijados con exito." << endl;
                    break;
                }
            }
            break;
        }
        case 10:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no válida." << endl;
        }
    } while (opcion != 10);

    // Liberar memoria al final del programa
    for (int i = 0; i < numEstaciones; i++) {
        delete estaciones[i];
    }
    delete[] estaciones;

    return 0;
}
