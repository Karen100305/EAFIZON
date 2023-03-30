#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Inventario : public LinkedList {
public:
  // constructor inventario
  Inventario() {
    articuloDeporte balon("BalonFootball", 1001, 5808.0, 10);
    head = new Node(balon);
    articuloTecnologia ipad("IPad", 1002, 365900.0, 4);
    Node *segundo = new Node(ipad);
    head->next = segundo;
    articuloDeporte bici("Bicicleta", 1003, 49990.0, 6);
    Node *tercero = new Node(bici);
    segundo->next = tercero;
    articuloTecnologia headphones("Audifonos", 1004, 60990.0, 6);
    Node *cuarto = new Node(headphones);
    tercero->next = cuarto;
    articuloExtranjero ramen("Ramen", 1005, 800.0, 14);
    Node* quinto = new Node(ramen);
    cuarto->next = quinto;
  }

  // método para añadir un articulo nuevo de deporte al inventario
  void addDeporte(string n, int id, int p, int d) {
    if (existe(n) == true) {
      cout << "Un articulo con este nombre ya existe" << endl;
    } else if (existe(id)) {
      cout << "Ya esxiste un articulo con este numero de id" << endl;
    } else {
      articuloDeporte nuevoD(n, id, p, d);
      Node *nuevoArticulo = new Node(nuevoD);
      if (head == NULL) {
        head = nuevoArticulo;
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = nuevoArticulo;
      }
    }
  }

  // método para añadir un articulo nuevo de tecnologia al inventario
  void addTecnologia(string n, int id, int p, int d) {
    if (existe(n) == true) {
      cout << "Un articulo con este nombre ya existe" << endl;
    } else if (existe(id) == true) {
      cout << "Ya existe un articulo con este numero de id" << endl;
    } else {
      articuloTecnologia nuevoT(n, id, p, d);
      Node *nuevoArticulo = new Node(nuevoT);
      if (head == NULL) {
        head = nuevoArticulo;
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = nuevoArticulo;
      }
    }
  }

  // método para añadir un articulo extranjero nuevo al inventario
  void addExtranjero(string n, int id, double p, int d) {
    if (existe(n) == true) {
      cout << "Un articulo con este nombre ya existe" << endl;
    } else if (existe(id) == true) {
      cout << "Ya existe un articulo con este numero de id" << endl;
    } else {
      articuloExtranjero nuevoE(n, id, p, d);
      Node *nuevoArticulo = new Node(nuevoE);
      if (head == NULL) {
        head = nuevoArticulo;
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = nuevoArticulo;
      }
    }
  }

  // método para eliminar un articulo del inventario
  void remove(int idBuscado) {
    if (head == NULL) {
      cout << "El inventario esta vacio" << endl;
    }
    if (head->articulo.id == idBuscado) {
      Node *oldPrimero = head;
      head = head->next;
      delete oldPrimero;
    }
    else{
      Node *actual = head;
      while (actual != NULL) {
        if (actual->next->articulo.id == idBuscado) {
          Node *articuloEliminado = actual->next;
          actual->next = articuloEliminado->next;
          delete articuloEliminado;
          break;
        }
      }
      actual = actual->next;
    }
  }

  // método para mostrar el inventario
  // head, articulos de tecnología, luego articulos de deporte
  void show() {
    if (head == NULL) {
      cout << "El inventario esta vacio." << endl;
    }
    Node *actual = head;
    cout << endl << "-+-+- ARTICULOS DE TECNOLOGIA -+-+-" << endl << endl;
    while (actual != NULL) {
      if (actual->articulo.tipo == "Tecnologia") {
        cout << endl;
        cout << "Nombre: " << actual->articulo.nombre
             << "    Id: " << actual->articulo.id << endl;
        cout << "Precio: " << actual->articulo.precio
             << "    Disponibilidad: " << actual->articulo.disponibilidad
             << endl;
        cout << endl << endl;
      }
      actual = actual->next;
    }
    actual = head;
    cout << endl << "-+-+- ARTICULOS DE DEPORTE -+-+-" << endl << endl;
    while (actual != NULL) {
      if (actual->articulo.tipo == "Deporte") {
        cout << endl;
        cout << "Nombre: " << actual->articulo.nombre
             << "    Id: " << actual->articulo.id << endl;
        cout << "Precio: " << actual->articulo.precio
             << "    Disponibilidad: " << actual->articulo.disponibilidad
             << endl;
        cout << endl << endl;
      }
      actual = actual->next;
    }
    actual = head;
    cout << endl << "-+-+- ARTICULOS EXTRANJEROS -+-+-" << endl <<"10% de impuesto"<< endl;
    while (actual != NULL) {
      if (actual->articulo.tipo == "Extranjero") {
        cout << endl;
        cout << "Nombre: " << actual->articulo.nombre
             << "    Id: " << actual->articulo.id << endl;
        cout << "Precio: " << actual->articulo.precio
             << "    Disponibilidad: " << actual->articulo.disponibilidad
             << endl;
        cout << endl << endl;
      }
      actual = actual->next;
    }
  }

  void modNombre(int idBuscado) {
    string newN;
    if (head == NULL) {
      cout << "El inventario esta vacio" << endl;
    }
    Node *actual = head;
    while (actual->next != NULL) {
      if (actual->articulo.id == idBuscado) {
        cout << "Ingrese el nuevo nombre: ";
        cin >> newN;
        actual->articulo.nombre = newN;
        return;
      }
      actual = actual->next;
    }
  }

  void modPrecio(int idBuscado) {
    int newP;
    if (head == NULL) {
      cout << "El inventario esta vacio" << endl;
    }
    Node *actual = head;
    while (actual->next != NULL) {
      if (actual->next->articulo.id == idBuscado) {
        cout << "Ingrese el nuevo precio: ";
        cin >> newP;
        actual->articulo.precio = newP;
        return;
      }
      actual = actual->next;
    }
  }

  void modDisponibilidad(int idBuscado) {
    int newD;
    if (head == NULL) {
      cout << "El inventario esta vacio" << endl;
    }
    Node *actual = head;
    while (actual->next != NULL) {
      if (actual->articulo.id == idBuscado) {
        cout << "Ingrese la nueva disponibilidad: ";
        cin >> newD;
        actual->articulo.disponibilidad = newD;
        return;
      }
      actual = actual->next;
    }
  }

  int contar() {
    int contador = 0;
    Node *current = head;
    while (current != NULL) {
      contador++;
      current = current->next;
    }
    return contador;
  }

  double sumar() {
    double suma = 0;
    Node *current = head;
    while (current != NULL) {
      suma += current->articulo.precio * current->articulo.disponibilidad;
      current = current->next;
    }
    return suma;
  }
};
#endif
