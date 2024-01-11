#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL

using namespace std;

template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
    bool empty() const;
  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
    int size() const;
  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front();

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back();

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum);

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum);
    

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front();

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back();

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear();

    List();
    List(const List<T> &other);
    
    List &operator=(const List<T> &other);

    ~List();
    
  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };
   int count = 0;
  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other);
  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  
public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.
      
      
  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
      Iterator& operator--();
      
      Iterator():node_ptr(nullptr){};
      
      T& operator* () const;
      
      Iterator & operator++ ();
      
      bool operator== (Iterator rhs) const;

      bool operator!= (Iterator rhs) const;
      
  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;
    // construct an Iterator at a specific position
      Iterator(Node *p):node_ptr(p){}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
    Iterator end() const{
        return Iterator(nullptr);
    }
    
  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i);

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum);
    
    private:
    void push_middle(Iterator i, const T &datum);

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.
template<typename T>
bool List<T>::empty() const {
    return (first == nullptr
            && last == nullptr
            && count == 0);
}

template<typename T>
int List<T>::size() const{
    return count;
}

template<typename T>
T & List<T>::front(){
    assert(!empty());
    return first->datum;
}

template<typename T>
T & List<T>::back(){
    assert(!empty());
    return last->datum;
}

template<typename T>
void List<T>::push_front(const T &datum){
    Node *p = new Node;
    p->datum = datum;
    p->next = first;
    p->prev = nullptr;
    if(empty()){
        first = p;
        last = p;
    }
    else{
        first->prev = p;
    }
    first = p;
    count++;
}

template<typename T>
void List<T>::push_back(const T &datum){
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    p->prev = last;
    if (empty()) {
        p->prev = nullptr;
        first = p;
        last = p;
    }
    else{
    last->next = p;
    last = p;
    }
    count++;
}

template<typename T>
void List<T>::pop_front(){
    assert(!empty());
    if(size() == 1){
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else{
        Node *p = first->next;
        delete first;
        p->prev = nullptr;
        first = p;
        
    }
    count--;
}

template<typename T>
void List<T>::pop_back(){
    assert(!empty());
    if(size() == 1){
        clear();
    }
    else{
        Node *p = last->prev;
        delete last;
        p->next = nullptr;
        last = p;
        count--;
    }
}

template<typename T>
void List<T>::clear(){
    while(!empty()){
        pop_front();
    }
}

template<typename T>
List<T>::List():first(nullptr),last(nullptr){}

template<typename T>
List<T>::List(const List<T> &other): first(nullptr),last(nullptr){
    copy_all(other);
}

template<typename T>
List<T> & List<T>::operator=(const List &other){
    if (this != &other) {
        clear();
        copy_all(other);
      }
      return *this;
}

template<typename T>
List<T>::~List(){
    clear();
}

template<typename T>
void List<T>::copy_all(const List<T> &other){
    assert(empty());
    for (Node *node_ptr = other.first; node_ptr; node_ptr = node_ptr->next) {
        push_back(node_ptr->datum);
      }
    count = other.count;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
  assert(node_ptr);
  node_ptr = node_ptr->prev;
  return *this;
}

template<typename T>
T  & List<T>::Iterator::operator* () const{
    assert(node_ptr != nullptr);
    return node_ptr->datum;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++ () {
assert(node_ptr != nullptr);
node_ptr = node_ptr->next;
return *this;
}

template<typename T>
bool List<T>::Iterator::operator== (Iterator rhs) const {
return node_ptr == rhs.node_ptr;
}

template<typename T>
bool List<T>::Iterator::operator!= (Iterator rhs) const {
return node_ptr != rhs.node_ptr;
}

template<typename T>
void List<T>::erase(Iterator i){
    assert(i.node_ptr);
    if(size() == 1){
        clear();
    }
    else if(i.node_ptr == first){
        pop_front();
    }
    else if(i.node_ptr == last){
        pop_back();
    }
    else{
        i.node_ptr->prev->next = i.node_ptr->next;
        i.node_ptr->next->prev = i.node_ptr->prev;
        delete i.node_ptr;
        count--;
    }
}

template<typename T>
void List<T>::insert(Iterator i, const T &datum){
    if(size() == 1 || i.node_ptr == first){
        push_front(datum);
    }
    else if (i.node_ptr == nullptr){
        push_back(datum);
    }
    else{
        push_middle(i,datum);
    }
}

template<typename T>
void List<T>::push_middle(Iterator i, const T &datum){
    Node *p = new Node;
    p->datum = datum;
    p->next = i.node_ptr;
    p->prev = i.node_ptr->prev;
    i.node_ptr->prev->next = p;
    i.node_ptr->prev = p;
    count++;
}


#endif // Do not remove this. Write all your code above this line.


