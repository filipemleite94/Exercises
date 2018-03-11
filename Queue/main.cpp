#include "Queuep.h"
#include "ResizingArray.h"
#include <iostream>

using namespace std;
int main(){
	QueuepResizingArray<int> q;
	q.Push(0);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Push(6);
	q.Push(7);
	q.Push(8);
	q.Push(5);
	q.Push(6);
	q.Push(7);
	q.Push(8);
	q.Push(5);
	q.Push(6);
	q.Push(7);
	q.Push(8);
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	q.Push(7);
	q.Push(8);
	q.Push(5);
	q.Push(6);
	q.Push(7);
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	q.Push(8);
	q.Push(5);
	q.Push(6);
	q.Push(7);
	q.Push(8);
	cout<<q.Pop()<<endl;
	cout<<q.Pop()<<endl;
	q.Push(8);
	//cout<<q.Pop()<<" "<<q.Pop()<<endl;
	return 0;
}