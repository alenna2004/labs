#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include "treenode.h"


using namespace std;

template <typename T>
void delete_node(TreeNode<T>* node)
{
	delete node;
}


template <class T>
class BinaryTree
{
private:
	TreeNode<T>* root{0};
	TreeNode<T>* create_new_node(const T &item, TreeNode<T>* left_ptr, TreeNode<T>* right_ptr);
	void copy_helper(TreeNode<T>* &copy_to, const TreeNode<T>* copy_from);
	void map_helper(TreeNode<T>* node, T (*func)(T));
	void get_elements_as_vector(TreeNode<T>* node, std::vector<T> &items, string order);
public:
	BinaryTree(){};
	BinaryTree(TreeNode<T>* root_node);
	BinaryTree(T* items, int length);
	BinaryTree(const BinaryTree<T> &tree);
	~BinaryTree();
	BinaryTree<T>* get_subtree(T root_value);
	bool search_subtree(const T root_value, const string subtree_string, const string order); 
	void triversal(TreeNode<T>* node, void (*visit)(TreeNode<T>*), const string order);
	void tree_to_string(TreeNode<T>* node, string &result, const string order); 
	void insert(T element);
	void remove(T element);
	TreeNode<T>* search(TreeNode<T>* node, T element);
	T reduce(T (*func)(T item_1, T item_2), T start_const, string order);
	BinaryTree<T>* map(T (*func)(T));
	BinaryTree<T>* balance(); 
	void print_tree(TreeNode<T>* node, int space = 0, int element_max_length = 10);
	TreeNode<T>* get_root();
};


template <class T>
TreeNode<T>* BinaryTree<T>::create_new_node(const T &item, TreeNode<T>* left_ptr, TreeNode<T>* right_ptr)
{
	TreeNode<T>* node = new TreeNode<T>(item, left_ptr, right_ptr);
	return node;
}


template <class T>
void BinaryTree<T>::copy_helper(TreeNode<T>* &copy_to, const TreeNode<T>* copy_from)
{
	if(copy_from == NULL){
		copy_to = NULL; 
	} else{
		copy_to = new TreeNode<T>; 
		copy_to->data = copy_from->data;
		copy_helper(copy_to->left, copy_from->left);
		copy_helper(copy_to->right, copy_from->right);
	}
}


template <class T>
BinaryTree<T>::BinaryTree(TreeNode<T>* root_node)
{
	copy_helper(this->root, root_node);
}


template <class T>
BinaryTree<T>::BinaryTree(T* items, int length)
{
	if(length <= 0){
		throw std::invalid_argument("Invalid array size");
	}
	sort(items, items+length);
	int middle = length / 2;
	root = create_new_node(items[middle], 0, 0);
	queue<pair<TreeNode<T>*, pair<int, int>>> nodes_queue;
	nodes_queue.push({root, {0, middle - 1}});
	nodes_queue.push({root, {middle + 1, length - 1}});
	while (!nodes_queue.empty()) {
		pair<TreeNode<T>*, pair<int, int>> current = nodes_queue.front();
		nodes_queue.pop();
		TreeNode<T>* parent = current.first;
		int left = current.second.first;
		int right = current.second.second;
		if (left <= right && parent != NULL) {
			int middle = (left + right) / 2;
			TreeNode<T>* child = new TreeNode<T>(items[middle], 0, 0);
			if (items[middle] < parent->get_data()){
				parent->left = child;
			}
			else{
				parent->right = child;
			}
			nodes_queue.push({child, {left, middle - 1}});
			nodes_queue.push({child, {middle + 1, right}});
		}
	}
}


template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree)
{
	if(tree.root == 0){
		root = 0;
	}
	else{
		copy_helper(this->root, tree.root);
	}
}


template <class T>
BinaryTree<T>::~BinaryTree()
{
	this->triversal(root, delete_node, "LRN");
}


