//Node Template implementation



//Default Constructor--------------------------------------------
template <typename T>
Node<T>::Node(): next(nullptr){}

//Copy Constructor-----------------------------------------------
template <typename T>
Node<T>::Node(const T& src): data(src), next(nullptr){}

//Copy Constructor-----------------------------------------------
template <typename T>
Node<T>::Node(const Node<T>& src): data(src.data), next(nullptr){}

//Destructor-----------------------------------------------------
template <typename T>
Node<T>::~Node(){
    next = NULL;
}

//Get 'next' pointer---------------------------------------------
template <typename T>
Node<T>*& Node<T>::getNext(){
    return next;
}
template <typename T>
T& Node<T>::getData(){
    return data;
}
//Set 'next' pointer---------------------------------------------
template <typename T>
void Node<T>::setNext(Node<T>* newNext){
    next = newNext;
}

//Insertion------------------------------------------------------
template <typename T>
istream& operator>>(istream& in, Node<T>& src){
    in >> src.data;
    return in;
}

//Extraction-----------------------------------------------------
template <typename T>
ostream& operator<<(ostream& out, const Node<T>& src){
    out << src.data;
    return out;
}

//Assignment-----------------------------------------------------
template <typename T>
Node<T>& Node<T>::operator=(const T& src){
    data = src;
    return *this;
}
template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& src){
    data = src.data;
    return *this;
}
//Equal----------------------------------------------------------
template <typename T>
bool Node<T>::operator==(const T& cmp){
    return data = cmp;
}
template <typename T>
bool Node<T>::operator==(const Node<T>& cmp){
    return data == cmp.data;
}


