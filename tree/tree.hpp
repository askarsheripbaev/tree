#include <memory>
#include <iostream>

struct tree_node {
  int value;
  tree_node *up;
  std::unique_ptr<tree_node> left, right;
};

struct tree {
  std::unique_ptr<tree_node> root;

  tree_node* insert(const std::unique_ptr<tree_node> &up, std::unique_ptr<tree_node> &node, int val);
  bool remove(std::unique_ptr<tree_node> &node, int value);

  auto insert(int val) -> tree_node *;
  auto remove(int val) -> bool;
};