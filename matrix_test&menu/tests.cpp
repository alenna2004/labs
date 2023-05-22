#include <iostream>
#include <cassert>
#include <complex>
#include "matrix.h"
#include "seq.h"
#include "listseq.h"
#include "arseq.h"
#include "pair.h"
#include "zip.h"




using std::cout;
using std::cin;
using std::endl;


ArraySequence<Matrix<int>*> create_basic_int_example_matrixes()
{
	int* arr0  = new int[6];
	arr0[0] = 9;
	arr0[1] = 1;
	arr0[2] = 8;
	arr0[3] = 1;
	arr0[4] = 2;
	arr0[5] = 6;
	int* arr1 = new int[6];
	arr1[0] = 1;
	arr1[1] = 8;
	arr1[2] = 4;
	arr1[3] = 3;
	arr1[4] = 5;
	arr1[5] = 7;
	int* arr2 = new int[12];
	arr2[0] = 2;
	arr2[1] = 2;
	arr2[2] = 1;
	arr2[3] = 0;
	arr2[4] = 3;
	arr2[5] = 2;
	arr2[6] = 1;
	arr2[7] = 0;
	arr2[8] = 2;
	arr2[9] = 1;
	arr2[10] = 3;
	arr2[11] = 1;
	int* arr3 = new int[3];
	arr3[0] = 1;
	arr3[1] = 2;
	arr3[2] = 5;
	int* arr4 = new int[3];
	arr4[0] = 1;
	arr4[1] = 1;
	arr4[2] = 1;
	ArraySequence<int>* seq_0 = new ArraySequence<int>(arr0, 6);
	ArraySequence<int>* seq_1 = new ArraySequence<int>(arr1, 6);
	ArraySequence<int>* seq_2 = new ArraySequence<int>(arr2, 12);
	ArraySequence<int>* seq_3 = new ArraySequence<int>(arr3, 3);
	ArraySequence<int>* seq_4 = new ArraySequence<int>(arr4, 3);
	Matrix<int>* matrix_1 = new Matrix<int>(seq_0, 2, 3);
	Matrix<int>* matrix_2 = new Matrix<int>(seq_1, 2, 3);
	Matrix<int>* matrix_3 = new Matrix<int>(seq_2, 3, 4);
	Matrix<int>* matrix_4 = new Matrix<int>(seq_3, 1,3);
	Matrix<int>* matrix_5 = new Matrix<int>(seq_4, 1,3);
	Matrix<int>** array = new Matrix<int>*[5];
	array[0] = matrix_1;
	array[1] = matrix_2;
	array[2] = matrix_3;
	array[3] = matrix_4;
	array[4] = matrix_5;
	ArraySequence<Matrix<int>*> matrixes_array(array, 5);
	return matrixes_array;
}


ArraySequence<ArraySequence<int>*> array_of_int_answers()
{
	int* sum_m = new int[6];
	sum_m[0] = 10;
	sum_m[1] = 9;
	sum_m[2] = 12;
	sum_m[3] = 4;
	sum_m[4] = 7;
	sum_m[5] = 13;
	int* mult_m_m = new int[8];
	mult_m_m[0] = 37;
	mult_m_m[1] = 28;
	mult_m_m[2] = 34;
	mult_m_m[3] = 8;
	mult_m_m[4] = 20;
	mult_m_m[5] = 12;
	mult_m_m[6] = 21;
	mult_m_m[7] = 6;
	int* mult_m_n = new int[6];
	mult_m_n[0] = 18; 
	mult_m_n[1] = 2;
	mult_m_n[2] = 16;
	mult_m_n[3] = 2;
	mult_m_n[4] = 4;
	mult_m_n[5] = 12;
	int* sum_1d = new int[3];
	sum_1d[0] = 2; 
	sum_1d[1] = 3;
	sum_1d[2] = 6;
	int* mult_1d_to_m = new int[4];
	mult_1d_to_m[0] = 18; 
	mult_1d_to_m[1] = 11;
	mult_1d_to_m[2] = 18;
	mult_1d_to_m[3] = 5;
	int* transpose_m = new int[6];
	transpose_m[0] = 9;
	transpose_m[1] = 1;
	transpose_m[2] = 1;
	transpose_m[3] = 2;
	transpose_m[4] = 8;
	transpose_m[5] = 6;
	int* transpose_1d = new int[3];
	transpose_1d[0] = 1; 
	transpose_1d[1] = 2;
	transpose_1d[2] = 5;
	int* swap = new int[6];
	swap[0] = 12;
	swap[1] = 9;
	swap[2] = 10;
	swap[3] = 13;
	swap[4] = 7;
	swap[5] = 4;
	int* mult_row = new int[6];
	mult_row[0] = 36;
	mult_row[1] = 27;
	mult_row[2] = 30;
	mult_row[3] = 13;
	mult_row[4] = 7;
	mult_row[5] = 4;
	int* add = new int[6];
	add[0] = 36;
	add[1] = 27;
	add[2] = 84;
	add[3] = 13;
	add[4] = 7;
	add[5] = 18;
	ArraySequence<int>* seq_0 = new ArraySequence<int>(sum_m, 6);
	ArraySequence<int>* seq_1 = new ArraySequence<int>(mult_m_m, 8);
	ArraySequence<int>* seq_2 = new ArraySequence<int>(mult_m_n, 6);
	ArraySequence<int>* seq_3 = new ArraySequence<int>(sum_1d, 3);
	ArraySequence<int>* seq_4 = new ArraySequence<int>(mult_1d_to_m, 4);
	ArraySequence<int>* seq_5 = new ArraySequence<int>(transpose_m, 6);
	ArraySequence<int>* seq_6 = new ArraySequence<int>(transpose_1d, 3);
	ArraySequence<int>* seq_7 = new ArraySequence<int>(swap, 6);
	ArraySequence<int>* seq_8 = new ArraySequence<int>(mult_row, 6);
	ArraySequence<int>* seq_9 = new ArraySequence<int>(add, 6);
	ArraySequence<int>** array = new ArraySequence<int>*[10];
	array[0] = seq_0;
	array[1] = seq_1;
	array[2] = seq_2;
	array[3] = seq_3;
	array[4] = seq_4;
	array[5] = seq_5;
	array[6] = seq_6;
	array[7] = seq_7;
	array[8] = seq_8;
	array[9] = seq_9;
	ArraySequence<ArraySequence<int>*> res_array(array, 10);
	return res_array;
}


