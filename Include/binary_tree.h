#include "binary_node.h"

template <class T>
class BinaryTree {
 public:
  BinaryTree();
  BinaryTree(T data);
  BinaryNode<T>* getRoot() {return root;};
  void insertTrees(BinaryTree<T>& left, BinaryTree<T>& right);
  void insertTrees(BinaryTree<T>& left);
  void printPreorder(std::ostream& os);
 private:
  void insertTree(BinaryNode<T>* node, BinaryNode<T>* out_node);
  void printPreorder(std::ostream& os, BinaryNode<T>* node);
 private:
  BinaryNode<T>* root;
};

template <class T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(T data) {
 root = new BinaryNode<T>(data);
}

template <class T>
void BinaryTree<T>::insertTrees(BinaryTree<T>& left) {
  BinaryNode<T>* left_root = new BinaryNode<T>(left.getRoot()->getData());
  root->setLeft(left_root);
  insertTree(root->getLeft(), left.getRoot());
}

template <class T>
void BinaryTree<T>::insertTrees(BinaryTree<T>& left, BinaryTree<T>& right) {
  BinaryNode<T>* left_root = new BinaryNode<T>(left.getRoot()->getData());
  BinaryNode<T>* right_root = new BinaryNode<T>(right.getRoot()->getData());
  root->setLeft(left_root);
  root->setRight(right_root);
  insertTree(root->getLeft(), left.getRoot());
  insertTree(root->getRight(), right.getRoot());
}

template <class T>
void BinaryTree<T>::insertTree(BinaryNode<T>* node, BinaryNode<T>* out_node) {
  if (out_node->getLeft() == nullptr)
    return;
  BinaryNode<T>* left_node = new BinaryNode<T>(out_node->getLeft()->getData());
  node->setLeft(left_node);
  insertTree(node->getLeft(), out_node->getLeft());
  if (out_node->getRight() == nullptr)
    return;
  BinaryNode<T>* right_node = new BinaryNode<T>(out_node->getRight()->getData());
  node->setRight(right_node);
  insertTree(node->getRight(), out_node->getRight());
}

template <class T>
void BinaryTree<T>::printPreorder(std::ostream& os) {
  printPreorder(os,root);
}

template <class T>
void BinaryTree<T>::printPreorder(std::ostream& os, BinaryNode<T>* node) {
  if (node == nullptr)
    return;
  os << node->getData();
  printPreorder(os, node->getLeft());
  printPreorder(os, node->getRight());
}
