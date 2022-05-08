#include "../helpers/Iterator.h"
template <class T>
class List
{
public:
    virtual void insertInTail(T element) = 0;
    virtual void insertInHead(T element) = 0;
    virtual void insertAt(int index, T element) = 0;
    virtual void remove(T element) = 0;
    virtual void removeAt(int index) = 0;
    virtual bool isEmpty() = 0;
    virtual T get(int index) = 0;
    virtual int getSize() = 0;
    virtual Iterator<T> *getIterator() = 0;
};