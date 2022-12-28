//Node Template header class
#ifndef Node_H
#define Node_H

#include <iostream>
using std::istream;
using std::ostream;

template <typename T>
class Node;
template <typename T>
istream& operator>>(istream&, Node<T>&);
template <typename T>
ostream& operator<<(ostream&, const Node<T>&);

template <typename T>
class Node{
    public:
        Node();
        Node(const T&);
        Node(const Node<T>&);
        ~Node();
        Node<T>*& getNext();
        T& getData();
        void setNext(Node<T>*);

        //Insertion / Extraction
        friend istream& operator>> <>(istream&, Node<T>&);
        friend ostream& operator<< <>(ostream&, const Node<T>&);
        //Assignment
        Node<T>& operator=(const T&);
        Node<T>& operator=(const Node<T>&);
        //Equal
        bool operator==(const T&);
        bool operator==(const Node<T>&);
        //Not Equal
        bool operator!=(const T&);
        bool operator!=(const Node<T>&);
        //Greater than
        bool operator>(const T&);
        bool operator>(const Node<T>&);
        //Greater than or equal
        bool operator>=(const T&);
        bool operator>=(const Node<T>&);
        //Less than
        bool operator<(const T&);
        bool operator<(const Node<T>&);
        //Less than or equal
        bool operator<=(const T&);
        bool operator<=(const Node<T>&);
        //Plus
        Node<T> operator+(const T&);
        Node<T> operator+(const Node<T>&);
        //Plus equal
        Node<T>& operator+=(const T&);
        Node<T>& operator+=(const Node<T>&);
        //Minus
        Node<T> operator-(const T&);
        Node<T> operator-(const Node<T>&);
        //Minus equal
        Node<T>& operator-=(const T&);
        Node<T>& operator-=(const Node<T>&);
        //Multiple
        Node<T> operator*(const T&);
        Node<T> operator*(const Node<T>&);
        //Multiply equal
        Node<T>& operator*=(const T&);
        Node<T>& operator*=(const Node<T>&);
        //Divide
        Node<T> operator/(const T&);
        Node<T> operator/(const Node<T>&);
        //Divide equal
        Node<T>& operator/=(const T&);
        Node<T>& operator/=(const Node<T>&);

    private:
        T data;
        Node<T>* next;
        //Node<T>* prev;
};

#include "Node.tpp"
#endif
