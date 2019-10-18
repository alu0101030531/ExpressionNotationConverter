#ifndef POSTFIX_H
#define POSTFIX_H

#include "stack.h"

#include <iostream>
#include <string>

class PostFix {
 public:
  PostFix() {};
  PostFix(std::string regular_expression);
  void setRegexp();
  std::string convertInfixToPostfix();
 private:
  bool concat(char symbol1, char symbol2);
  std::string extendedExpression(const std::string& expression); 
  std::string popUntilParenthesis(Stack<char>& stack);
  int precedence(char operator1, char operator2);
  std::string popUntilPrecedence(char operator1, Stack<char>& stack);
  std::string popAll(Stack<char>& stack);
 private:
  std::string regular_expression_;

};
#endif // POSTFIX_H