template <class T>
BinaryTree<T>* BinaryTree<T>::get_subtree(T root_value)
{
	TreeNode<T>* target = this->search(root, root_value);
	if(!target){
		return 0;
	}
	BinaryTree<T>* subtree = new BinaryTree<T>(target);
	return subtree;
}


template <class T>
bool BinaryTree<T>::search_subtree(const T root_value, const string subtree_string, const string order)
{
	if(order.length() != 3){
		throw std::invalid_argument("Invalid order string");
	}
	BinaryTree<T>* candidate = get_subtree(root_value);
	if(!candidate){
		return false;
	}
	string candidate_string = "";
	candidate->tree_to_string(candidate->get_root(), candidate_string, order);
	if(candidate_string == subtree_string){
		return true;
	}
	return false;
}


template <class T>
void BinaryTree<T>::triversal(TreeNode<T>* node, void (*visit)(TreeNode<T>*), const string order)
{
	if(!node){
		return;
	}
	if(order.length() != 3){
		throw std::invalid_argument("Invalid order string");
	}
	for(int i = 0; i < order.length(); i++){
		switch(order[i]){
			case 'N':{
				visit(node);
				break;
			}
			case 'L':{
				triversal(node->left, visit, order);
				break;
			}
			case 'R':{
				triversal(node->right, visit, order);
				break;
			}
		}
	}
}


template <class T>
void BinaryTree<T>::tree_to_string(TreeNode<T>* node, string &result, const string order)
{
	if(!node){
		return;
	}
	if(order.length() != 3){
		throw std::invalid_argument("Invalid order string");
	}
	for(int i = 0; i < order.length(); i++){
		switch(order[i]){
			case 'N':{
				result.push_back('{');
				ostringstream str_steam;
				str_steam << node->data;
				result += str_steam.str();
				result.push_back('}');
				break;
			}
			case 'L':{
				result.push_back('(');
				tree_to_string(node->left, result, order);
				result.push_back(')');
				break;
			}
			case 'R':{
				result.push_back('[');
				tree_to_string(node->right, result, order);
				result.push_back(']');
				break;	
			}
		}
	}
}


template <class T>
void BinaryTree<T>::insert(T element)
{
	if(!root){
		TreeNode<T>* new_node = create_new_node(element, 0, 0);
		root = new_node;
	}
	else{
		TreeNode<T>* current = root;
		TreeNode<T>* prev = root;
		while(current){
			if(current->data == element){
				return;
			}
			if(current->data < element){
				prev = current;
				current = current->right;
			}
			else{
				prev = current;
				current = current->left;
			}
		}
		TreeNode<T>* new_node = create_new_node(element, 0, 0);
		if(element > prev->data){
			prev->right = new_node;
		}
		else{
			prev->left = new_node;
		}
	}
}


