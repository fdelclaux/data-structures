/*
 *  LL.h
 *
 *  COSC 052 Fall 2019
 *  Project #3
 *
 *  Due on: NOV 1, 2019
 *  Author: fsd7
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */

#ifndef _COSC052_FALL2019_P3_LL_h_
#define _COSC052_FALL2019_P3_LL_h_


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Exceptions.h"
#include "Resources.h"

#define DEBUG_LL_POP_BACK
//#define DEBUG_COPY_LIST
//#define DEBUG_LL_INSERT

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::out_of_range;


const int LOOP_OUTPUT_FREQUENCY = 5000;   //new for P3 (optional)
const int SORT_OUTPUT_FREQUENCY = 750;    //new for P3 (optional)

/****************************************************************************
 *                                                                          *
 *                                                                          *
 *                    Project #3 LL.h template classes                      *
 *                                                                          *
 *                                                                          *
 ****************************************************************************/




/****************************************************************************
 *                                                                          *
 *                       class Node declaration                             *
 *                                                                          *
 ****************************************************************************/


/**
 * <P>The <code>Node</code> class.</P>
 *
 * <P>This is a self-referential template class.  One or more <code>Node</code> objects
 * will be orgainzed in a doubly-linked list of objects.</P>
 *
 * <P>This class declaration is provided to students in COSC 052 Fall 2019
 * to use in part or in total for class projects.
 * Students may use this code as their own, without any attribution.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2019/10/12
 * @version 1.2, 2019/10/15
 * @version 1.3, 2019/10/16
 *
 */

template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;
    Node<T> *previous;
    
    Node(T = T(), Node<T> *next = NULL, Node<T> *previous = NULL);
    
}; //END declaration templatized class Node



/****************************************************************************
 *                                                                          *
 *                        class LL declaration                              *
 *                                                                          *
 ****************************************************************************/


/**
 * <P>The <code>LL</code> class.</P>
 *
 * <P>This is a template class that maintains a doubly-linked list
 * of <code>Node</code> objects.  One or more Node objects
 * will be used to create a linked-list.  The <code>LL</code> class
 * is responsible for maintaining all list "maintenance" tasks such as
 * adding objects to the list, removing objects from the list, 
 * locating specific objects on the list, etc.</P>
 *
 * <P>This class declaration is provided to students in COSC 052 Fall 2019
 * to use in part or in total for class projects.
 * Students may use this code as their own, without any attribution.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2019/10/12
 * @version 1.2, 2019/10/15
 * @version 1.3, 2019/10/16
 *
 */

template <typename T>
class LL
{
    template <typename F>
    friend std::ostream& operator<<(std::ostream& os, const LL<F> &rhsObj);
    
private:
    unsigned long count;   /*!< the number of object on the list */
    Node<T> *header;       /*!< the address of the header sentinel Node */
    Node<T> *trailer;      /*!< the address of the trailer sentinel Node */
    
    void copyList(const LL<T>&);
    void initialize();
    
    void remove(unsigned long ndx);
    
public:
    LL();
    LL(const LL<T>&);
    ~LL();
    
    LL<T>& operator=(const LL<T>&);
    
    void insert(unsigned long ndx, T);
    
    void push_back(T);
    void pop_back();
    T& back() const;
    
    void push_front(T);
    void pop_front();
    T& front() const;
    
    void clear();
    bool empty() const;
    unsigned long size() const {return count;}
    
    T& at(unsigned long ndx) const;
    T& operator[](unsigned long ndx) const;
    
    T* toArray() const;
    
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    unsigned long linearSearch(T lookFor) const;
    unsigned long binarySearch(T lookFor) const;
    
    
}; //END declaration templatized class LL









/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                 *
 *               CLASS IMPLEMENTATIONS             *
 *                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * *
 *   Node Class Implementation   *
 * * * * * * * * * * * * * * * * */

template <typename T>
Node<T>::Node(T infoValue, Node<T> *nPtr, Node<T> *pPtr)
{
    info = infoValue;
    next = nPtr;
    previous = pPtr;
    
} //END Node<T>::Node(T infoValue, Node *nodePtr)





/* * * * * * * * * * * * * * * * *
 *     LL Class Implementation   *
 * * * * * * * * * * * * * * * * */

