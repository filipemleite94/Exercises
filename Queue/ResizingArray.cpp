#include "Queuep.h"
#include "ResizingArray.h"
#include <utility>
#include <iostream>

using namespace std;

template <class T>
QueuepResizingArray<T>::QueuepResizingArray():Queuep<T>(), capacity(1), begin(0), array(new T[1]){}

template <class T>
void QueuepResizingArray<T>::Resize(long capacity){
	T* newArr = new T[capacity];
	cout<<"Resizing ";
	for(int i = 0; i< Queuep<T>::count; i++){
		cout<<array[(begin+i)%(this->capacity)]<<" ";
		newArr[i] = array[(begin+i)%(this->capacity)];
	}
	cout<<"::"<<capacity<<endl;
	begin = 0;
	this->capacity = capacity;
	swap(array, newArr);
	delete[] newArr;
}

template <class T>
void QueuepResizingArray<T>::Push(T const &thing){
	if(Queuep<T>::count==capacity){
		Resize(2*capacity);
	}
	int i{(begin + Queuep<T>::count)%capacity};
	array[i] = thing;
	Queuep<T>::count++;
}

template <class T>
T QueuepResizingArray<T>::Pop(){
	T val(array[begin]);
	Queuep<T>::count--;
	if(Queuep<T>::count<capacity/4)
		Resize(capacity/2);
	begin=(begin+1)%capacity;
	return val;
}

template <class T>
QueuepResizingArray<T>::~QueuepResizingArray(){delete[] array;}