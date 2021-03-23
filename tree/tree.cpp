#include "tree.hpp"

auto tree::insert(int val) -> tree_node * {
    // Код для добавления элемента в дерево
    return nullptr;
tree_node* tree::insert(const std::unique_ptr<tree_node> &up, std::unique_ptr<tree_node> &node, int value) {
	if (!node) {
		node = std::make_unique<tree_node>();
		node->value = value;
		node->left = nullptr;
		node->right = nullptr;
		node->up = up.get();
		return node.get();
	}
	if (value < node->value)
		return insert(node, node->left, value);
	if (value > node->value)
		return insert(node, node->right, value); 
	return node.get(); 
}
bool tree::remove(std::unique_ptr<tree_node> &node, int value) {
	if (!node)
		return false;
	if (node->value == value) {
        if (node->left == nullptr || node->right == nullptr) {
            node = std::move(node->left ? node->left : node->right);
            return true;
        }

auto tree::remove(int val) -> bool {
    // Код для удаления элемента из дерева
    return false;
        tree_node *parent = node->right.get(); 
        tree_node *tmp = node->right.get(); 

    
        while (tmp->left) {
            parent = tmp;
            tmp = tmp->left.get();
        }
        node->value = tmp->value; 

        if (parent != tmp) { 
            parent->left = std::move(tmp->right); 
        }
        else {
            node->right = std::move(tmp->right); 
        }
		return true; 
	}
	else if (value < node->value) {
		return remove(node->left, value); 
	}
	else {
		return remove(node->right, value); 
	}
}
auto tree::insert(int value) -> tree_node * {
    return insert(nullptr, root, value);
}
auto tree::remove(int value) -> bool {
    return remove(root, value);
}