#ifndef MENU_H
#define MENU_H
#include "Carrito.h"
#include "Cliente.h"
#include "Coordinador.h"
#include "Inventario.h"
#include <iostream>
using namespace std;

// Menú principal
Inventario inventario;               // Crear inventario
Coordinador coordinador(inventario); // Crear coordinador
Carrito carrito;                     // Crear carrito
Cliente cliente(carrito);            // Crear cliente

void menu() {
  int opcion;
  do {
    cout << "Seleccione el tipo de usuario: " << endl;
    cout << "1. Coordinador" << endl;
    cout << "2. Cliente" << endl;
    cout << "3. Salir" << endl << endl;
    cout << "Opción: ";
    int choice1;
    cin >> choice1;
    opcion = choice1;
    system("clear");

    switch (opcion) {
    case 1: {
      // Menú del coordinador
      int opcion_coordinador;
      do {
        cout << endl
             << "Bienvenido coordinador, ¿Qué desea hacer? " << endl
             << endl;
        cout << "1. Agregar artículo" << endl;
        cout << "2. Modificar artículo" << endl;
        cout << "3. Eliminar artículo" << endl;
        cout << "4. Volver al menú principal" << endl;
        cout << endl << "Opción: ";
        int choice2;
        cin >> choice2;
        opcion_coordinador = choice2;
        system("clear");

        switch (opcion_coordinador) {
        case 1: {
          // Agregar artículo
          int repeat;
          do {
            coordinador.agregarArticulo();
            cout << "Desea agregar otro articulo?" << endl
                 << "(0) No" << endl
                 << "(1) Si" << endl;
            cin >> repeat;
            system("clear");
          } while (repeat != 0);
          break;
        }
        case 2: {
          // Modificar artículo
          int repeat;
          do {
            coordinador.modificarArticulo();
            cout << "Desea modificar algo mas?" << endl
                 << "(0) No" << endl
                 << "(1) Si" << endl;
            cin >> repeat;
            system("clear");
          } while (repeat != 0);
          break;
        }
        case 3: {
          // Eliminar artículo
          int repeat;
          do {
            coordinador.eliminarArticulo();
            cout << "Desea modificar algo mas?" << endl
                 << "(0) No" << endl
                 << "(1) Si" << endl;
            cin >> repeat;
            system("clear");
          } while (repeat != 0);
          break;
        }
        case 4: {
          // Volver al menú principal
          break;
        }
        default: {
          cout << "Opción inválida" << endl;
          break;
        }
        }
      } while (opcion_coordinador != 4);
      break;
    }
    case 2: {
      // Menú del cliente
      int opcion_cliente;
      do {
        cout << endl << "Menú del cliente" << endl;
        cout << "1. Comprar artículo" << endl;
        cout << "2. Pagar" << endl;
        cout << "3. Cancelar compra" << endl;
        cout << "4. Volver al menú principal" << endl;
        cout << "Opción: ";
        int choice3;
        cin >> choice3;
        opcion_cliente = choice3;
        system("clear");

        switch (opcion_cliente) {
        case 1: {
          // Comprar artículo del inventario y agregarlo al carrito
          int repeat;
          do {
            cliente.comprarArticulo(inventario);
            cout << "Desea comprar algo mas?" << endl
                 << "(0) No" << endl
                 << "(1) Si" << endl;
            cin >> repeat;
            system("clear");
          } while (repeat != 0);
          break;
        }
        case 2: {
          // Pagar
          cliente.pagar();
          break;
        }
        case 3: {
          // Cancelar compra y devolver articulos al inventario
          cliente.devolver(inventario);
          break;
        }
        case 4: {
          // Volver al menú principal
          break;
        }
        default:
          cout << "Opción inválida" << endl;
          break;
        }
      } while (opcion_cliente != 4);
      break;
    }
    case 3: {
      // Salir
      break;
    }
    default: {
      cout << "Opción inválida" << endl;
      break;
    }
    }
  } while (opcion != 3);
}

#endif