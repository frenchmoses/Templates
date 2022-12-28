//Linear Linked List Template header class
#ifndef LLL_H
#define LLL_H

#include <iostream>
#include "Node.h"
using std::istream;
using std::ostream;

template <typename T>
class LLL;
template <typename T>
ostream& operator<<(ostream&, const LLL<T>&);

template <typename T>
class LLL{
    public:
        LLL();
        LLL(const LLL<T>&);
        ~LLL();
        int pushFront(const T&);
        int pushFront(const Node<T>&);
        int pushBack(const T&);
        int pushBack(const Node<T>&);
        T popFront();
        T popBack();
        T pop(const T&);
        T find(const T&);

        //Insertion / Extraction
        friend ostream& operator<< <>(ostream&, const LLL<T>&);
        //Assignment
        LLL<T>& operator=(const LLL<T>&);

    //private:
    public:
        Node<T>* head;

        void display(Node<T>*, ostream&) const;
        int pushBack(Node<T>*&, const Node<T>&);
        T popBack(Node<T>*&);
        T pop(Node<T>*&, const T&);
        T find(Node<T>*, const T&);
};

#include "LLL.tpp"
#endif
