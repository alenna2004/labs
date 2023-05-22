#include <stdexcept>
#include <iostream>
#include "seq.h"
#include "arseq.h"
#include "listseq.h"
#include "pair.h"
#include "zip.h"
#ifndef MATRIX_H
#define MATRIX_H


template<class T>
Pair<T, T> sum_elements(Pair<T,T> pair)
{
	T first = pair.get_first();
	T second = pair.get_second();
	Pair<T,T> new_pair(first + second, first + second);
	return new_pair;
}


template<class T>
Pair<T, T> mult_elements(Pair<T,T> pair)
{
	T first = pair.get_first();
	T second = pair.get_second();
	Pair<T,T> new_pair(first*second, first*second);
	return new_pair;
}


template <class T>
T count_abs(T num){
	if(num < 0){
		return (-1)*num;
	}
	return num;
}


template <class T>
T get_sum(T a, T b)
{
	return a+b;
}





template<class T>
class Matrix
{
private:
	Sequence<T>* data{0};
	int num_rows{0};
	int num_cols{0};
public:
	Matrix(){};
	Matrix(Sequence<T>* data_as_array, int n_rows,int n_cols);
	~Matrix();
	Matrix<T>* operator+(Matrix<T> &matrix);
	Sequence<T>* get_row(int index_row);
	void set_row(Sequence<T>* row, int index_row);
	void transpose();
	void print_matrix();
	Matrix<T>* operator*(Matrix<T> &matrix);
	Matrix<T>* operator*(T number);
	T count_norm();
	void swap_two_rows(int first_ind, int second_ind);
	void swap_two_cols(int first_ind, int second_ind);
	void mult_row_to_num(T num, int index);
	void mult_col_to_num(T num, int index);
	void add_multed_row_to_row(T num, int first_ind, int second_ind);
	void add_multed_col_to_col(T num, int first_ind, int second_ind);
	int get_num_rows();
	int get_num_cols();
	Sequence<T>* get_data();
	void set_element(int row_ind, int col_ind, T element);
};


template<class T>
Matrix<T>::Matrix(Sequence<T>* data_as_array, int n_rows,int n_cols)
{
	if(data_as_array->get_length() != n_rows*n_cols){
		throw std::invalid_argument("Invalid array size");
	}
	ArraySequence<T>* check_1 = dynamic_cast<ArraySequence<T>*>(data_as_array);
	LinkedListSequence<T>* check_2 = dynamic_cast<LinkedListSequence<T>*>(data_as_array);
	if(check_1){
		data = new ArraySequence<T>(*check_1);
	}
	else{
		data = new LinkedListSequence<T>(*check_2);
	}
	num_rows = n_rows;
	num_cols = n_cols;
}


template<class T>
Matrix<T>::~Matrix()
{
	delete [] data;
}


template<class T>
Matrix<T>* Matrix<T>::operator+(Matrix<T> &matrix)
{
	if(matrix.num_cols != num_cols || matrix.num_rows != num_rows){
		throw std::invalid_argument("Invalid matrix sizes");
	}
	Sequence<Pair<T,T>>* zipped = zip<Pair, Sequence, T, T>(matrix.data, data);
	zipped->map(sum_elements<T>);
	Pair<Sequence<T>*,Sequence<T>*> unzipped = unzip(zipped);
	Matrix<T>* matrix_sum = new Matrix<T>(unzipped.get_first(), num_rows, num_cols);
	return matrix_sum;
}


template <class T>
Sequence<T>* Matrix<T>::get_row(int index_row)
{
	if(index_row >= num_rows || index_row < 0){
		throw std::out_of_range("Index out of range");
	}
 	Sequence<T>* row = data->get_subsequence(num_cols*index_row, num_cols*index_row + num_cols-1);
 	T* items = new T[num_cols];
 	for(int i = 0; i < num_cols; i++){
 		items[i] = (*row)[i];
 	}
 	ArraySequence<T>* ptr = new ArraySequence<T>(items, num_cols); 
	return ptr;
}


template <class T>
void Matrix<T>::set_row(Sequence<T>* row, int index_row)
{
	if(index_row > num_rows || index_row < 0){
		throw std::out_of_range("Index out of range");
	}
	int start_index = num_cols*index_row;
	for(int i = 0; i < num_cols; i++){
		(*data)[start_index + i] = (*row)[i];
	}
}

template <class T>
void Matrix<T>::transpose()
{
	T* items = new T[num_rows*num_cols];
	for(int i=0; i< num_rows*num_cols; i++){
		int row_ind = i/num_cols;
		int col_ind = i - row_ind*num_cols;
		T element = (*data)[row_ind*num_cols + col_ind];
		int new_ind = col_ind*num_rows + row_ind;
		items[new_ind] = element;
	}
	ArraySequence<T>* new_data = new ArraySequence<T>(items, num_rows*num_cols);
	data = new_data;
	int tmp = num_rows;
	num_rows = num_cols;
	num_cols = tmp;
}


template <class T>
void Matrix<T>::print_matrix()
{
	std::cout << "\n";
	for(int i = 0; i < num_rows; i++){
		for(int j = 0; j < num_cols; j++){
			if(num_cols != 1){
				std::cout << (*(this->get_row(i)))[j] << " ";
			}
			else{
				std::cout << (*data)[i] << " ";
			}
		}
		std::cout << "\n";
	}
}


