#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Default Constructor to Creates a new lqueue where m_head and m_tail point to nullptr
  Lqueue() : m_head(nullptr), m_tail(nullptr), m_size(0) {

  }
  // Destructor
  
~Lqueue(){

  //delete m_Lqueue.at(i);
    //m_Lqueue.at(i) = nullptr;
  }
  // Lqueue (Copy Constructor)
  
 Lqueue(const Lqueue &Lqueue){
    m_head = Lqueue.m_head;
    m_tail = Lqueue.m_tail;
  }
  // operator= (Overloaded Assignment Operator)
 Lqueue<T>& operator= (const Lqueue &Lqueue){
    if(this != &Lqueue){
      //delete Lqueue();
      m_head = Lqueue.m_head;
      m_tail = Lqueue.m_tail;
    }
    return *this;
  }
  
  // Adds a new node to the end of the lqueue.
  void Push(const T& ){
    Node<T>* newNode = new Node<T>(data);
    if(m_head == nullptr) {
      m_head = m_tail = newNode;
    } else {
      m_tail->SetNext(newNode);
      m_tail = newNode;
  }
  }
  
  //  Remove first node in the lqueue, returns data in first node
  T Pop(){
  if (!IsEmpty()) {
   Node<T>* temp = m_head;
   m_head = m_head->GetNext();
   T poppedData = temp->GetData();
    delete temp;
    // If the queue becomes empty after the pop, update the tail pointer
    if (m_head == nullptr) {
      m_tail = nullptr;
    }    
    return poppedData;
  } else {
    return T();
  }
  }

  // Displays the data in each node of lqueue
  void Display(){
  Node<T>* current = m_head;

  while (current != nullptr) {         // Traverse the linked list and output the data in each node
    cout << current->GetNext() << " " ;
    current = current->GetNext();
  }

 cout << endl;
}

// // Returns whatever data is in front
 
 T Front(){
   if (!IsEmpty) {
   return m_head->data;
 }
   return T();
 }

  // Returns if the lqueue is empty.
bool IsEmpty() {
  return m_head == nullptr;
}

  //  Returns m_size
int GetSize(){
  int m_size = 0;
  Node<T>* current = m_head;

  while (current != nullptr) {
    m_size++;
    current = current->GetNext();
  }

  return m_size;
}

// Iterates and if it finds the thing, returns index, else -1

int Find(T& thing){
   int index = 0;
  Node<T>* current = m_head;

    while (current != nullptr) {
      if (current->GetData() == thing) {

      return index;
    }

      current = current->GetNext();
    index++;
  }
  
  return -1;
}

void Clear(){             //Removes all nodes in a lqueue 
    Node<T>* current = m_head;
    Node<T>* nextNode;

    while (current != nullptr){
      nextNode = current->GetNext();
      delete current;
      current = nextNode;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
  }
 
  // Iterates to node x and returns data from Lqueue
  
T& At (int x){
  if (x < 0 || x >= GetSize()) {
    return T();
  }

  int index = 0;
  Node<T>* current = m_head;

  while (index < x) {
    current = current->GetNext();
    index++;
  }

  return current->data;
}
 
int main() {
  // Test your Lqueue implementation here
  Lqueue<int> myQueue;
  myQueue.Push(1);
  myQueue.Push(2);
  
  return 0;
}

  // OPTIONAL: EXTRA CREDIT
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Details: Must implement a separate file named swap_tests.cpp that is
  //          designed to test the swap function as well. See project document.
  //void Swap(int);

private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Lqueue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********Except Swap for extra credit******************



#endif
