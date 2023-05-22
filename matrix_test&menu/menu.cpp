#include <iostream>
#include <complex>
#include "seq.h"
#include "listseq.h"
#include "arseq.h"
#include "matrix.h"


using std::cout;
using std::cin;
using std::endl;


const char* HELLO_PART = """Welcome to our programm which provides access to sequence class.\n\
You can work with arrays or linked lists.\n All avaliable functions are shown in our menu.\n\
The sequences created with options 1 and 2 will be added to array and all of them\n\
will have their own number starting from 1 (the second created sequence will have number 2 and so on).\n\
Please, be a good user and don't try to do anything unexpected or not permited.\n""";


void print_base_options()
{
	cout << "Choose what to do and enter the appropriate number:\n";
	cout << "1. Create new Matrix\n";
	cout << "2. Transpose matrix\n";
	cout << "3. Sum two matrixes\n";
	cout << "4. Get number of rows\n";
	cout << "5. Get number of columns\n";
	cout << "6. Multiplicate to number\n";
	cout << "7. Multiplicate to matrix\n";
	cout << "8. Swap two rows\n";
	cout << "9. Swap two columns\n";
	cout << "10. Multiplicate row to number\n";
	cout << "11. Multiplicate column to number\n";
	cout << "12. Add multiplicated row to another row\n";
	cout << "13. Add multiplicated column to another column\n";
	cout << "14. Print matrix\n";
	cout << "15. Quit\n";

}


