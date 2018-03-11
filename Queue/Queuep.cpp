#include <utility>
#include "Queuep.h"

template <class T>
Queuep<T>::Queuep():count(0){}
template <class T>
void Queuep<T>::Push(T const&){count++;}
template <class T>
T Queuep<T>::Pop(){count--;}
template <class T>
long  Queuep<T>::Count(){return count;}
