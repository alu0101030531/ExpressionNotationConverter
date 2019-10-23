// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo postfix.cpp: Definiciones de la clase postfix 
//                     
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código


#include "postfix.h"

#include <ctype.h>

// Crea un objeto postfix dado un string
PostFix::PostFix(std::string regular_expression): regular_expression_(regular_expression) {}

// Extiende la expresión introduciendo concatenaciones donde aparecen de manera implícita
std::string PostFix::extendedExpression(const std::string& expression) {
  std::string extended = expression;
  int j, pos = 0;
  for (int i = 0, j = 1; i < expression.size() && j < expression.size(); i++, j++) {
    if (concat((expression[i]), (expression[j]))) {
      extended.insert(i +1 + pos, 1, '&');
      pos++;
    }
  }
  return extended;
}

// devuelve true si se debe introducir una concatenación
bool PostFix::concat(char symbol1, char symbol2) {
  switch (symbol1) {
    case '*':
      if (isalpha(symbol2) || symbol2 == '(')
        return true;
      break;
    case ')':
      if (isalpha(symbol2) || symbol2 == '(')
        return true;
      break;
  }
  if (isalpha(symbol1) && isalpha(symbol2) || isalpha(symbol1) && symbol2 == '(')
    return true;
}

// Convierte la expresión de infija a postfija
std::string PostFix::convertInfixToPostfix() {
  std::stack<char> operator_stack;
  std::string postfix_expression;
  for (int i = 0; i < regular_expression_.size(); i++) {
    if ( isdigit(regular_expression_[i])) 
      postfix_expression += regular_expression_[i];
    else if (regular_expression_[i] == ')')
      postfix_expression += popUntilParenthesis(operator_stack);
    else if (regular_expression_[i] == '(')
      operator_stack.push(regular_expression_[i]);
    else if (operator_stack.empty() || operator_stack.top() == '(')
      operator_stack.push(regular_expression_[i]);
    else if (precedence(regular_expression_[i], operator_stack.top()) == 1)
      operator_stack.push(regular_expression_[i]);
    else if (precedence(regular_expression_[i], operator_stack.top()) == 0) {
      postfix_expression += operator_stack.top();
      operator_stack.pop();
      operator_stack.push(regular_expression_[i]);
    } else if (precedence(regular_expression_[i], operator_stack.top()) == -1)
      postfix_expression += popUntilPrecedence(regular_expression_[i], operator_stack);
    }
  postfix_expression += popAll(operator_stack);
  return postfix_expression;
}

// Saca de la pila hasta vaciarla
std::string PostFix::popAll(std::stack<char>& exp_stack) {
  std::string operators;
  while(!exp_stack.empty()) {
    operators += exp_stack.top();
    exp_stack.pop();
  }
  return operators;
}

// Saca de la pila hasta encontrar un paréntesis
std::string PostFix::popUntilParenthesis(std::stack<char>& exp_stack) {
  char top;
  std::string store_operators;
  while (top != '(') {
    top = exp_stack.top();
    exp_stack.pop();
    store_operators += top;
  }
  store_operators.pop_back();
  return store_operators;
}

// Saca de la pila hasta tener mayor o igual precedencia
std::string PostFix::popUntilPrecedence(char operator1, std::stack<char>& exp_stack) {
  std::string store_operators;
  while (precedence(operator1, exp_stack.top()) == -1) {
    store_operators += exp_stack.top();
    exp_stack.pop();
  }
  if (precedence(operator1, exp_stack.top()) == 0) {
    store_operators += exp_stack.top();
    exp_stack.pop();
  }
  exp_stack.push(operator1);
  return store_operators;
}

// Dados dos operadores devuelve una precedencia
int PostFix::precedence(char operator1, char operator2) {
  int op_precedence = -2;
  switch (operator1) {
      case '/':
        switch (operator2) {
          case '/':
            op_precedence = 0;
            break;
          case '*':
            op_precedence = 0;
            break;
          case '+':
            op_precedence = 1;
            break;
          case '-':
            op_precedence = 1;
            break;
        }
        break;
      case '*':
        switch (operator2) {
          case '/':
            op_precedence = 0;
            break;
          case '*':
            op_precedence = 0;
            break;
          case '+':
            op_precedence = 1;
            break;
          case '-':
            op_precedence = 1;
            break;
        }
      break;
      case '+':
        switch (operator2) {
          case '/':
            op_precedence = -1;
            break;
          case '*':
            op_precedence = -1;
            break;
          case '+':
            op_precedence = 0;
            break;
          case '-':
            op_precedence = 0;
            break;
        }
      break;
      case '-':
        switch (operator2) {
          case '/':
            op_precedence = -1;
            break;
          case '*':
            op_precedence = -1;
            break;
          case '+':
            op_precedence = 0;
            break;
          case '-':
            op_precedence = 0;
            break;
        }
      break;
  }
  return op_precedence;
}
    
