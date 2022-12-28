//Austin Frenchmoses
//BST Node Template header class

#ifndef bstNode_H
#define bstNode_H

#include <memory>
#include <iostream>
using std::shared_ptr;
using std::istream;
using std::ostream;

template <typename T>
class bstNode{
    public:
        typedef bstNode<T> node;
        typedef shared_ptr<node> nodePtr;
        bstNode();
        bstNode(const T&);
        bstNode(const node&);
        ~bstNode();
        nodePtr& getLeft();
        nodePtr& getRight();
        T& getData();
        void setLeft(nodePtr&);
        void setRight(nodePtr&);

        //Insertion / Extraction
		template <typename U>
        friend istream& operator>> (istream&, bstNode<U>&);
		template <typename U>
        friend ostream& operator<< (ostream&, const bstNode<U>&);

        //Assignment
        node& operator=(const T&);
        node& operator=(const node&);

        //Equal
        bool operator==(const T&) const;
        bool operator==(const node&) const;
		template <typename U>
        friend bool operator==(const U&, const bstNode<U>&);

        //Not Equal
        bool operator!=(const T&) const;
        bool operator!=(const node&) const;
		template <typename U>
        friend bool operator!=(const U&, const bstNode<U>&);

        //Greater than
        bool operator>(const T&) const;
        bool operator>(const node&) const;
		template <typename U>
        friend bool operator>(const U&, const bstNode<U>&);

        //Greater than or equal
        bool operator>=(const T&) const;
        bool operator>=(const node&) const;
		template <typename U>
        friend bool operator>=(const U&, const bstNode<U>&);

        //Less than
        bool operator<(const T&);
        bool operator<(const node&);
		template <typename U>
        friend bool operator<=(const U&, const bstNode<U>&);

        //Less than or equal
        bool operator<=(const T&);
        bool operator<=(const node&);
		template <typename U>
        friend bool operator<=(const U&, const bstNode<U>&);
        
		//Plus
        node operator+(const T&);
        node operator+(const node&);
		template <typename U>
		friend bool operator+(const U&, const bstNode<U>&);

		//Plus equal
        node& operator+=(const T&);
        node& operator+=(const node&);
        
		//Minus
        node operator-(const T&);
        node operator-(const node&);
		template <typename U>
        friend bool operator-(const U&, const bstNode<U>&);
        
		//Minus equal
        node& operator-=(const T&);
        node& operator-=(const node&);

        //Multiple
        node operator*(const T&);
        node operator*(const node&);
		template <typename U>
        friend bool operator*(const U&, const bstNode<U>&);

        //Multiply equal
        node& operator*=(const T&);
        node& operator*=(const node&);
        
		//Divide
        node operator/(const T&);
        node operator/(const node&);
		template <typename U>
        friend bool operator/(const U&, const bstNode<U>&);
        
		//Divide equal
        node& operator/=(const T&);
        node& operator/=(const node&);

    private:
        T data;
        nodePtr left;
        nodePtr right;
};

#include "bstNode.tpp"
#endif
