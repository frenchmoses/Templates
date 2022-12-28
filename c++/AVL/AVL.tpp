//Austin Frenchmoses
//AVL Tree Template implementation

#include <math.h>
using namespace std;

//Default Constructor--------------------------------------------
template <typename T>
AVLTree<T>::AVLTree(){}
//Copy Constructor-----------------------------------------------
template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& src){
	copy(root,src.root);
}
//Destructor-----------------------------------------------------
template <typename T>
AVLTree<T>::~AVLTree(){}
//Extraction / Display-------------------------------------------
template <typename T>
ostream& operator<< (ostream& out, const AVLTree<T>& tree){
    if(!tree.root) out << "List is empty!";
    else tree.display(tree.root, out);
    return out;
}
template <typename T>
void AVLTree<T>::display(const nodePtr& root, ostream& out) const{
    if(!root) return;
    display(root->getLeft(), out);
    out << *root << " ";
    display(root->getRight(), out);
}
//Assignment-----------------------------------------------------
template <typename T>
AVLTree<T>::tree& AVLTree<T>::operator= (const tree& src){
	if(!src.root) return 0;
	else copy(src);
	return *this;
}
//Push-----------------------------------------------------------
template <typename T>
void AVLTree<T>::push(const T& src){
    push(root, src);
}
template <typename T>
void AVLTree<T>::push(nodePtr& root, const T& src){
    if(!root) root.reset(new bstNode<T>(src));
	else if(src >= *root) push(root->getRight(), src);
	else push(root->getLeft(), src);
	reBalance(root);    
}
//Pop------------------------------------------------------------
template <typename T>
int AVLTree<T>::pop(const T& find){
    if(!root) return 0;
    return pop(root, find);
}
template <typename T>
int AVLTree<T>::pop(nodePtr& root, const T& find){
    int success = 0;
	if(!root) return 0;
	else if(*root == find){
		if(!root->getLeft() && !root->getRight()) root.reset();
		else if(!root->getLeft()) root = move(root->getRight());
		else if(!root->getRight()) root = move(root->getLeft());
		else getSuccessor(root, root->getRight());
		return 1;
	}else if(find >= *root) success =  pop(root->getRight(), find);
	else success = pop(root->getLeft(), find);
	reBalance(root);
	return success;
}
//Copy-----------------------------------------------------------
template <typename T>
int AVLTree<T>::copy(nodePtr& dest, const nodePtr& src){
	if(!src) return 0;
	dest.reset(new bstNode<T>(*src));
	return copy(dest->getLeft(), src->getLeft()) + 
		copy(dest->getRight(), src->getRight()) + 1;
}
//Retrieve-------------------------------------------------------
template <typename T>
AVLTree<T>::nodePtr AVLTree<T>::retrieve(const T& find){
    if(!root) return nullptr;
    return retrieve(root, find);
}
template <typename T>
AVLTree<T>::nodePtr AVLTree<T>::retrieve(const nodePtr& root, const T& find){
	if(!root) return nullptr;
	if(*root == find) return root;
	else if(find >= *root) return retrieve(root->getRight(), find);
	else return retrieve(root->getLeft(), find);
}
//Get In-order Successor-----------------------------------------
template <typename T>
int AVLTree<T>::getSuccessor(nodePtr& root,nodePtr& IoS){
	if(!IoS->getLeft()){
		*root = *IoS;
		IoS = move(IoS->getRight());
		return 1;
	}
	return getSuccessor(root, IoS->getLeft());
}
//Height---------------------------------------------------------
template <typename T>
int AVLTree<T>::height() const{
    return height(root);
}
template <typename T>
int AVLTree<T>::height(const nodePtr& root) const{
    if(!root) return -1;
    return 1 + max(height(root->getLeft()),height(root->getRight()));
}
template <typename T>
int AVLTree<T>::height2(const nodePtr& root) const{
	int h = -1;
    if(root){
		int left = height2(root->getLeft());
		int right = height2(root->getRight());
		int maxHeight = max(left, right);
		return 1 + maxHeight;
	}
    return h;
}
//Count----------------------------------------------------------
template <typename T>
int AVLTree<T>::count() const{
	if(!root) return 0;
	return count(root);
}
template <typename T>
int AVLTree<T>::count(const nodePtr& root) const{
	if(!root) return 0;
	return count(root->getLeft()) + 
 	count(root->getRight()) + 1;
}
//Print Levels---------------------------------------------------
template <typename T>
void AVLTree<T>::printLevels() const{
    int levels = height(root);
    for(int i = 0; i < levels; i++){
        std::cout << "Level " << i << ": ";
        printLevels(root, i);
        std::cout << std::endl;
    }
}
template <typename T>
void AVLTree<T>::printLevels(const nodePtr& root, int lvl) const{
    if(!root) return;
	if(lvl == 0) std::cout << *root << " ";
	else if(lvl > 0){
		printLevels(root->getLeft(), lvl - 1);
		printLevels(root->getRight(), lvl - 1);
    }
}

//Re-balance-----------------------------------------------------
template <typename T>
void AVLTree<T>::reBalance(nodePtr& root){
	if(!root) return;
    int bf = balanceFactor(root);
    int bfLeft = balanceFactor(root->getLeft());
    int bfRight = balanceFactor(root->getRight());
    if(bf > 1){
        if(bfLeft > 0) root = move(leftLeft(root));
        else root = move(leftRight(root));
    }else if(bf < -1){
        if(bfRight > 0) root = move(rightLeft(root));
        else root = move(rightRight(root));
    }
}
//Balance Factor-------------------------------------------------
template <typename T>
int AVLTree<T>::balanceFactor(const nodePtr& root) const{
    return (!root) ? 0 : height(root->getLeft()) - height(root->getRight());
}
//Left Rotation--------------------------------------------------
template <typename T>
AVLTree<T>::nodePtr& AVLTree<T>::leftLeft(nodePtr& root){
    nodePtr temp = move(root->getLeft());
    root->setLeft(temp->getRight());
    temp->setRight(root);
    root = move(temp);
    return root;
}
//Left Right Rotation--------------------------------------------
template <typename T>
AVLTree<T>::nodePtr& AVLTree<T>::leftRight(nodePtr& root){
    nodePtr temp = move(root->getLeft());
    root->setLeft(rightRight(temp));
    return leftLeft(root);
}
//Right Rotation-------------------------------------------------
template <typename T>
AVLTree<T>::nodePtr& AVLTree<T>::rightRight(nodePtr& root){
    nodePtr temp = move(root->getRight());
    root->setRight(temp->getLeft());
    temp->setLeft(root);
    root = move(temp);
    return root;
}
//Right Left Rotation--------------------------------------------
template <typename T>
AVLTree<T>::nodePtr& AVLTree<T>::rightLeft(nodePtr& root){
    nodePtr temp = move(root->getRight());
    root->setRight(leftLeft(temp));
    return rightRight(root);
}

