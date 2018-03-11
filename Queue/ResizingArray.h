#ifndef ResizingArray_H
#define ResizingArray_H

#include "Queuep.h"

template <class T>
class QueuepResizingArray: public Queuep<T>{
private:
	T *array;
	long capacity;
	int begin;
	void Resize(long);
public:
	QueuepResizingArray();
	virtual void Push(T const&);
	virtual T Pop();
	~QueuepResizingArray();
};

#include "ResizingArray.cpp"

#endif