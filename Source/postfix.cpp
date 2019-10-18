#include "postfix.h"

#include <ctype.h>

PostFix::PostFix(std::string regular_expression): regular_expression_(extendedExpression(regular_expression)) {}

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

std::string PostFix::convertInfixToPostfix() {
  Stack<char> operator_stack;
  std::string postfix_expression;
  for (int i = 0; i < regular_expression_.size(); i++) {
    if ( isalpha(regular_expression_[i])) 
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
      postfix_expression += operator_stack.pop();
      operator_stack.push(regular_expression_[i]);
    } else if (precedence(regular_expression_[i], operator_stack.top()) == -1)
      postfix_expression += popUntilPrecedence(regular_expression_[i], operator_stack);
    }
  postfix_expression += popAll(operator_stack);
  std::cout << postfix_expression << "\n";
  return postfix_expression;
}

std::string PostFix::popAll(Stack<char>& stack) {
  std::string operators;
  while(!stack.empty())
    operators += stack.pop();
  return operators;
}

std::string PostFix::popUntilParenthesis(Stack<char>& stack) {
  char top;
  std::string store_operators;
  while (top != '(') {
    top = stack.pop();
    store_operators += top;
  }
  store_operators.pop_back();
  return store_operators;
}

std::string PostFix::popUntilPrecedence(char operator1, Stack<char>& stack) {
  std::string store_operators;
  while (precedence(operator1, stack.top()) == -1)
    store_operators += stack.pop();
  if (precedence(operator1, stack.top()) == 0)
    store_operators += stack.pop();
  stack.push(operator1);
  return store_operators;
}


int PostFix::precedence(char operator1, char operator2) {
  int op_precedence = -2;
  switch (operator1) {
      case '*':
        switch (operator2) {
          case '*':
            op_precedence = 0;
            break;
          case '&':
            op_precedence = 1;
            break;
          case '|':
            op_precedence = 1;
            break;
        }
        break;
      case '&':
        switch (operator2) {
          case '*':
            op_precedence = -1;
            break;
          case '&':
            op_precedence = 0;
            break;
          case '|':
            op_precedence = 1;
            break;
        }
      case '|':
        switch (operator2) {
          case '*':
            op_precedence = -1;
            break;
          case '&':
            op_precedence = -1;
            break;
          case '|':
            op_precedence = 0;
            break;
        }
  }
  return op_precedence;
}
    
