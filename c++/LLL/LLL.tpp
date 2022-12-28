


template <typename T>
LLL<T>::LLL(): head(nullptr){}
template <typename T>
LLL<T>::LLL(const LLL<T>& src){
    //copy
}
template <typename T>
LLL<T>::~LLL(){
    Node<T>* curr = head;
    while(curr != NULL){
        head = curr;
        curr = curr->getNext();
        delete head;
    }
    head = NULL;
}
template <typename T>
int LLL<T>::pushFront(const T& src){
    return pushFront(Node<T>(src));
}
template <typename T>
int LLL<T>::pushFront(const Node<T>& src){
    Node<T>* temp = head;
    head = new Node<T>(src);
    head->setNext(temp);
    return 1;
}
template <typename T>
int LLL<T>::pushBack(const T& src){
    return pushBack(Node<T>(src));
}
template <typename T>
int LLL<T>::pushBack(const Node<T>& src){
    return pushBack(head, src);
}
template <typename T>
T LLL<T>::popFront(){
    if(!head) return NULL;
    T data = head->getData();
    Node<T>* temp = head->getNext();
    delete head;
    head = temp;
    return data;
}
template <typename T>
T LLL<T>::popBack(){
    if(!head) return NULL;
    return popBack(head);
}
template <typename T>
T LLL<T>::pop(const T& src){
    if(!head) return NULL;
    return pop(head, src);
}
template <typename T>
T LLL<T>::find(const T& src){}

//Extraction
template <typename T>
ostream& operator<<(ostream& out, const LLL<T>& L){
    if(!L.head) return out;
    else L.display(L.head, out);
    return out;
}
//Assignment
template <typename T>
LLL<T>& LLL<T>::operator=(const LLL<T>& L){}

template <typename T>
void LLL<T>::display(Node<T>* head, ostream& out) const{
    if(!head) return;
    out << *head << " ";
    //out << *head << std::endl;
    display(head->getNext(), out);
}
template <typename T>
int LLL<T>::pushBack(Node<T>*& head, const Node<T>& add){
    if(!head){
        head = new Node<T>(add);
        return 1;
    } 
    return pushBack(head->getNext(), add) + 1;
}
template <typename T>
T LLL<T>::popBack(Node<T>*& head){
    if(!head->getNext()){
        T data = head->getData();
        delete head;
        head = nullptr;
        return data;
    }
    return popBack(head->getNext());
}
template <typename T>
T LLL<T>::pop(Node<T>*& head, const T& src){
    if(!head) return NULL;
    if(head->getData() == src){
        Node<T>* temp = head->getNext();
        delete head;
        head = temp;
        return src;
    }   
    return pop(head->getNext(), src);
}

