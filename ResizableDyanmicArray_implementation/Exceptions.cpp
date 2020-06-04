/*
 *  Exceptions.cpp
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

#include "Exceptions.h"

bad_vehicle_code::bad_vehicle_code(string msg) : invalid_argument(msg)
{

}

no_such_object::no_such_object(string msg) : logic_error(msg)
{
    
}