template <class T>
Matrix<T>* Matrix<T>::operator*(Matrix<T> &matrix)
{
	if(num_cols != matrix.num_rows){
		throw std::invalid_argument("Invalid matrix sizes");
	}
	int res_n_cols = matrix.num_cols;
	int res_n_rows = num_rows;
	int res_len = res_n_cols*res_n_rows;
	T* items = new T[res_len];
	for(int i = 0; i < res_len; i++){
		int row_ind = i/res_n_cols;
		int col_ind = i - row_ind*res_n_cols;
		T res_element = 0;
		for(int j = 0; j < num_cols; j++){
			T element_1 = (*(this->get_row(row_ind)))[j];
			T element_2 = (*(matrix.get_row(j)))[i % res_n_cols];
			res_element += (element_1*element_2);
		}
		items[row_ind*res_n_cols + col_ind] = res_element;
	}
	ArraySequence<T>* new_data = new ArraySequence<T>(items, res_n_cols*res_n_rows);
	Matrix<T>* multed_matrix = new Matrix<T>(new_data, res_n_rows, res_n_cols);
	return multed_matrix;
}


template <class T>
Matrix<T>* Matrix<T>::operator*(T number)
{
	int len = num_cols*num_rows;
	T* nums = new T[len];
	for(int i = 0; i < len; i++){
		nums[i] = number;
	}
	ArraySequence<T>* coefs = new ArraySequence(nums, len);
	Sequence<Pair<T,T>>* zipped = zip<Pair, Sequence, T, T>(coefs, data);
	zipped->map(mult_elements<T>);
	Pair<Sequence<T>*,Sequence<T>*> unzipped = unzip(zipped);
	Matrix<T>* multed_matrix = new Matrix<T>(unzipped.get_first(), num_rows, num_cols);
	return multed_matrix;
}

template <class T>
T Matrix<T>::count_norm()
{
	T norm = 0;
	for (int i = 0; i < num_rows; i++){
		Sequence<T>* row = this->get_row(i);
		row->map(count_abs);
		T element  = row->reduce(get_sum, 0);
		if(element > norm){
			norm = element;
		}
	}
	return norm;
}

template <class T>
void Matrix<T>::swap_two_rows(int first_ind, int second_ind)
{
	if(first_ind > num_rows || second_ind > num_rows || first_ind < 0 || second_ind < 0){
		throw std::out_of_range("Index out of range");
	}
	Sequence<T>* row_1 = this->get_row(first_ind);
	Sequence<T>* row_2 = this->get_row(second_ind);
	this->set_row(row_2, first_ind);
	this->set_row(row_1, second_ind);
}


template <class T>
void Matrix<T>::swap_two_cols(int first_ind, int second_ind)
{
	this->transpose();
	this->swap_two_rows(first_ind, second_ind);
	this->transpose();
}


template <class T>
void Matrix<T>::mult_row_to_num(T num, int index)
{
	if(index > num_rows || index < 0){
		throw std::out_of_range("Index out of range");
	}
	int len = num_cols;
	T* nums = new T[len];
	for(int i = 0; i < len; i++){
		nums[i] = num;
	}
	ArraySequence<T>* coefs = new ArraySequence(nums, len);
	Sequence<T>* row = this->get_row(index);
	Sequence<Pair<T,T>>* zipped = zip<Pair, Sequence, T, T>(coefs, row);
	zipped->map(mult_elements<T>);
	Pair<Sequence<T>*,Sequence<T>*> unzipped = unzip(zipped);
	this->set_row(unzipped.get_first(), index);
}


template <class T>
void Matrix<T>::mult_col_to_num(T num, int index)
{
	this->transpose();
	this->mult_row_to_num(num, index);
	this->transpose();
}


template <class T>
void Matrix<T>::add_multed_row_to_row(T num, int first_ind, int second_ind)
{
	if(first_ind > num_rows || second_ind > num_rows || first_ind < 0 || second_ind < 0){
		throw std::out_of_range("Index out of range");
	}	
	int len = num_cols;
	T* nums = new T[len];
	for(int i = 0; i < len; i++){
		nums[i] = num;
	}
	ArraySequence<T>* coefs = new ArraySequence(nums, len);
	Sequence<T>* row_1 = this->get_row(first_ind);
	Sequence<T>* row_2 = this->get_row(second_ind);
	Sequence<Pair<T,T>>* zipped_1 = zip<Pair, Sequence, T, T>(coefs, row_1);
	zipped_1->map(mult_elements<T>);
	Pair<Sequence<T>*,Sequence<T>*> unzipped_1 = unzip(zipped_1);
	Sequence<Pair<T,T>>* zipped_2 = zip<Pair, Sequence, T, T>(unzipped_1.get_first(), row_2);
	zipped_2->map(sum_elements<T>);
	Pair<Sequence<T>*,Sequence<T>*> unzipped_2 = unzip(zipped_2);
	this->set_row(unzipped_2.get_first(), second_ind);
}


template <class T>
void Matrix<T>::add_multed_col_to_col(T num, int first_ind, int second_ind)
{
	this->transpose();
	this->add_multed_row_to_row(num, first_ind, second_ind);
	this->transpose();
}

template <class T>
int Matrix<T>::get_num_rows()
{
	return num_rows;
}


template <class T>
int Matrix<T>::get_num_cols()
{
	return num_cols;
}


template <class T>
Sequence<T>* Matrix<T>::get_data()
{
	return data;
}

template <class T>
void Matrix<T>::set_element(int row_ind, int col_ind, T element){
	if(row_ind > num_rows || col_ind > num_cols || row_ind < 0 || col_ind < 0){
		throw std::out_of_range("Index out of range");
	}
	(*data)[row_ind*num_cols + col_ind] = element;
}


#endif