template <class T>
void BinaryTree<T>::remove(T element)
{
	if(!root){
		return;
	}
	if(root->data == element){
		if(root->left == 0 && root->right == 0){
			delete root;
			root = 0;
		}
		else if(root->left == 0 ^ root->right == 0){
			if(root->left == 0){
				TreeNode<T>* temp = root->right;
				delete root;
				root = temp;
			}
			else{
				TreeNode<T>* temp = root->left;
				delete root;
				root = temp;
			}
		}
		else{
			TreeNode<T>* temp = root->right;
			TreeNode<T>* prev_temp = root;
			while(temp->left){
				prev_temp = temp;
				temp = temp->left;
			}
			root->data = temp->data;
			temp->data = element;
			if(temp->left == 0 && temp->right == 0){
				if(prev_temp->left == temp){
					prev_temp->left = 0;
				}
				else{
					prev_temp->right = 0;
				}
				delete temp;
			}
			else{
				if(prev_temp->left == temp){
					prev_temp->left = temp->right;
				}
				else{
					prev_temp->right = temp->right;
				}
				delete temp;
			}
		}
	}
	else{
		TreeNode<T>* current = root;
		TreeNode<T>* prev = 0;
		while(current->data != element){
			if(current->data < element){
				prev = current;
				current = current->right;
			}
			else{
				prev = current;
				current = current->left;
			}
		}
		if(prev != 0){
			if(current->left == 0 && current->right == 0){
				if(prev->left == current){
					prev->left = 0;
				}
				else{
					prev->right = 0;
				}
				delete current; 
			}
			else if(current->left == 0 ^ current->right == 0){
				if(current == prev->left){
					if(current->left == 0){
						prev->left = current->right;
					}
					else{
						prev->left = current->left;
					}
					delete current;
				}
				else{
					if(current->left == 0){
						prev->right = current->right;
					}
					else{
						prev->right = current->left;
					}
					delete current;
				}
			}
			else{
				TreeNode<T>* temp = current->right;
				TreeNode<T>* prev_temp = current;
				while(temp->left){
					prev_temp = temp;
					temp = temp->left;
				}
				current->data = temp->data;
				temp->data = element;
				if(temp->left == 0 && temp->right == 0){
					if(prev_temp->left == temp){
						prev_temp->left = 0;
					}
					else{
						prev_temp->right = 0;
					} 
					delete temp;
				}
				else{
					if(prev_temp->left == temp){
						prev_temp->left = temp->right;
					}
					else{
						prev_temp->right = temp->right;
					}
					delete temp;
				}
			}
		}
	}
}


template <class T>
TreeNode<T>* BinaryTree<T>::search(TreeNode<T>* node, T element)
{
	if(node == 0 || node->data == element){
		return node;
	}
	if( node->data < element){
		return search(node->right, element);
	}
	return search(node->left, element);
}


template <class T>
void BinaryTree<T>::get_elements_as_vector(TreeNode<T>* node, std::vector<T> &result, string order)
{
	if(!node){
		return;
	}
	if(order.length() != 3){
		throw std::invalid_argument("Invalid order string");
	}
	for(int i = 0; i < order.length() ; i++){
		switch(order[i]){
			case 'N':{
				result.push_back(node->data);
				break;
			}
			case 'L':{
				get_elements_as_vector(node->left, result, order);
				break;
			}
			case 'R':{
				get_elements_as_vector(node->right, result, order);
				break;	
			}
		}
	}
}

template <class T>
void BinaryTree<T>::map_helper(TreeNode<T>* node, T (*func)(T))
{
	if(!node){
		return;
	}
	node->data = func(node->data);
	map_helper(node->left, func);
	map_helper(node->right, func);
}


template <class T>
T BinaryTree<T>::reduce(T (*func)(T item_1, T item_2), T start_const, string order)
{
	if(order.length() != 3){
		throw std::invalid_argument("Invalid order string");
	}
	vector<T> items;
	get_elements_as_vector(root, items, order);
	T current = start_const;
	for (int i = 0; i < items.size(); ++i){
		T new_element = func(items[i], current);
		current = new_element;
	}
	return current;
}


template <class T>
BinaryTree<T>* BinaryTree<T>::map(T (*func)(T)){
	BinaryTree<T>* copy = new BinaryTree<T>(*this);
	map_helper(copy->root, func);
	return copy;
}


template <class T>
BinaryTree<T>* BinaryTree<T>::balance()
{
	vector<T> items;
	get_elements_as_vector(root, items, "NLR");
	BinaryTree<T>* balanced = new BinaryTree<T>(items.data(), items.size());
	return balanced;
}


template <class T>
void BinaryTree<T>::print_tree(TreeNode<T>* node, int space, int element_max_length){
	if (node != 0){
		space += element_max_length;
		print_tree(node->right, space);
		for (int i = element_max_length; i < space; i++)
			cout << " ";
		cout << node->data << "\n";
		print_tree(node->left, space);
	}
}


template <class T>
TreeNode<T>* BinaryTree<T>::get_root()
{
	return root;
}


#endif