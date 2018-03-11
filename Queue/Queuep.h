#ifndef QUEUE_PH
#define QUEUE_PH

template <class T>
class Queuep{
protected:
	long count;
public:
	Queuep();
	virtual void Push(T const&);
	virtual T Pop();
	long Count();
	//virtual bool Remove(long);
	//virtual bool Remove(T);
};

#include "Queuep.cpp"
 
#endif