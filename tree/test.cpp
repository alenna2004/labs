#include <iostream>
#include <string>
#include <cassert>
#include "treenode.h"
#include "tree.h"


using namespace std;


string INSERT_1 = "{4}({2}({1}()[])[{3}()[]])[{5}()[{6}()[{9}()[{17}({10}()[])[]]]]]";
string INSERT_2 = "{-12}()[{6}({3}()[])[]]";
string REMOVE_1 = "{4}({1}()[])[{5}()[{6}()[{9}()[{17}()[]]]]]";
string REMOVE_2 = "{6}({3}()[])[]";
string TO_STRING_NRL = "{6}[]({3}[]())";
string TO_STRING_RLN = "[]([](){3}){6}";
string TO_STRING_LNR = "((){3}[]){6}[]";
string BALANCED_TREE = "{6}({4}({1}()[])[{5}()[]])[{9}()[{17}()[]]]";
string MAPPED_TREE = "{36}({9}()[])[]";
string SUBTREE_STR = "{4}({1}()[])[{5}()[]]";


void test_creating(int* items, int len)
{
	TreeNode<int>* root = new TreeNode<int>(1,0,0);
	BinaryTree<int> tree_1(items, len);
	assert(tree_1.get_root() != 0);
	cout << "BinaryTree constructor from array OK\n";
	BinaryTree<int> tree_2(tree_1);
	assert(tree_2.get_root() != 0);
	cout << "BinaryTree copy constructor OK\n";
	BinaryTree<int> tree_3(root);
	assert(tree_3.get_root() != 0);
	cout << "BinaryTree constructor from root OK\n";
	BinaryTree<int> tree_4;
	assert(tree_4.get_root() == 0);
	cout << "BinaryTree empty constructor OK\n";
}


void test_base_operations(BinaryTree<int>* tree_1, BinaryTree<int>* tree_0)
{
	tree_1->insert(9);
	tree_1->insert(17);
	tree_1->insert(10);
	string res_insert_1 = "";
	tree_1->tree_to_string(tree_1->get_root(), res_insert_1, "NLR");
	assert(res_insert_1 == INSERT_1);
	tree_0->insert(-12);
	tree_0->insert(6);
	tree_0->insert(3);
	string res_insert_2 = "";
	tree_0->tree_to_string(tree_0->get_root(), res_insert_2, "NLR");
	assert(res_insert_2 == INSERT_2);
	cout << "BinaryTree insert OK\n";
	tree_1->remove(2);
	tree_1->remove(3);
	tree_1->remove(10);
	tree_0->remove(-12);
	string res_remove_1 = "";
	string res_remove_2 = "";
	tree_1->tree_to_string(tree_1->get_root(), res_remove_1, "NLR");
	tree_0->tree_to_string(tree_0->get_root(), res_remove_2, "NLR");
	assert(res_remove_1 == REMOVE_1);
	assert(res_remove_2 == REMOVE_2);
	cout << "BinaryTree remove OK\n";
	TreeNode<int>* node_1 = tree_1->search(tree_1->get_root(), 16);
	TreeNode<int>* node_2 = tree_1->search(tree_1->get_root(), 6);
	assert(!node_1);
	assert(node_2->get_data() == 6);
	cout << "BinaryTree search OK\n";
}


void test_converting_to_string(BinaryTree<int> tree)
{
	string res_1 = "";
	tree.tree_to_string(tree.get_root(), res_1, "NRL");
	string res_2 = "";
	tree.tree_to_string(tree.get_root(), res_2, "RLN");
	string res_3 = "";
	tree.tree_to_string(tree.get_root(), res_3, "LNR");
	assert(res_1 == TO_STRING_NRL);
	assert(res_2 == TO_STRING_RLN);
	assert(res_3 == TO_STRING_LNR);
	cout << "BinaryTree converting to string OK\n";
}


void test_get_and_search_subtree(BinaryTree<int>* tree)
{
	BinaryTree<int>* subtree = tree->get_subtree(4);
	string res = "";
	subtree->tree_to_string(subtree->get_root(), res, "NLR");
	assert(res == SUBTREE_STR);
	cout << "BinaryTree get subtree OK\n";
	bool is_subtree_1 = tree->search_subtree(4, res, "NLR");
	bool is_subtree_2 = tree->search_subtree(2, res, "NLR");
	assert(is_subtree_1);
	assert(!is_subtree_2);
	cout << "BinaryTree search subtree OK\n";
}


void test_balance(BinaryTree<int> tree)
{
	BinaryTree<int>* balanced = tree.balance();
	string res = "";
	balanced->tree_to_string(balanced->get_root(), res, "NLR");
	assert(res == BALANCED_TREE);
	cout << "BinaryTree balance OK\n";
}


int get_sqr(int num)
{
	return num*num;
}


void test_map(BinaryTree<int> tree)
{
	BinaryTree<int>* mapped = tree.map(get_sqr);
	string res = "";
	mapped->tree_to_string(mapped->get_root(), res, "NLR");
	assert(res == MAPPED_TREE);
	cout << "BinaryTree map OK\n";
}


int get_sum(int a, int b)
{
	return a+b;
}


void test_reduce(BinaryTree<int> tree)
{
	int sum = tree.reduce(get_sum, 0, "RNL");
	assert(sum == 9);
	cout << "BinaryTree reduce OK\n";
}


int main()
{
	int* array = new int[6];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	array[5] = 6;
	test_creating(array, 6);
	BinaryTree<int> tree_0;
	BinaryTree<int> tree_1(array, 6);
	test_base_operations(&tree_1, &tree_0);
	test_converting_to_string(tree_0);
	test_balance(tree_1);
	BinaryTree<int>* tree_3 = tree_1.balance();
	test_get_and_search_subtree(tree_3);
	test_map(tree_0);
	test_reduce(tree_0);
	return 0;
}