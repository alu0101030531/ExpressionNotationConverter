#include "postfix.h"
#include "regular_expression_converter.h"
int main() {
  RegularExpressionConverter t("(a|b)(c|d)");
  t.createBinaryTree();
};
