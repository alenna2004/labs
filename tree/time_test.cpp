#include <iostream>
#include <chrono>
#include "treenode.h"
#include "tree.h"


using namespace std;
using namespace std::chrono;


int get_sqr(int num)
{
	return num*num;
}


int get_sum(int a, int b)
{
	return a+b;
}


int balance_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	auto start = high_resolution_clock::now();
	BinaryTree<int>* balanced = tree.balance();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int tree_to_string_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	string res = "";
	auto start = high_resolution_clock::now();
	tree.tree_to_string(tree.get_root(), res, "NLR");
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int get_subtree_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	int value = num_elements/2;
	auto start = high_resolution_clock::now();
	BinaryTree<int>* subtree = tree.get_subtree(value);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int search_subtree_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	int value = num_elements/2;
	auto start = high_resolution_clock::now();
	bool is_subtree = tree.search_subtree(value , "abc", "NLR");
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int insert_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	int value = num_elements + 2;
	auto start = high_resolution_clock::now();
	tree.insert(value);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	delete items;
	return duration.count();
}


int remove_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	int value = num_elements/2;
	auto start = high_resolution_clock::now();
	tree.remove(value);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	delete items;
	return duration.count();
}


int search_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	int value = num_elements/2;
	auto start = high_resolution_clock::now();
	TreeNode<int>* node = tree.search(tree.get_root(), value);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	delete items;
	return duration.count();
}


int map_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	auto start = high_resolution_clock::now();
	BinaryTree<int>* mapped = tree.map(get_sqr);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int reduce_time(int num_elements)
{
	int* items = new int[num_elements];
	for(int i = 0; i < num_elements; i++){
		items[i] = i;
	}
	BinaryTree<int> tree(items, num_elements);
	auto start = high_resolution_clock::now();
	int sum = tree.reduce(get_sum, 0, "NLR");
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	delete items;
	return duration.count();
}


int main()
{
	int num = 100;
	cout << "Insert(ns):\n";
	while(num <= 10000000){
		int time  = insert_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Remove(ns):\n";
	while(num <= 10000000){
		int time  = remove_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Search(ns):\n";
	while(num <= 10000000){
		int time  = search_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Tree to string(mcrs):\n";
	while(num <= 10000000){
		int time  = tree_to_string_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Get subtree(mcrs):\n";
	while(num <= 10000000){
		int time  = get_subtree_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Search subtree(mcrs):\n";
	while(num <= 10000000){
		int time  = search_subtree_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Map(mcrs):\n";
	while(num <= 10000000){
		int time  = map_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}

	num = 100;
	cout << "Reduce(mcrs):\n";
	while(num <= 10000000){
		int time  = reduce_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}
	num = 100;
	cout << "Balance(mcrs):\n";
	while(num <= 10000000){
		int time  = balance_time(num);
		cout << "Num elements: " << num << ", time: " << time << "\n";
		num *= 10;
	}
}