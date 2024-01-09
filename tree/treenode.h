#ifndef TREENODE_H
#define TREENODE_H


template <class T> class BinaryTree;


template <class T>
class TreeNode
{
	friend class BinaryTree<T>;
private:
	T data{0};
	TreeNode<T>* left{0};
	TreeNode<T>* right{0};
public:
	TreeNode(){};
	TreeNode(const T &item, TreeNode<T>* left_ptr, TreeNode<T>* right_ptr);
	~TreeNode(){};
	T get_data();
	void set_data(T element);
	TreeNode<T>* get_right();
	TreeNode<T>* get_left();
};


template <class T>
TreeNode<T>::TreeNode(const T &item, TreeNode<T>* left_ptr, TreeNode<T>* right_ptr)
{
	data = item;
	left = left_ptr;
	right = right_ptr;
}


template <class T>
T TreeNode<T>::get_data()
{
	return data;
}


template <class T>
void TreeNode<T>::set_data(T element)
{
	data = element;
}


template <class T>
TreeNode<T>* TreeNode<T>::get_right()
{
	return right;
}

template <class T>
TreeNode<T>* TreeNode<T>::get_left()
{
	return left;
}

#endif