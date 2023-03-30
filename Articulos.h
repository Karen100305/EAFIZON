#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <iostream>
#include <string>
using namespace std;
#include <typeinfo>

class Articulo {
public:
  string tipo;
  string nombre;
  int id;
  double precio;
  int disponibilidad;
  Articulo(string n, int id, double p, int d) {
    this->tipo = "Articulo";
    this->nombre = n;
    this->id = id;
    this->precio = p;
    this->disponibilidad = d;
  }
  Articulo(){}
  virtual ~Articulo(){} // hacer que Articulo sea polimorfica

};

class articuloTecnologia : public Articulo {
public:
  articuloTecnologia (string n, int id, double p, int d) : Articulo(n,id,p,d){
    this->tipo = "Tecnologia";
  }
};

class articuloDeporte : public Articulo {
public:
  articuloDeporte(string n, int id, double p, int d) : Articulo(n,id,p,d){
    this->tipo = "Deporte";
  }
};

class articuloExtranjero : public Articulo {
public:
  articuloExtranjero(string n, int id, double p, int d) : Articulo(n,id,p,d){
    this->tipo = "Extranjero";
  }
};
#endif