#include <iostream>
#include "seq.h"
#include "listseq.h"
#include "arseq.h"


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
	cout << "1. Create new Array\n";
	cout << "2. Create new Linked List\n";
	cout << "3. Get element by index\n";
	cout << "4. Get length\n";
	cout << "5. Get subsequence\n";
	cout << "6. Append element\n";
	cout << "7. Prepend element\n";
	cout << "8. Insert element\n";
	cout << "9. Concatinate two sequences\n";
	cout << "10. Check are all elements of two sequences are equal\n";
	cout << "11. Print sequence\n";
	cout << "12. Quit\n";

}


void print_ways_of_creation()
{
	cout << "Choose way of creating\n";
	cout << "1. Create empty\n";
	cout << "2. Create from array\n";
}


template<typename T>
void create_and_print_menu()
{
	system("clear");
	cout << HELLO_PART;
	ArraySequence<Sequence<T>*>* sequences= new ArraySequence<Sequence<T>*>;
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
				int opt;
				print_ways_of_creation();
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						ArraySequence<T>* new_array = new ArraySequence<T>;
						sequences->append(new_array);
						break;
					}
					case 2:{
						system("clear");
						int num = 0;
						cout << "Enter number of elements\n";
						cin >> num;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> num;
						}
						T* items = new T[num];
						for (int i = 0; i < num; i++){
							cout << "Element with index " << i << "\n";
							cin >> items[i];
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> items[i];
							}
						}
						ArraySequence<T>* new_array = new ArraySequence<T>(items, num);
						sequences->append(new_array);
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
	        case 2:{
	        	system("clear");
				int opt;
				print_ways_of_creation();
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						LinkedListSequence<T>* new_array = new LinkedListSequence<T>;
						sequences->append(new_array);
						break;
					}
					case 2:{
						system("clear");
						int num = 0;
						cout << "Enter number of elements\n";
						cin >> num;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> num;
						}
						T* items = new T[num];
						for (int i = 0; i < num; i++){
							cout << "Element with index " << i << "\n";
							cin >> items[i];
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> items[i];
							}
						}
						LinkedListSequence<T>* new_array = new LinkedListSequence<T>(items, num);
						sequences->append(new_array);
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
			case 3:{
				system("clear");
				int num;
				int index;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Enter index\n";
					cin >> index;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> index;
					}
					cout << "Result is " << (*(*sequences)[num-1])[index] << "\n";
				}
				break;
			}
			case 4:{
				system("clear");
				int num;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Result is " <<(*sequences)[num-1]->get_length() << "\n";
				}
				break;
			}
			case 5:{
				system("clear");
				int num;
				int start_index;
				int end_index;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Enter start index\n";
					cin >> start_index;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> start_index;
					}
					cout << "Enter end index\n";
					cin >> end_index;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> end_index;
					}
					Sequence<T>* subsequence = (*sequences)[num-1]->get_subsequence(start_index, end_index);
					cout << "Subsequence is: ";
					for (int i = 0; i < subsequence->get_length(); i++){
						cout << (*subsequence)[i] << " ";
					}
					cout << "\n";
				}
				break;
			}
			case 6:{
				system("clear");
				int num;
				T element;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Enter element\n";
					cin >> element;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> element;
					}
					(*sequences)[num-1]->append(element);
					cout << "Element was successfully appended\n";
				}
				break;
			}
			case 7:{
				system("clear");
				int num;
				T element;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Enter element\n";
					cin >> element;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> element;
					}
					(*sequences)[num-1]->prepend(element);
					cout << "Element was successfully prepended\n";
				}
				break;
			}
			case 8:{
				system("clear");
				int num;
				T element;
				int index;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Enter element\n";
					cin >> element;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> element;
					}
					cout << "Enter index\n";
					cin >> index;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> index;
					}
					(*sequences)[num-1]->insert(element, index);
					cout << "Element was successfully inserted\n";
				}
				break;
			}
			case 9:{
				system("clear");
				int num1;
				int num2;
				cout << "Enter number of first sequence\n";
				cin >> num1;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num1;
				}
				if(num1 > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
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
					if(num2 > sequences->get_length()){
						cout << "OOPS! We don't have a sequence with this number.";
						cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
					}
					else{
						Sequence<T>* concated = (*sequences)[num1-1]->concat((*sequences)[num2-1]);
						cout << "Concatinated sequence is: ";
						for (int i = 0; i < concated->get_length(); i++){
							cout << (*concated)[i] << " ";
						}
						cout << "\n";
					}
				}
				break;
			}
			case 10:{
				system("clear");
				int num1;
				int num2;
				cout << "Enter number of first sequence\n";
				cin >> num1;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num1;
				}
				if(num1 > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
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
					if(num2 > sequences->get_length()){
						cout << "OOPS! We don't have a sequence with this number.";
						cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
					}
					else{
						if((*((*sequences)[num1-1])) == (*((*sequences)[num2-1]))){
							cout << "Equal\n";
						}
						else{
							cout << "Unequal\n";
						}
					}
				}
				break;
			}
			case 11:{
				system("clear");
				int num;
				cout << "Enter number of sequence\n";
				cin >> num;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> num;
				}
				if(num > sequences->get_length()){
					cout << "OOPS! We don't have a sequence with this number.";
					cout <<" Number must be poitive and less than " << sequences->get_length() <<"\n";
				}
				else{
					cout << "Sequence is: ";
					for(int i = 0; i < (*sequences)[num-1]->get_length(); i++){
						cout << (*((*sequences)[num-1]))[i] << " ";
					}
					cout << "\n";
				}
				break;
			}
			case 12:{
				break;
			}
			default:
			int new_choice;
			cout << "Please choose an integer between 1 and 12\n";
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
	}while (choice != 12);
}


int main()
{
	int var = 0;
	system("clear");
	cout << "Choose variable type for work\n";
	cout << "1. Integer\n";
	cout << "2. Double\n";
	cout << "3. Char\n";
	cin >> var;
	if(var  == 1){
		create_and_print_menu<int>();
	}
	else if(var == 2){
		create_and_print_menu<double>();
	}
	else if(var == 3){
		create_and_print_menu<char>();
	}
	else{
		cout << "You entered bad value. The programm is over. Try again\n";
	}
	return 0;
}