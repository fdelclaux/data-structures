/*
 *  rd_array.h
 *
 *  COSC 052 Fall 2019
 *  Project #5
 *
 *  Due on: DEC 5, 2019
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

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Exceptions.h"
#include "Resources.h"

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::out_of_range;


template <typename T>
class RD_Array {

  public:
    RD_Array();
    RD_Array( const unsigned long, const T& = T() );
    RD_Array( const RD_Array<T> & );
    ~RD_Array();

    const RD_Array<T> &operator=( const RD_Array<T>& );

    T& at( const unsigned long ) const;
    T& operator[]( const unsigned long ) const;

    unsigned long size() const { return currentSize; };
    unsigned long capacity() const { return currentCapacity; };

    void insert( const unsigned long, const T& );
    void push_back( const T& );
    void pop_back();

    void resize( const unsigned long, const T& = T() );
    void clear();
    bool empty() const;

  private:
    T* contents;
    unsigned long currentSize;
    unsigned long currentCapacity;

    void increaseCapacity();

}; // END RD_Array<T> class declaration

/******************************************
 *                                        *
 *            CLASS CONSTRUCTORS          *
 *                                        *
 ******************************************/

/******************************************
 *           DEFAULT CONSTRUCTOR          *
 ******************************************/

template <typename T>
RD_Array<T>::RD_Array() 
{

  currentSize = 0;
  currentCapacity = 0;
  contents = NULL;

}

/******************************************
 *               CONSTRUCTOR              *
 ******************************************/

template <typename T>
RD_Array<T>::RD_Array(const unsigned long size, const T& content)
{

  currentSize = size;
  currentCapacity = size;
  T *arr1 = new T[size];
  for(int i = 0; i < size; i ++)
  {
    arr1[i] = content;
  }
  contents = arr1;

}

/******************************************
 *             COPY CONSTRUCTOR           *
 ******************************************/
template <typename T>
RD_Array<T>::RD_Array(const RD_Array<T>& otherRdar)
{

  currentSize = otherRdar.size();
  currentCapacity = otherRdar.capacity();

  T *arr1 = new T[currentCapacity];

  for(int i = 0; i < currentSize; i++)
  {
    arr1[i] = otherRdar[i];
  }

  contents = arr1;

}

/******************************************
 *              DESTRUCTOR                *
 ******************************************/
template <typename T>
RD_Array<T>::~RD_Array()
{
  delete [] contents;
}


/******************************************
 *                                        *
 *     OVERLOADED ASSIGNMENT OPERATOR     *
 *                                        *
 ******************************************/
template <typename T>
const RD_Array<T>& RD_Array<T>::operator=(const RD_Array<T>& otherRdar)
{

  if(!(this->empty()))
  {
    delete [] contents;
  }

  currentSize = otherRdar.size();
  currentCapacity = otherRdar.capacity();

  T *arr1 = new T[currentCapacity];

  for(int i = 0; i < currentSize; i++)
  {
    arr1[i] = otherRdar[i];
  }
  contents = arr1;

  return *this;

}

/******************************************
 *                                        *
 *       RD_Array MEMBER FUNCTIONS        *
 *                                        *
 ******************************************/

template <typename T>
T& RD_Array<T>::at(const unsigned long pos) const
{
  if(this->empty() || pos > currentSize - 1)
  {
    throw out_of_range("The index you are trying to access is out of range.");
  }

  return *(contents+pos);

}

template <typename T>
void RD_Array<T>::increaseCapacity()
{
  if(currentCapacity == 0)
  {

    currentCapacity = 1;

  }
  else
  {
    currentCapacity *= 2;
  }

  T *arr1 = new T[currentCapacity];

  for(int i = 0; i < currentSize; i++)
  {
    arr1[i] = *(contents+i);
  }

  contents = arr1;
  
}

template <typename T>
void RD_Array<T>::insert(const unsigned long pos, const T& value)
{

  if( pos < 0 || pos > currentSize)
  {
    throw out_of_range("The index you are trying to access is out of range.");
  }

  if(currentSize == currentCapacity)
  {
    increaseCapacity();
  }

  currentSize++;

  for(int i = currentSize; i > pos; i--)
  {
    *(contents+i) = *(contents +(i-1));
  }

  *(contents+pos) = value;

}

template <typename T>
void RD_Array<T>::push_back(const T& content)
{
  if(currentSize == currentCapacity)
  {
    increaseCapacity();
  }

  *(contents+currentSize) = content;

  currentSize++;

}

template <typename T>
void RD_Array<T>::pop_back()
{

  if(empty())
  {
    throw no_such_object("This array is empty, so no item can be popped back.");
  }

  currentSize--;

  //delete (contents+currentSize);

}

template <typename T>
void RD_Array<T>::resize(const unsigned long newSize, const T& content)
{

  if ( newSize < currentSize)
  {
    currentSize = newSize;
  }
  else if (newSize <= currentCapacity)
  {
    unsigned long oldSize = currentSize;

    currentSize = newSize;

    for(int i = oldSize; i < newSize; i ++)
    {
      *(contents+i) = content;
    }

  }
  else if( newSize > currentCapacity)
  {
    unsigned long oldSize = currentSize;

    T *arr1 = new T[newSize];
    
    currentCapacity = newSize;

    for( int i = 0; i < oldSize; i++)
    {
      arr1[i] = *(contents+i);
    }

    contents = arr1;

    currentSize = newSize;

    for(int i = oldSize; i < newSize; i++)
    {
      *(contents+i) = content;
    }
    
  }
}

template <typename T>
T& RD_Array<T>::operator[](const unsigned long pos) const
{
  if(pos < 0 || pos >= currentSize)
  {
    throw out_of_range("The index you are trying to access is out of range");
  }

  return *(contents+pos);


}

template <typename T>
void RD_Array<T>::clear()
{
  currentSize = 0;
}

template <typename T>
bool RD_Array<T>::empty() const
{
  bool empty = false;

  if(currentSize == 0)
  {
    empty = true;
  }

  return empty;
}