/****************************************************************************
 *              non-member function overloaded operator<<                   *
 ****************************************************************************/

template <typename T>
std::ostream& operator<<(std::ostream& os, const LL<T> &rhsObj)
{
    Node<T> *current = rhsObj.header->next;

    while(current != rhsObj.trailer)
    {
        os << current->info << endl;
        current = current->next;
    }
    
    return os;
    
} //END overloaded stream insertion operator for LL<T> class



/****************************************************************************
 *                  private method copyList of LL class                     *
 ****************************************************************************/

template <typename T>
void LL<T>::copyList(const LL<T> &otherLL)
{
    if(!(this->empty()))
    {
        this->clear();
    }
    else
    {
        Node<T> *current = otherLL.header->next;
        while( current != trailer)
        {
            this->push_back(current->info); 
            current = current->next;
        }
    }
     
} //END function copyList(const LL &otherLL)



/****************************************************************************
 *                 private method initialize of LL class                    *
 ****************************************************************************/

template <typename T>
void LL<T>::initialize()
{
    header->next = trailer;
    trailer->next = trailer;
    header->previous = header;
    trailer->previous = header;

    count = 0;
    
} //END private method LL<T>::initialize



/****************************************************************************
 *                 private method remove of LL class                    *
 ****************************************************************************/

template <typename T>
void LL<T>::remove(unsigned long ndx)
{
    
    if(ndx >= count)
    {
        throw std::out_of_range("\tERROR: Given index is out of range "
                           "in LL<T>::remove");
    }

    Node<T> *current = header->next;

    for( int i = 0; i < ndx; i++)
    {
        current = current-> next;
    }

    current->next->previous = current->previous;
    current->previous->next = current-> next;
    delete current;

    count--;

}



/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
LL<T>::LL()
{
    header = new Node<T>;
    trailer = new Node<T>;

    this->initialize();
    
} //END default constructor for LL class



/****************************************************************************
 *                    copy constructor of LL class                          *
 ****************************************************************************/

template <typename T>
LL<T>::LL(const LL<T> &otherLL)
{

    this->copyList(otherLL);

} //END LL<T>::LL(const LL<T> &otherLL)



/****************************************************************************
 *                         destructor of LL class                           *
 ****************************************************************************/

template <typename T>
LL<T>::~LL()
{
    //destructor
    std::cout << "LL<T>::~LL() Entered destructor for class LL<T>\n";
    
    this->clear();
    
    std::cout << "LL<T>::~LL() Exiting destructor for class LL<T>\n";
    
} //END LL<T>::~LL()



/****************************************************************************
 *                 member function overloaded operator=                     *
 ****************************************************************************/


template <typename T>
LL<T>& LL<T>::operator=(const LL<T> &rhsLL)
{
    //overloaded assignment operator
    
    this->copyList(rhsLL);
    
    return *this;
    
} // END LL<T>::operator=(const LL<T> &rhsLL)



/****************************************************************************
 *                         member function insert                           *
 ****************************************************************************/

template <typename T>
void LL<T>::insert(unsigned long ndx, T infoToAdd)
{
 
#ifdef DEBUG_LL_INSERT
        cout << "Entered function LL<T>::insert() " << endl;
#endif

    if(ndx >= count)
    {
        throw std::out_of_range("\tERROR: Given index is out of range in "
                "LL<T>::insert");
    }
    
    Node<T> *addMe = new Node<T>(infoToAdd, NULL, NULL);
    Node<T> *current = header->next;

    for(unsigned long i = 0; i < ndx; i ++)
    {
        current = current->next;
    }

    current->previous->next = addMe;
    addMe->next = current;
    addMe->previous = current->previous;
    current->previous = addMe;

    count++;
#ifdef DEBUG_LL_INSERT
    cout << "Exiting function LL<T>::insert() " << endl;
#endif
    
} //END memmber function insert


    
/****************************************************************************
 *                        member function push_back                         *
 ****************************************************************************/

