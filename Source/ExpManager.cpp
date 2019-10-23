// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo Expmanger.cpp: Utiliza la clase exp_converter para obtener las distintas notaciones dada un exp regular
//                     
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código


#include "postfix.h"
#include "regular_expression_converter.h"

#include <fstream>

// Función que muestra el modo de uso
void showinfo() {
  std::cout << "Modo de uso: ./ExpConverter file_in file_out\n"
  "Utilice --help para más información\n";
}

int main(int argc, char* argv[]) {
  switch (argc) {                     // Switch case para comprobar las opciones que se le introducen al programa 
    case 1:
      showinfo();
      break;
    case 2:
      if (argv[1] == "--help")
        std::cout << " -> file_in es el fichero que debe contener las expresiones regulares a las que se les quiere\n"
        "cambiar la notación\n"
        " -> file_out es el fichero en el que se imprimirán las expresiones regulares en las distintas notaciones y\n"
        " el número de nodos que se han generado";
      else
        showinfo();
      break;
    case 3:
      std::ifstream file_in(argv[1]);
      std::ofstream file_out(argv[2]);
      if (file_in.is_open() && file_out.is_open()) {
        std::string regexp;
        file_out << "Infija\tPostfija\tPrefija\tNodos\n";
        file_out << "===================================\n";
        while(getline(file_in,regexp)) {
          file_out << regexp << "\t";
          RegularExpressionConverter converter(regexp);
          file_out << converter.getPostfixExpression() << "\t";
          converter.getPrefixExpression(file_out); 
          file_out << "\t";
          file_out << converter.getNodesCreated() << "\t";
          file_out << "\n";
        }
      }
      break;
  }
}
