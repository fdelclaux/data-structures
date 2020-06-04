/*
 *  main.cpp
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

#include "main.h"

#define DEFAULT_CONSTRUCTOR
#define CONSTRUCTOR
#define COPY_CONSTRUCTOR
#define ASSIGNMENT_OPERATOR
#define SIZE
#define INCREASE_CAPACITY
#define CAPACITY
#define AT
#define POSITION_OPERATOR
#define PUSH_BACK
#define POP_BACK
#define INSERT
#define RESIZE
#define EMPTY
#define CLEAR

int main()
{

    try
    {
        #ifdef DEFAULT_CONSTRUCTOR
            
            cout << "Testing default constructor\n" << endl;

            RD_Array<char> rd1;

            cout << "\n" << endl;

        #endif

        #ifdef CONSTRUCTOR

            cout << "Testing parameter constructor\n" << endl;

            RD_Array<char> rd2(3, 'a');

            for(int i = 0; i < rd2.size(); i ++)
            {
                cout << rd2.at(i) << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef COPY_CONSTRUCTOR

            cout << "Testing copy construcctor\n" << endl;

            RD_Array<char> rd3(10, 'b');
            cout << "rd3:" << endl;

            for(int i = 0; i < rd3.size(); i ++)
            {
                cout << rd3.at(i) << " ";
            }

            cout << "\n" << endl;

            RD_Array<char> rd4(rd3);
            cout << endl << "rd4:" << endl;

            for(int i = 0; i < rd4.size(); i ++)
            {
                cout << rd4.at(i) << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef ASSIGNMENT_OPERATOR

            cout << "Testing overloaded assignment operator\n" << endl;

            RD_Array<char> rd5(10,'c');
            cout << "rd5:" << endl;

            for(int i = 0; i < rd5.size(); i ++)
            {
                cout << rd5.at(i) << " ";
            }

            cout << "\n" << endl;

            RD_Array <char> rd6;

            RD_Array<char> rd7 = rd6 = rd5;

            cout << endl << "rd6:" << endl;

            for(int i = 0; i < rd6.size(); i ++)
            {
                cout << rd6.at(i) << " ";
            }

            cout << "\n" << endl;

            cout << endl << "rd7:" << endl;

            for(int i = 0; i < rd7.size(); i ++)
            {
                cout << rd7.at(i) << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef SIZE

            cout << "Testing size member function\n" << endl;

            RD_Array<char> rd8(10, 'd');

            cout << rd8.size() << endl;

            cout << "\n" << endl;

        #endif

        #ifdef PUSH_BACK

            cout << "Testing push_back member function\n" << endl;

            RD_Array<char> rd23;

            rd23.push_back('a');
            rd23.push_back('b');
            rd23.push_back('c');

            RD_Array<char> rd01(10, 'x');

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

            cout << "\npush back y...\n" << endl;

            rd01.push_back('y');

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

            cout << "\npush back z...\n" << endl;

            rd01.push_back('z');

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef POP_BACK

            cout << "Testing pop_back member function\n" << endl;

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

            cout << "\npop back z...\n" << endl;

            rd01.pop_back();

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

            cout << "\npop back y...\n" << endl;

            rd01.pop_back();

            for(int i = 0; i < rd01.size(); i ++)
            {
                cout << rd01.at(i) << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef CAPACITY

            cout << "Testing capacity member function\n" << endl;

            RD_Array<char> rd08(10,'a');

            for(int i = 0; i < rd08.size(); i ++)
            {
                cout << rd08.at(i) << " ";
            }

            cout << endl << "rd8 cap: " << rd08.capacity() << endl;

            cout << "\nAfter pushing back another item... \n" << endl;

            rd8.push_back('b');

            for(int i = 0; i < rd08.size(); i ++)
            {
                cout << rd08.at(i) << " ";
            }

            cout << endl << "rd8 cap: " << rd08.capacity() << endl;

            cout << "\n" << endl;

        #endif

        #ifdef AT
            cout << "Testing at member function\n" << endl;

            RD_Array<char> rd002(10);

            for(int i = 0; i < 10 ; i++)
            {
                rd002.at(i) = static_cast<char>(i+1);
                cout << rd002.at(i) << " ";
            }

        #endif

        #ifdef POSITION_OPERATOR

            cout << "Testing position operator member function\n" << endl;

            RD_Array<char> rd02(10, 'a');

            rd02.push_back('z');

            for(int i = 0; i < rd02.size(); i++)
            {

                cout << rd02[i] << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef INSERT

            cout << "Testing insert member function\n" << endl;

            RD_Array<char> rd03(5,'a');

            for(int i = 0; i < rd03.size(); i++)
            {

                cout << rd03[i] << " ";
            }

            cout << "\nAfter insert method\n" << endl;

            rd03.insert(rd03.size(),'b'); 

            for(int i = 0; i < rd03.size(); i++)
            {
                cout << rd03[i] << " ";
            }

            cout << "\n" << endl;

        #endif

        #ifdef RESIZE

            cout << "Testing resize member function\n" << endl;

            RD_Array<char> rd04(10, 'a');

            for(int i = 0; i < rd04.size(); i++)
            {

                cout << rd04[i] << " ";
            }

            cout << "\n" << endl;

            cout << "Resizing RDArray to 5\n" << endl;

            rd04.resize(5);

            for(int i = 0; i < rd04.size(); i++)
            {

                cout << rd04[i] << " ";
            }

            cout << "\n" << endl;

            cout << "Resizing RDArray back to 8\n" << endl;

            rd04.resize(8, 'b');

            for(int i = 0; i < rd04.size(); i++)
            {

                cout << rd04[i] << " ";
            }

            cout << "\n" << endl;

            cout << "Resizing RDArray to 12\n" << endl;

            rd04.resize(12, 'c');

            for(int i = 0; i < rd04.size(); i++)
            {

                cout << rd04[i] << " ";
            }
            
            cout << "\n" << endl;

        #endif

        #ifdef CLEAR

            cout << "Testing clear member function\n" << endl;

            cout << rd04.size() << endl;

            rd04.clear();

            cout << "\n" << rd04.size() << endl;

            cout << endl;

        #endif

        #ifdef EMPTY

            cout << "Testing empty member function\n" << endl;

            cout << rd04.empty() << endl;

            cout << endl;

        #endif
    }
    catch(no_such_object &e)
    {
        cout << "no_such_object caught" << endl;
        cout << e.what() << endl;
    }
    catch(out_of_range &e)
    {
        cout << "out_of_range caught" << endl;
        cout << e.what() << endl;
    }
    catch(bad_alloc &e)
    {
        cout << "bad_alloc caught" << endl;
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
        cout << "Unkown Exception caught in main" << endl;
    }

    return 0;

}