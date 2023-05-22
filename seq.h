#ifndef SEQ_H
#define SEQ_H
#include "pair.h"


template <class T> 
class Sequence 
{
public:
	virtual bool is_empty() const = 0;
	virtual T get_first() const = 0;
	virtual T get_last() const = 0;
	virtual T &operator[](int index) = 0;
	virtual Sequence<T>* get_subsequence(int start_index, int end_index) = 0;
	virtual int get_length() const = 0;
	virtual void append(T item) = 0;
	virtual void prepend(T item) = 0;
	virtual void insert(T item, int index) = 0;
	virtual Sequence <T>* concat(Sequence<T>* list) = 0;
	bool operator==(Sequence &right);
	bool operator!=(Sequence &right);
	void map(T (*func)(T));
	T reduce(T (*func)(T item_1, T item_2), T start_const);
	//Sequence<Pair>* zip(Sequence<T>* list_1, Sequence<T>* list_2); 
};

template <class T>
bool Sequence<T>::operator==(Sequence &right)
{
	if((*this).get_length() != right.get_length()){
		return false;
	}
	int len = right.get_length();
	for(int i = 0; i < len; i++){
		if((*this)[i] != right[i]){
			return false;
		}
	}
	return true;
}


template <class T>
bool Sequence<T>::operator!=(Sequence &right)
{
	return !(*this == right);
}


template <class T>
void Sequence<T>::map(T (*func)(T))
{
	for(int i = 0; i < this->get_length(); i++){
		(*this)[i] = func((*this)[i]);
	}
}


template <class T>
T Sequence<T>::reduce(T (*func)(T item_1, T item_2), T start_const)
{
	T current = start_const;
	for (int i = 0; i < this->get_length(); ++i){
		T new_element = func((*this)[i], current);
		current = new_element;
	}
	return current;
}


#endif