/*
 *  Resources.h
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

#ifndef _P1_RESOURCES_H_
#define _P1_RESOURCES_H_


#include <iostream>
#include <string> 
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;
using std::logic_error;
using std::cin;

const int MAX_LINES = 10;

// use for array indexes (can improve readability)
enum MONTH_LIST {DUMMY, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

const int MIN_YYYY = 1492;
const int MAX_YYYY = 2192;
const int MIN_MM = 1;
const int MAX_MM = 12;
const int MIN_DD = 1;
const int MAX_DD = 31;

const int DEFAULT_HOUR = 0;
const int DEFAULT_MINUTE = 0;
const int MAX_HOUR = 24;
const int MAX_MINUTE = 59;

std::string readDoubleQuotedString( std::istream& in ); // required

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Date declaration                             **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/**
 * <P>A class to represent a date in year, month, day format.</P>
 * <P>Each portion of the date is stored in an integer.</P>
 * <P>The class also overloads relational operators to compare
 * the order of Date objects:</P>
 *
 *<UL>
 *     <LI>20160101 is earlier than (less than) 20190908</LI>
 *     <LI>20160323 is later than (greater than) 20150323</LI>
 *     <LI>20190908 is equal to 20190908</LI>
 *     <LI>etc.</LI>
 *</UL>
 *
 * @author COSC 052 Given Code
 * @version 1.1.0, 2019/08/12
 * @version 1.2.0, 2019/08/18
 * @version 1.2.1, 2019/08/19
 * @version 1.3.0, 2019/08/20
 * @version 1.3.1, 2019/08/20
 * @version 1.3.2, 2019/08/20
 *
 */

class Date
{
    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);
    
public:
    Date(int year = MIN_YYYY, int month = MIN_MM, int day = MIN_DD); //yyyy, mm, dd
    Date(const Date&);
    void setDate(int, int, int);  //yyyy, mm, dd
    void setDate(const Date&);
    Date operator=(const Date&);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    bool operator ==(const Date&) const;
    bool operator !=(const Date&) const;
    bool operator <=(const Date&) const;
    bool operator <(const Date&) const;
    bool operator >=(const Date&) const;
    bool operator >(const Date&) const;
    
private:

    int yyyy; /*!< the year */
    int mm;   /*!< the month */
    int dd;   /*!< the day */
    
}; //end class Date




/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time declaration                                 **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/**
 * <P>A class to represent a the time of day in 24-hour format.</P>
 * <P>Each portion of the time is stored in an integer.</P>
 * <P>The class also overloads relational operators to compare
 * the order of Time objects:</P>
 *
 *<UL>
 *     <LI>00:58 is earlier than (less than) 10:32</LI>
 *     <LI>12:43 is later than (greater than) 01:20</LI>
 *     <LI>00:01 is equal to 00:01</LI>
 *     <LI>etc.</LI>
 *</UL>
 *
 * @author COSC 052 Given Code
 * @version 1.1.0, 2019/08/12
 * @version 1.2.0, 2019/08/18
 * @version 1.2.1, 2019/08/18
 * @version 1.2.2, 2019/08/19
 * @version 1.3.0, 2019/08/20
 *
 */

class Time
{
    friend std::istream& operator>>(std::istream &in, Time &t);
    //Overloaded stream extraction operator
    //Postcondition: Extracts values for each data member from 
    //the input stream.  Format of the data in the stream 
    //is assumed to be:  hh:mm
    //The delimiting character is read and discarded.
    
    friend std::ostream& operator<<(std::ostream &os, const Time &t);
    //Overloaded stream insertion operator.
    //Postcondition: The time is output to the steam.  Delimiting 
    //character is replaced.  The result is a time value
    //output in the same format as was read in (except values less than
    //10 shall be right padded with a 0 which may not have been
    //what was read in).
    
private:

    int hh; /*!< the hour of the day */
    int mm; /*!< the minutes past the hour */
    
    
public:
    Time(int hour = DEFAULT_HOUR, int minute = DEFAULT_MINUTE);
    //constructor with parameters, with default values
    //This constructor calls the member function setTime()
    //and passes the same arguments as were passed in to
    //the constructor, function setTime() updates the data members.
    //Postcondition: Sets the values of hh and mm
    //according to the values of the arguments passed in.
    //If no values are passed, this acts as the default constructor
    //all integer data members are set to values in dafault constants
    
    void setTime(int, int);
    //Function to set the values of the object data members,
    //can be called directly or by a constructor.
    //Postcondition: Data members are set to the values
    //of the respective arguments passed in.
    
    int getHour() const {return hh;}  /*!< return the hour data member */
    //In-line function to return the hour value.
    //Postcondtion: The value of data member hh is retured. 
    
    int getMinute() const {return mm;}  /*!< return the minute data member */
    //In-line function to return the minute value.
    //Postcondtion: The value of data member mm is retured.
    
    Time operator=(const Time&);
    //Overloaded assignment operator.
    //Postcondtion: The values of right hand side object's
    //data members are copied to the respective data
    //members of the left hand side object.
    
    /*!< return true if left side operand is equal to right side operand, false otherwise */
    bool operator==( const Time& ) const;
    
    /*!< return true if left side operand is NOT equal to right side operand, false otherwise */
    bool operator!=( const Time& ) const;
    
    /*!< return true if left side operand is greater than right side operand, false otherwise */
    bool operator>( const Time& ) const;
    
    /*!< return true if left side operand is less than right side operand, false otherwise */
    bool operator<( const Time& ) const;
    
}; //END class Time declaration


#endif
 // _P1_RESOURCES_H_ 
