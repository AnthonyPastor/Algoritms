#include "List.h"
#include <cstddef>

template <class T>

class ListImplementation : public List<T>
{

private:
    class ListNode
    {
    public:
        T element;
        ListNode *next;
        ListNode(T element) : element(element), next(NULL) {}
        ListNode(T element, ListNode *aNext) : element(element), next(aNext) {}
    };

    class ListIterator : public Iterator<T>
    {
    private:
        ListNode *current;

    public:
        ListIterator(ListNode *current) : current(current) {}

        bool hasNext()
        {
            return current != NULL;
        }

        T next()
        {
            T element = current->element;
            current = current->next;
            return element;
        }
    };
    ListNode *head;
    ListNode *tail;
    int size;

public:
    ListImplementation() : head(NULL), size(0) {}

    void insertInTail(T element)
    {
        ListNode *newNode = new ListNode(element);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertInHead(T element){
        ListNode *newNode = new ListNode(element);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    T Head()
    {
        return this->head->element;
    }

    void insertAt(int index, T element)
    {
        if (index < 0 || index > size)
        {
            throw "Index out of bounds";
        }
        ListNode *newNode = new ListNode(element);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (index == size)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            ListNode *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void remove(T elementToDelete)
    {
        if (isEmpty())
        {
            throw "List is empty";
        }
        ListNode *current = head;
        ListNode *previus = NULL;

        if (current != NULL && current->element == elementToDelete)
        {
            head = current->next;
            delete current;
            size--;
        }
        else
        {
            while (current != NULL && current->element != elementToDelete)
            {
                previus = current;
                current = current->next;
            }

            if (current == NULL)
                throw "Element not found";

            previus->next = current->next;
            delete current;
            size--;
        };
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw "Index out of bounds";
        }
        ListNode *current = head;
        ListNode *previus = NULL;

        for (int i = 0; i < index; i++)
        {
            previus = current;
            current = current->next;
        }
        if (current == head)
        {
            head = current->next;
        }
        else
        {
            previus->next = current->next;
        }
        delete current;
        size--;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
        {
            throw "Index out of bounds";
        }
        ListNode *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->element;
    }

    int getSize()
    {
        return size;
    }

    Iterator<T> *getIterator()
    {
        return new ListIterator(this->head);
    }
};