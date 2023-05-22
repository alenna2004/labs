#include <iostream>
#include <ctime>
#include "seq.h"
#include "listseq.h"
#include "arseq.h"
#include "matrix.h"


using std::cout;


int count_neighbours(int row_ind, int col_ind, Matrix<int>* matrix)
{
	int res = 0;
	Sequence<int>* row_i = matrix->get_row(row_ind);
	Sequence<int>* row_prev = matrix->get_row(row_ind-1);
	Sequence<int>* row_next = matrix->get_row(row_ind+1);
	res += (*row_i)[col_ind-1];
	res += (*row_i)[col_ind+1];
	res += (*row_prev)[col_ind];
	res += (*row_next)[col_ind];
	return res;
}


int main(void)
{
	srand(time(0));
	int a = rand() % 2;
	int b = rand() %2;
	//cout << a << "\n";
	//cout << "\033[32;42m a\033[0m\n";
	int* array = new int[5400];
	for(int i = 0; i< 5400; i++){
		array[i] = 0;
	}
	ArraySequence<int>* arrayseq = new ArraySequence<int>(array, 5400);
	Matrix<int> matrix(arrayseq, 60, 90);
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		int* new_row = new int[90];
		new_row[0] = 0;
		new_row[1] = 0;
		new_row[89] = 0;
		for(int j = 2; j < 89; j++){
			int el = rand() % 3;
			new_row[j] = (el % 2);
		}
		ArraySequence<int>* seq_row = new ArraySequence<int>(new_row, 90);
		matrix.set_row(seq_row, i);
	}
	//matrix.print_matrix();
	cout <<"\n";
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if((check == 0 || check == 2) && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
			if((check == 4 || check == 2) && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if((check == 0 || check == 2) && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
			if((check == 4 || check == 2) && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 0 && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
			if(check == 4 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 1 && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
			if(check == 3 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 0 && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
			if(check == 4 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 3 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 4 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 88; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 1 && (*row)[j] == 1){
				int check_2 = count_neighbours(i+1, j, &matrix);
				int check_3 = count_neighbours(i, j+1, &matrix);
				if(check_2 == 1 && (*row)[j] == 1){
					matrix.set_element(i, j, 0);
					matrix.set_element(i+1, j, 0);
				}
				if(check_3 == 1 && (*row)[j] == 1){
					matrix.set_element(i, j, 0);
					matrix.set_element(i, j+1, 0);
				}
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 88; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 3 && (*row)[j] == 0){
				int check_2 = count_neighbours(i+1, j, &matrix);
				int check_3 = count_neighbours(i, j+1, &matrix);
				if(check_2 == 3 && (*row)[j] == 0){
					matrix.set_element(i, j, 1);
					matrix.set_element(i+1, j, 1);
				}
				if(check_3 == 3 && (*row)[j] == 0){
					matrix.set_element(i, j, 1);
					matrix.set_element(i, j+1, 1);
				}
			}
		}
	}

	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 88; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 1){
				int check_2 = count_neighbours(i+1, j, &matrix);
				int check_3 = count_neighbours(i, j+1, &matrix);
				int check_4 = count_neighbours(i+1, j+1, &matrix);
				if(check_2 == 2 && check_3 == 2 && check_4 ==2){
					matrix.set_element(i, j, 0);
					matrix.set_element(i+1, j, 0);
					matrix.set_element(i, j+1, 0);
					matrix.set_element(i+1, j+1, 0);
				}
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 88; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				int check_2 = count_neighbours(i+1, j, &matrix);
				int check_3 = count_neighbours(i, j+1, &matrix);
				int check_4 = count_neighbours(i+1, j+1, &matrix);
				if(check_2 == 2 && check_3 == 2 && check_4 == 2){
					matrix.set_element(i, j, 1);
					matrix.set_element(i+1, j, 1);
					matrix.set_element(i, j+1, 1);
					matrix.set_element(i+1, j+1, 1);
				}
			}
		}
	}
	/*for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				matrix.set_element(i,j,1);
			}
		}
	}*/
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 0 && (*row)[j] == 1){
				matrix.set_element(i, j, 0);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 4 && (*row)[j] == 0){
				matrix.set_element(i, j, 1);
			}
		}
	}
	/*for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				matrix.set_element(i,j,1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				matrix.set_element(i,j,1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				matrix.set_element(i,j,1);
			}
		}
	}
	for(int i = 2 ; i < 58; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 2; j < 89; j++){
			int check = count_neighbours(i, j, &matrix);
			if(check == 2 && (*row)[j] == 0){
				matrix.set_element(i,j,1);
			}
		}
	}*/
	//matrix.print_matrix();
	for(int i = 1 ; i < 60; i++){
		Sequence<int>* row = matrix.get_row(i);
		for(int j = 1; j < 90; j++){
			int element = (*row)[j];
			if(element == 1){
				cout << "\033[32;42m .\033[0m";
			}
			if(element == 0){
				cout << "\033[34;44m .\033[0m";
			}
		}
		cout << "\n";
	}
}