template<typename T>
void test_sum(ArraySequence<Matrix<T>*> matrixes_array, ArraySequence<ArraySequence<T>*> answers_array)
{
	Matrix<T>* m1 =(*(matrixes_array[0])) + (*(matrixes_array[1]));
	assert(*(m1->get_data()) == (*(answers_array[0])));
	cout << "Test sum of matrixes: OK\n";
	Matrix<T>* m4 =  (*(matrixes_array[3])) + (*(matrixes_array[4]));
	assert(*(m4->get_data()) == (*(answers_array[3])));
	cout << "Test sum of matrixes with 1 row: OK\n";
}


template<typename T>
void test_mult(ArraySequence<Matrix<T>*> matrixes_array, ArraySequence<ArraySequence<T>*> answers_array, T num)
{
	Matrix<T>* m2 = (*(matrixes_array[0]))*(*(matrixes_array[2]));
	assert(*(m2->get_data()) == (*(answers_array[1])));
	cout << "Test mult of two matrixes: OK\n";
	Matrix<T>* m3 = (*(matrixes_array[0]))*num;
	assert(*(m3->get_data()) == (*(answers_array[2])));
	cout << "Test mult matrix to num: OK\n";
	Matrix<T>* m5 = (*(matrixes_array[3]))*(*(matrixes_array[2]));
	assert(*(m5->get_data()) == (*(answers_array[4])));
	cout << "Test mult of matrix and row: OK\n";
}

template<typename T>
void test_transpose(ArraySequence<Matrix<T>*> matrixes_array, ArraySequence<ArraySequence<T>*> answers_array)
{
	matrixes_array[0]->transpose();
	assert(*(matrixes_array[0]->get_data()) == (*(answers_array[5])));
	cout << "Test transpose matrix: OK\n";
	matrixes_array[3]->transpose();
	assert(*(matrixes_array[3]->get_data()) == (*(answers_array[6])));
	cout << "Test transpose matrix with 1 row: OK\n";
}

template<typename T>
void test_elemental_operations(Matrix<T>* m1, ArraySequence<ArraySequence<T>*> answers_array)
{
	m1->swap_two_cols(0, 2);
	assert(*(m1->get_data()) == (*(answers_array[7])));
	cout << "Test swap two coumns of matrix: OK\n";
	m1->mult_row_to_num(3, 0);
	assert(*(m1->get_data()) == (*(answers_array[8])));
	cout << "Test mult row to num: OK\n";
	m1->add_multed_col_to_col(2, 1, 2);
	assert(*(m1->get_data()) == (*(answers_array[9])));
	cout << "Test add to column other column multed to num: OK\n";
}


template<typename T>
void test_matrix(ArraySequence<Matrix<T>*> matrixes_array, ArraySequence<ArraySequence<T>*> answers_array, T num)
{
	Matrix<T>* m1 =(*(matrixes_array[0])) + (*(matrixes_array[1]));
	test_sum<T>(matrixes_array, answers_array);
	test_mult<T>(matrixes_array, answers_array, num);
	test_transpose<T>(matrixes_array, answers_array);
	test_elemental_operations<T>(m1, answers_array);
}



int main()
{
	ArraySequence<Matrix<int>*> int_matrixes = create_basic_int_example_matrixes();
	ArraySequence<ArraySequence<int>*> int_answers = array_of_int_answers();
	test_matrix<int>(int_matrixes, int_answers, 2);
	return 0;
}