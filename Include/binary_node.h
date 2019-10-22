#include <vector>
#include <iostream>

template <class T>
class BinaryNode {
 public:
  BinaryNode(T data, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr);
  BinaryNode(T data, BinaryNode<T> left, BinaryNode<T> right);
  T getData() const { return data_;};
  BinaryNode<T>* getLeft() const {return left_;};
  BinaryNode<T>* getRight() const {return right_;};
  void setLeft(BinaryNode<T>* left) {left_ = left;};
  void setRight(BinaryNode<T>* right) {right_ = right;};
  void preorderPrint(std::ostream& os);
 private:
  void preorderPrint(std::ostream& os, BinaryNode<T>* node);
  T data_;
  BinaryNode<T>* left_;
  BinaryNode<T>* right_;
};

template <class T>
BinaryNode<T>::BinaryNode(T data, BinaryNode<T> left, BinaryNode<T> right)
  : data_(data), left_(left), right_(right) {}

template <class T>
BinaryNode<T>::BinaryNode(T data, BinaryNode<T>* left, BinaryNode<T>* right)
    : data_(data), left_(left), right_(right) {
}

template <class T>
void BinaryNode<T>::preorderPrint(std::ostream& os) {
  preorderPrint(os,this);
}

template <class T>
void BinaryNode<T>::preorderPrint(std::ostream& os, BinaryNode<T>* node) {
  if (node == nullptr)
    return;
  os << node->data_;
  preorderPrint(os,node->left_);
  preorderPrint(os,node->right_);
}
