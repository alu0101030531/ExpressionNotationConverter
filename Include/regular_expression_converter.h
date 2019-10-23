// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo regular_expression_converter.h: Dada una expresión regular permite
//                                         obtener su notación postfija y prefija
//                     
//                 
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código

#ifndef REGULAR_EXPRESSION_CONVERTER_H
#define REGULAR_EXPRESSION_CONVERTER_H

#include "postfix.h"
#include "binary_tree.h"

#include <stack>

class RegularExpressionConverter {
 public:
  RegularExpressionConverter(std::string regexp);
  BinaryTree<char> createBinaryTree();
  int getNodesCreated() {return expression_tree_.getSize();};
  void getPrefixExpression(std::ostream& os) {expression_tree_.printPreorder(os);};
  std::string getPostfixExpression() {return postfix_converter_.convertInfixToPostfix();};
 private:
  bool isBinary(char regexp_operator);
 private:
  PostFix postfix_converter_;           // Objeto postfix para convertir la expresión a postfija 
  BinaryTree<char> expression_tree_;     // Almacena el árbol de la expresión
};

#endif
