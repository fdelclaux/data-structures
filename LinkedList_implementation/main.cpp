/*
 *  main.cpp
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

#include "main.h"

int main(int argc , const char* argv[])
{
    try
    {
        if(argc < 2)
        {   
            throw invalid_argument("\tERROR: Not enough command line arguments");
        }

        string fileName = argv[1];

        ifstream inFile;

        inFile.open(fileName.c_str());

        if(!inFile)
        {   
            throw logic_error("\t ERROR: Failure to open file");
        }

/* 
            LL<char> *l1 = new LL<char>();

            l1->push_back('a');
            l1->push_front('b');
            l1->insert(1, 'c');

            cout << *l1 << endl;

            l1->insertionSort();

            cout << *l1 << endl;  */

            string headings;

            getline(inFile, headings);

            LL<Date> *l1 = new LL<Date>();

            Date d1;

            for(int i = 0; i < 15; i++)
            {
                inFile >> d1;
		        l1->push_back(d1);
            }

/*             cout << "testing stream insertion operator" << endl;
            cout << *l1 << endl; */

            Date d2;

/*             cout << "testing push_back, adding default Date " << endl;
            l1->push_back(d2);
            cout << *l1 << endl;

            cout << "testing pop_back, removing Default date" << endl;
            l1->pop_back();
            cout << *l1 << endl; */

/*              cout << "testing insert, inserting default date in 3rd position" << endl;
            l1->insert(3,d2);
            cout << *l1 << endl; */

/*             cout << "testing front and back methods" << endl;
           cout << "front: " << l1->front() << "  back: "<< l1->back() << endl;*/

/*             cout << "testing push front by adding default date at front" << endl;
            l1->push_front(d2);
            cout << *l1 << endl;

            cout << "testing pop front by eliminating default date at front" << endl;
            l1->pop_front();
            cout << *l1 << endl;  */

            cout << "testing copy constructor and copy list" << endl;
            LL<Date> *l2 = new LL<Date>();
            l2 = l1;
            cout << "l1:" << endl << *l1 << endl;
            cout << "l2" << endl << *l2 << endl;

/*          cout << "testing at() by searching for object in 5th position" 
            cout << endl;
            cout << l1->at(5) << endl;

            cout << "testing []  operator by searching for object in 5th position"
            cout << endl;
            cout << l1[5] << endl;
            //What is the syntax? l1->operator[](5) works */

/*          cout << "testing toArray() and clear() function by transforming it"
            " to array printing out array and checking contents of LL" << endl;
            Date *ptr = l1->toArray();
            for(int i = 0; i < l1->size(); i++)
            {
                cout << ptr[i] << endl;
            }
            l1->clear(); */

/*             cout << "testing bubble sort \n before sort:" << endl;
            cout << *l1 << endl << endl;
            l1->bubbleSort();
            cout << "after sort:" << endl;
            cout << *l1 <<  endl; */

            /* cout << "testing selection sort \n before sort:" << endl;
            cout << *l1 << endl << endl;
            l1->selectionSort();
            cout << "after sort:" << endl;
            cout << *l1 << endl; */

/*             cout << "testing insertion sort \n before sort:" << endl;
            cout << *l1 << endl << endl;
            l1->insertionSort();
            cout << "after sort:" << endl;
            cout << *l1 << endl; */

/*             cout << "testing linear search and binary search" << endl;
            l1->selectionSort();
            cout << l1->linearSearch(Date(1947,12,6)) << endl;
            cout << l1->binarySearch(Date(1947,12,6)) << endl; */


    }
    catch(no_such_object &e)
    {
        cout << "no_such_object caught" << endl;
        cout << e.what() << endl;
    }
    catch(bad_vehicle_code &e)
    {
        cout << "bad_vehicle_code caught" << endl;
        cout << e.what() << endl;
    }
    catch(out_of_range &e)
    {
        cout << "out_of_range caught" << endl;
        cout << e.what() << endl;
    }
    catch(invalid_argument &e)
    {
        cout << "invalid_argument caught" << endl;
        cout << e.what() << endl;
    }
    catch(logic_error &e)
    {
        cout << "logic_error caught" << endl;
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unknown exception caught in main" << endl;
    }
    //instantiate Linked List of chars

}
