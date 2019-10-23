// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo postfix.h: Dada una expresión regular infija la convierte a postfija
//                     
//                 
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código

#ifndef POSTFIX_H
#define POSTFIX_H

#include <stack>
#include <iostream>
#include <string>

// Modo de Uso:
//  Postfix exp("(a|b)*");
//  std::string postexp = exp.convertInfixToPostfix();
class PostFix {
 public:
  PostFix() {};
  PostFix(std::string regular_expression);
  void setRegexp();
  std::string convertInfixToPostfix();
 private:
  bool concat(char symbol1, char symbol2);
  std::string extendedExpression(const std::string& expression); 
  std::string popUntilParenthesis(std::stack<char>& exp_stack);
  int precedence(char operator1, char operator2);
  std::string popUntilPrecedence(char operator1, std::stack<char>& exp_stack);
  std::string popAll(std::stack<char>& exp_stack);
 private:
  std::string regular_expression_;    // Almacena la expresión regular en infija

};
#endif // POSTFIX_H
