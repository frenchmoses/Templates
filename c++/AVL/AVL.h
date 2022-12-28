//Austin Frenchmoses
//AVL Tree Template Header File

#ifndef AVL_H
#define AVL_H

#include "bstNode.h"

template<typename T>
class AVLTree{
	public:
        typedef AVLTree<T> tree;
        typedef bstNode<T> node;
        typedef shared_ptr<node> nodePtr;
		AVLTree();
		AVLTree(const tree&);
        ~AVLTree();

		template<typename U>
        friend ostream& operator<< (ostream&, const AVLTree<U>&);
        tree& operator= (const tree&);

        void push(const T&);
        int pop(const T&);
        nodePtr retrieve(const T&);
        int height() const;
		int count() const;
        void printLevels() const;


    private:
        nodePtr root;

        void display(const nodePtr&, ostream&) const;
        void push(nodePtr&, const T&);
        int pop(nodePtr&, const T&);
		int copy(nodePtr&, const nodePtr&);
        nodePtr retrieve(const nodePtr&, const T&);
		int getSuccessor(nodePtr&,nodePtr&);
        int height(const nodePtr&) const;
		int height2(const nodePtr& root) const;
		int count(const nodePtr&) const;
        void printLevels(const nodePtr&, int) const;

        void reBalance(nodePtr&);
        int balanceFactor(const nodePtr&) const;
        nodePtr& leftLeft(nodePtr&);
        nodePtr& leftRight(nodePtr&);
        nodePtr& rightRight(nodePtr&);
        nodePtr& rightLeft(nodePtr&);
};

#include "AVL.tpp"
#endif