template<typename T>
void create_and_print_menu()
{
	system("clear");
	cout << HELLO_PART;
	ArraySequence<Matrix<T>*>* matrixes = new ArraySequence<Matrix<T>*>;
	int choice;
	do {
		print_base_options();
		cin >> choice;
		while(cin.fail()){
			cout << "Wrong value. Try again\n";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
		switch(choice) {
			case 1:{
				system("clear");
				int num_rows = 0;
				int num_cols = 0;
				cout << "Enter number of rows\n";
				cin >> num_rows;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num_rows;
				}
				cout << "Enter number of columns\n";
				cin >> num_cols;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num_cols;
				}
				int len = num_rows*num_cols;
				T* items = new T[len];
				for (int i = 0; i < len; i++){
					int row_ind = i/num_cols;
					int col_ind = i - row_ind*num_cols;
					cout << "Element at place " << row_ind << " " << col_ind << "\n";
					cin >> items[i];
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> items[i];
					}
				}
				ArraySequence<T>* array = new ArraySequence<T>(items, len);
				Matrix<T>* new_matrix = new Matrix<T>(array, num_rows, num_cols);
				matrixes->append(new_matrix);
				break;
			}
			case 2:{
				system("clear");
				int num;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					(*matrixes)[num-1]->transpose();
					cout << "Matrix was transposed successfully\n";
				}
				break;
			}
			case 3:{
				system("clear");
				int num1;
				int num2;
				cout << "Enter number of first matrix\n";
				cin >> num1;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num1;
				}
				if(num1 > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter number of second sequence\n";
					cin >> num2;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> num2;
					}
					if(num2 > matrixes->get_length()){
						cout << "OOPS! We don't have a matrix with this number.";
						cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
					}
					else{
						Matrix<T>* sum = (*(*matrixes)[num1 - 1]) + (*(*matrixes)[num2 - 1]);
						cout << "Result is \n";
						sum->print_matrix();
						matrixes->append(sum);
						cout << "The result was added to array of matrixes\n";
					}
				}
				break;
			}
			case 4:{
				system("clear");
				int num;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					int num_rows = (*matrixes)[num-1]->get_num_rows();
					cout << "Number of rows is " << num_rows <<"\n";
				}
				break;
			}
			case 5:{
				system("clear");
				int num;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					int num_cols = (*matrixes)[num-1]->get_num_cols();
					cout << "Number of columns is " << num_cols <<"\n";
				}
				break;
			}
			case 6:{
				system("clear");
				int num;
				T number;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter number to multiplicate\n";
					cin >> number;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> number;
					}
					Matrix<T>* multed = (*(*matrixes)[num-1])*number;
					cout << "Result is \n";
					multed->print_matrix();
					matrixes->append(multed);
					cout << "The result was added to array of matrixes\n";
				}
				break;
			}
			case 7:{
				system("clear");
				int num1;
				int num2;
				cout << "Enter number of first matrix\n";
				cin >> num1;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num1;
				}
				if(num1 > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter number of second matrix\n";
					cin >> num2;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> num2;
					}
					if(num2 > matrixes->get_length()){
						cout << "OOPS! We don't have a matrix with this number.";
						cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
					}
					else{
						Matrix<T>* mult = (*(*matrixes)[num1 - 1])*(*(*matrixes)[num2 - 1]);
						cout << "Result is \n";
						mult->print_matrix();
						matrixes->append(mult);
						cout << "The result was added to array of matrixes\n";
					}
				}
				break;
			}
			case 8:{
				system("clear");
				int num;
				int first_ind;
				int second_ind;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of a row\n";
					cin >> first_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> first_ind;
					}
					cout << "Enter index of another row\n";
					cin >> second_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> second_ind;
					}
					(*matrixes)[num-1]->swap_two_rows(first_ind, second_ind);
					cout << "Rows were swaped successfully\n";
				}
				break;
			}
			case 9:{
				system("clear");
				int num;
				int first_ind;
				int second_ind;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of a column\n";
					cin >> first_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> first_ind;
					}
					cout << "Enter index of another column\n";
					cin >> second_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> second_ind;
					}
					(*matrixes)[num-1]->swap_two_cols(first_ind, second_ind);
					cout << "Columns were swaped successfully\n";
				}
				break;
			}
			case 10:{
				system("clear");
				int num;
				int ind;
				T number;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of a row\n";
					cin >> ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> ind;
					}
					cout << "Enter number to multiplicate\n";
					cin >> number;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> number;
					}
					(*matrixes)[num-1]->mult_row_to_num(number, ind);
					cout << "Row was multiplicated successfully\n";
				}
				break;
			}
			case 11:{
				system("clear");
				int num;
				int ind;
				T number;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of a column\n";
					cin >> ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> ind;
					}
					cout << "Enter number to multiplicate\n";
					cin >> number;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> number;
					}
					(*matrixes)[num-1]->mult_col_to_num(number, ind);
					cout << "Column was multiplicated successfully\n";
				}
				break;
			}
			case 12:{
				system("clear");
				int num;
				int first_ind;
				int second_ind;
				T number;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of the row that we will multiplicate to number\n";
					cin >> first_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> first_ind;
					}
					cout << "Enter index of the row to that we will add\n";
					cin >> second_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> second_ind;
					}
					cout << "Enter number to multiplicate\n";
					cin >> number;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> number;
					}
					(*matrixes)[num-1]->add_multed_row_to_row(number, first_ind, second_ind);
					cout << "It was done successfully\n";
				}
				break;
			}
			case 13:{
				system("clear");
				int num;
				int first_ind;
				int second_ind;
				T number;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					cout << "Enter index of of the column that we will multiplicate to number\n";
					cin >> first_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> first_ind;
					}
					cout << "Enter index of the column to that we will add\n";
					cin >> second_ind;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> second_ind;
					}
					cout << "Enter number to multiplicate\n";
					cin >> number;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> number;
					}
					(*matrixes)[num-1]->add_multed_col_to_col(number, first_ind, second_ind);
					cout << "It was done successfully\n";
				}
				break;
			}
			case 14:{
				system("clear");
	        	int num;
				cout << "Enter number of matrix\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > matrixes->get_length()){
					cout << "OOPS! We don't have a matrix with this number.";
					cout <<" Number must be poitive and less than " << matrixes->get_length() <<"\n";
				}
				else{
					(*matrixes)[num-1]->print_matrix();
				}
				break;
			}
			case 15:{
				break;
			}
			default:
			int new_choice;
			cout << "Please choose an integer between 1 and 15\n";
			cin >> new_choice;
			while(cin.fail()){
				cout << "Wrong value. Try again\n";
				cin.clear();
				cin.ignore();
				cin >> new_choice;
			}
			choice = new_choice;
			break;
		}
	}while (choice != 15);
}


int main()
{
	int var = 0;
	system("clear");
	cout << "Choose variable type for work\n";
	cout << "1. Integer\n";
	cout << "2. Double\n";
	cout << "3. Complex\n";
	cin >> var;
	if(var  == 1){
		create_and_print_menu<int>();
	}
	else if(var == 2){
		create_and_print_menu<double>();
	}
	else if(var == 3){
		create_and_print_menu<std::complex<double>>();
	}
	else{
		cout << "You entered bad value. The programm is over. Try again\n";
	}
}