template <typename T>
void LL<T>::push_back(T infoToAdd)
{
    
#ifdef DEBUG_LL_PUSH_BACK
    cout << "Entered function LL<T>::push_back() " << endl;
#endif
    Node<T> *addMe = new Node<T>(infoToAdd, NULL, NULL);

    Node<T> *current = trailer->previous;

    addMe->next = trailer;
    addMe->previous = current;
    current->next = addMe;
    trailer->previous = addMe;

    count++;
    

    
    
#ifdef DEBUG_LL_PUSH_BACK
    cout << "Exiting function LL::push_back() " << endl;
#endif
    
} //END LL<T>::push_back(T infoToAdd)



/****************************************************************************
 *                        member function pop_back                          *
 ****************************************************************************/

template <typename T>
void LL<T>::pop_back()
{
    
    if(header->next == trailer)
    {
        throw no_such_object("\tERROR: There is no objects in this linked "
                "list to be popped back.");
    }

    Node<T>* current  = trailer->previous->previous;

    delete current->next;

    current->next = trailer;
    trailer->previous = current;

    count--;

    
} //END LL<T>::pop_back()



/****************************************************************************
 *                          member function back                            *
 ****************************************************************************/

template <typename T>
T& LL<T>::back() const
{
    if(header->next == trailer)
    {
        throw no_such_object("\tERROR: There is no objects in this linked list,"
                " in function LL<T>::back");
    }

    return trailer->previous->info;
}



/****************************************************************************
 *                       member function push_front                         *
 ****************************************************************************/

template <typename T>
void LL<T>::push_front(T infoToAdd)
{
    Node<T>* addMe = new Node<T>(infoToAdd, NULL, NULL);

    Node<T>* current = header->next;

    addMe->next = current;
    addMe->previous = header;
    header->next = addMe;
    current->previous = addMe;

    count ++;

} //END LL::push_front(T infoToAdd)



/****************************************************************************
 *                       member function pop_front                          *
 ****************************************************************************/

template <typename T>
void LL<T>::pop_front()
{
    if(header->next == trailer)
    {
        throw no_such_object("\tERROR: There is no objects in this linked "
                "list to be popped back.");
    }
    
    Node<T> * current = header->next->next;
    
    delete current->previous;

    current->previous = header;
    header->next = current;
    
    count--;
    
} //END LL<T>::pop_front()



/****************************************************************************
 *                          member function front                           *
 ****************************************************************************/

template <typename T>
T& LL<T>::front() const
{
   if(header->next == trailer)
   {
       throw no_such_object("\tERROR: There are no objects in this linked list, "
               "            in function LL<T>::front");
   }

   return header->next->info;
}



/****************************************************************************
 *                         member function clear                            *
 ****************************************************************************/

template <typename T>
void LL<T>::clear()
{
    // for testing
    unsigned long i = 0;
    
    std::cout << "\tLL<T>::clear() preparing to remove " << count;
    std::cout << " Nodes from the linked list\n";
    
    while(header->next != trailer)
    {
        this->pop_back();

    }
    
    count = 0;

    this->initialize();
    std::cout << "\tLL<T>::clear() removed " << i << " Nodes from the list\n";
    std::cout << "\tLL<T>::clear() new count is: " << count << std::endl;
    
} //END LL<T>::clear()



/****************************************************************************
 *                        method empty of LL class                          *
 ****************************************************************************/

template <typename T>
bool LL<T>::empty() const
{
    bool answer = true;
    if(count != 0)
    {
        answer = false;
    }
    
    
    return answer;
    
} // END LL<T>::empty



/****************************************************************************
 *                         member function at const                         *
 ****************************************************************************/

template <typename T>
T& LL<T>::at(unsigned long location) const
{

    if(location >= count)
    {
        throw std::out_of_range("\tERROR: Given index is out of range in LL<t>::at");
    }

    Node<T>* current = header->next;

    for(unsigned long i = 0; i < location; i++)
    {
        current = current->next;
    }

    return current->info;

} //END LL::at(int location)



/****************************************************************************
 *                       overloaded operator[] const                        *
 ****************************************************************************/

template <typename T>
T& LL<T>::operator[](unsigned long ndx) const
{
    return this->at(ndx);

} //END overloaded subscript operator

    

/****************************************************************************
 *                         member function toArray                          *
 ****************************************************************************/
    
