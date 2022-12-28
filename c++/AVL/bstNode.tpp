//Austin Frenchmoses
//BST Node Template implementation

//Default Constructor--------------------------------------------
template <typename T>
bstNode<T>::bstNode(){}

//Copy Constructor-----------------------------------------------
template <typename T>
bstNode<T>::bstNode(const T& src): data(src){}

//Copy Constructor-----------------------------------------------
template <typename T>
bstNode<T>::bstNode(const bstNode<T>& src): data(src.data){}

//Destructor-----------------------------------------------------
template <typename T>
bstNode<T>::~bstNode(){}

//Get Left Pointer-----------------------------------------------
template <typename T>
bstNode<T>::nodePtr& bstNode<T>::getLeft(){
    return left;
}
//Get Right Pointer----------------------------------------------
template <typename T>
bstNode<T>::nodePtr& bstNode<T>::getRight(){
    return right;
}
//Get Data-------------------------------------------------------
template <typename T>
T& bstNode<T>::getData(){
    return data;
}
//Set Left Pointer-----------------------------------------------
template <typename T>
void bstNode<T>::setLeft(nodePtr& newLeft){
    left = move(newLeft);
}

//Set Right pointer----------------------------------------------
template <typename T>
void bstNode<T>::setRight(nodePtr& newRight){
    right = move(newRight);
}

//Insertion------------------------------------------------------
template <typename T>
istream& operator>>(istream& in, bstNode<T>& src){
    in >> src.data;
    return in;
}

//Extraction-----------------------------------------------------
template <typename T>
ostream& operator<<(ostream& out, const bstNode<T>& src){
    out << src.data;
    return out;
}

//Assignment-----------------------------------------------------
template <typename T>
bstNode<T>& bstNode<T>::operator=(const T& src){
    data = src;
    return *this;
}
template <typename T>
bstNode<T>& bstNode<T>::operator=(const bstNode<T>& src){
	data = src.data;
    return *this;
}
//Equal----------------------------------------------------------
template <typename T>
bool bstNode<T>::operator==(const T& op2) const{
    return data == op2;
}
template <typename T>
bool bstNode<T>::operator==(const bstNode<T>& op2) const{
    return data == op2.data;
}
template <typename U>
bool operator==(const U& op1, const bstNode<U>& op2){
    return op1 == op2.data;
}

//Not Equal------------------------------------------------------
template <typename T>
bool bstNode<T>::operator!=(const T& op2) const{
    return data != op2;
}
template <typename T>
bool bstNode<T>::operator!=(const node& op2) const{
    return data != op2.data;
}
template <typename U>
bool operator!=(const U& op1, const bstNode<U>& op2){
    return op1 != op2.data;
}

//Greater Than--------------------------------------------------
template <typename T>
bool bstNode<T>::operator>(const T& op2) const{
    return data > op2;
}
template <typename T>
bool bstNode<T>::operator>(const node& op2) const{
    return data > op2.data;
}
template <typename U>
bool operator>(const U& op1, const bstNode<U>& op2){
    return op1 > op2.data;
}

//Greater Than or Equal------------------------------------------
template <typename T>
bool bstNode<T>::operator>=(const T& op2) const{
    return data >= op2;
}
template <typename T>
bool bstNode<T>::operator>=(const node& op2) const{
    return data >= op2.data;
}
template <typename U>
bool operator>=(const U& op1, const bstNode<U>& op2){
    return op1 >= op2.data;
}

//Less Than------------------------------------------------------
template <typename T>
bool bstNode<T>::operator<(const T& op2){
	return data < op2;
}
template <typename T>
bool bstNode<T>::operator<(const node& op2){
	return data < op2.data;
}
template <typename U>
bool operator<(const U& op1, const bstNode<U>& op2){
    return op1 < op2.data;
}

//Less Than or Equal---------------------------------------------
template <typename T>
bool bstNode<T>::operator<=(const T& op2){	
	return data <= op2;
}
template <typename T>
bool bstNode<T>::operator<=(const node& op2){
	return data <= op2.data;
}
template <typename U>
bool operator<=(const U& op1, const bstNode<U>& op2){
    return op1 <= op2.data;
}
//Plus-----------------------------------------------------------
template <typename T>
bstNode<T>::node bstNode<T>::operator+(const T& op2){	
	return bstNode<T>(data + op2);
}
template <typename T>
 bstNode<T>::node bstNode<T>::operator+(const node& op2){
	return bstNode<T>(data + op2.data);
}
template <typename U>
bstNode<U>::node operator+(const U& op1, const bstNode<U>& op2){
	return bstNode<U>(op1 + op2.data);
}

//Plus Equals----------------------------------------------------
template <typename T>
bstNode<T>::node& bstNode<T>::operator+=(const T& op2){	
	data += op2;
	return *this;
}
template <typename T>
 bstNode<T>::node& bstNode<T>::operator+=(const node& op2){
 	data += op2.data;
 	return *this;
}

//Minus----------------------------------------------------------
template <typename T>
bstNode<T>::node bstNode<T>::operator-(const T& op2){	
	return bstNode<T>(data - op2);
}
template <typename T>
 bstNode<T>::node bstNode<T>::operator-(const node& op2){
	return bstNode<T>(data - op2.data);
}
template <typename U>
bstNode<U>::node operator-(const U& op1, const bstNode<U>& op2){
	return bstNode<U>(op1 - op2.data);
}

//Minus Equals---------------------------------------------------
template <typename T>
bstNode<T>::node& bstNode<T>::operator-=(const T& op2){	
	data -= op2;
	return *this;
}
template <typename T>
 bstNode<T>::node& bstNode<T>::operator-=(const node& op2){
 	data -= op2.data;
 	return *this;
}

//Mulptiply------------------------------------------------------
template <typename T>
bstNode<T>::node bstNode<T>::operator*(const T& op2){	
	return bstNode<T>(data * op2);
}
template <typename T>
 bstNode<T>::node bstNode<T>::operator*(const node& op2){
	return bstNode<T>(data * op2.data);
}
template <typename U>
bstNode<U>::node operator*(const U& op1, const bstNode<U>& op2){
	return bstNode<U>(op1 * op2.data);
}

//Mulptiply Equals-----------------------------------------------
template <typename T>
bstNode<T>::node& bstNode<T>::operator*=(const T& op2){	
	data *= op2;
	return *this;
}
template <typename T>
 bstNode<T>::node& bstNode<T>::operator*=(const node& op2){
 	data *= op2.data;
 	return *this;
}

//Divide---------------------------------------------------------
template <typename T>
bstNode<T>::node bstNode<T>::operator/(const T& op2){	
	return bstNode<T>(data / op2);
}
template <typename T>
 bstNode<T>::node bstNode<T>::operator/(const node& op2){
	return bstNode<T>(data / op2.data);
}
template <typename U>
bstNode<U>::node operator/(const U& op1, const bstNode<U>& op2){
	return bstNode<U>(op1 / op2.data);
}

//Divide Equals--------------------------------------------------
template <typename T>
bstNode<T>::node& bstNode<T>::operator/=(const T& op2){	
	data /= op2;
	return *this;
}
template <typename T>
 bstNode<T>::node& bstNode<T>::operator/=(const node& op2){
 	data /= op2.data;
 	return *this;
}


