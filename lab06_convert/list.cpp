// Fill in the functions at the bottom of this file
// 
#include <iostream>
using namespace std;
#include "list.h"

// on some machines member variables are not automatically initialized to 0
List::List()
{
    m_head = NULL;
    m_length = 0;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
List::~List()
{
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
}

// always insert at the front of the list
// Note: this works even in the SPECIAL CASE that the list is empty
void List::insert(int value)
{
    m_head = new Node(value, m_head);
    m_length++;
}

// iterate through all the Nodes in the list and print each Node
void List::print()
{
    for (Node *ptr = m_head; ptr; ptr = ptr->m_next)
    {
        cout << ptr->m_value << endl; 
    }
}

int *List::convert_to_array(int &size){
    if(m_head == NULL)return NULL;

    // (1) dynamically allocate an array of integers
    //      the exact same size of the list
    int* array = new int[length()];

    // (2) copy all the lists values into the array
    Node* tmp = m_head;
    int cur = 0;
    while(tmp != NULL){
        array[cur] = tmp->m_value;
        tmp = tmp->m_next;
        cur++;
    }
    
    // (3) assign the size of the array to size
    size = length();

    // (4) return the array
    return array;
}