template <typename T>
T* LL<T>::toArray() const
{
    // IMPORTANT NOTE!!!
    // remember that the code calling this method is responsible
    // for deallocating this dynamically allocated array
    
    T *tPtr = new T[count];

    Node<T>* current = header->next;
    int index = 0;

    while(current != trailer)
    {
        tPtr[index] = current->info;
        current = current->next;
        index++;
    }

    return tPtr;
    
} // END LL<T>::toArray()



/****************************************************************************
 *                       member function bubbleSort                         *
 ****************************************************************************/

template <typename T>
void LL<T>::bubbleSort()
{
    cout << "Entered member function bubbleSort()" << endl;
    
    //for testing
    unsigned long swapCount = 0;

    T temp;

    for(int i = 0;i < count; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if (this->at(j) > this->at(j+1))
            {
                temp = this->at(j);
                this->at(j) = this->at(j+1);
                this->at(j+1) = temp;
                swapCount++;
            }
            
        }
    }
    
    
    cout << "Exiting member function bubbleSort() \nresults: swapCount = " << swapCount << endl;
    
} //END member function LL<T>::bubbleSort()



/****************************************************************************
 *                     member function selectionSort                        *
 ****************************************************************************/
        
template <typename T>
void LL<T>::selectionSort()
{
    cout << "Entered function selectionSort() " << endl;

    //for testing
    unsigned long  swapCount = 0;

    T temp;
    int smallestValue;

    for(int i = 0; i < count - 1; i++)
    {
        smallestValue = i;
        for(int j = i + 1; j < count; j++ )
        {
            if(this->at(j) < this->at(smallestValue))
            {
                smallestValue = j; 
                swapCount++;
            }
        }

        temp = this->at(smallestValue);
        this->at(smallestValue) = this->at(i);
        this->at(i) = temp;
    }
    

    
    
    cout << "Exiting function selectionSort() \nresults: swapCount = " << swapCount << endl;
    
} // END void LL<T>::selectionSort()

    
    
/****************************************************************************
 *                     member function insertionSort                        *
 ****************************************************************************/

template <typename T>
void LL<T>::insertionSort()
{
    cout << "Entered function insertionSort() " << endl;
    
    //for testing
    unsigned long  swapCount = 0;
    
    T temp;
    int outOfOrder;

    for( int i = 1; i < count; i++)
    {
        if(this->at(i) < this->at(i-1))
        {
            temp = this->at(i);
            outOfOrder = i;

            while(outOfOrder > 0 && this->at(outOfOrder - 1) >= temp)
            {
                this->at(outOfOrder) = this->at(outOfOrder - 1);
                outOfOrder--;
                swapCount++;
            }

            this->at(outOfOrder) = temp;
        }
    }

    
    
    cout << "Exiting function insertionSort() \nresults: swapCount = " << swapCount << endl;
    
} // END void LL<T>::insertionSort()
    
        
        
/****************************************************************************
 *                      member function linearSearch                        *
 ****************************************************************************/

template <typename T>
unsigned long LL<T>::linearSearch(T lookFor) const
{
    cout << "Entered function linearSearch(" << lookFor << ")" << endl;

    unsigned long index = 0;
    bool found = false;

    for(index = 0; index < count; index++)
    {
        if(this->at(index) == lookFor)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        throw no_such_object("\tERROR: The object you were looking for was not"
                " found, using linear search");
    }
    
    cout << "Exiting function linearSearch()" << endl;
    
    return index;
    
} // END unsigned long LL<T>::linearSearch(T lookFor)

        
        
/****************************************************************************
 *                      member function binarySearch                        *
 ****************************************************************************/

template <typename T>
unsigned long LL<T>::binarySearch(T lookFor) const
{
    cout << "Entered function binarySearch(" << lookFor << ")" << endl;
    
    unsigned long index = 0;
    bool found = false;

    int first = 0;
    int last = count - 1;

    while ( first <= last && !found)
    {
        index = (first + last)/2;

        if(this->at(index) == lookFor)
            found = true;
        else if(this->at(index) > lookFor)
            last = index - 1;
        else
            first = index + 1;   
    }

    if(!found)
    {
        throw no_such_object("\tERROR: The object you are looking was not found, "
                            "using binary search");
    }
    
    
    cout << "Exiting function binarySearch()" << endl;
    
    return index;
    
} // END unsigned long LL<T>::binarySearch(T lookFor)


#endif