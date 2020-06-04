/*
*   Author: Felipe Delclaux
*   Project #2a
*   p2.cpp
*   February 14, 2020
*   COSC160
*/

#include "p2.h"


int main(int argc, const char* argv[])
{
    try
    {

        if(argc < 2)
        {
            throw logic_error("Not enough arguments. Please try again.");
        }

       /***************************************
        *                                     *
        *        Gathering Test File Data     *
        *                                     *
        ***************************************/
        
        string filename = argv[1];

        ifstream inFile;

        inFile.open(filename.c_str());

        string data;

        //Count number of insertions and store in vector
        vector<int> insertions;

        inFile >> data;

        while(data != "$" )
        {
            int value = stoi(data);
            insertions.push_back(value);
            inFile >> data;
        }


        //Count number of searches and store in vector
        vector<int> searches;

        inFile >> data;

        while(data != "$")
        {
            int value = stoi(data);
            searches.push_back(value);
            inFile>>data;
        }



        //Count number of removals and store in vector;

        vector<int> removals;

        inFile >> data;

        while(inFile)
        {
            int value = stoi(data);
            removals.push_back(value);
            inFile >> data;
            
        }

       /**********************************************
        *                                            *
        *               BST Operations               *
        *                                            *
        **********************************************/
        cout << "Binary Search Tree Structures: \n" << endl;

        BST tree1;

        int traversalInsertBST = 0;

        Node* root = tree1.getRoot();

        //insertions;

        auto start = chrono::steady_clock::now();
        for(int i = 0; i < insertions.size();i++)
        {
            traversalInsertBST += tree1.insert(root,insertions[i]);
        }
        auto end = chrono::steady_clock::now();
        
        std::chrono::duration<double> differenceInsertionsBST = end - start;

        cout << "\tStructure after insertion operations: " << endl;
        cout << "\t";
        tree1.print(root);
        cout << endl;

        //Searches

        int traversalSearchBST = 0;

        start = chrono::steady_clock::now();
        for(int i = 0; i < searches.size(); i++)
        {
            traversalSearchBST += tree1.search(root,searches[i]);
        }
        end = chrono::steady_clock::now();

        std::chrono::duration<double> differenceSearchesBST = end-start;

        //Removals

        int traversalRemovalBST = 0;

        start = chrono::steady_clock::now();
        for(int i = 0; i < removals.size(); i++)
        {
            traversalRemovalBST += tree1.remove(root, removals[i]);
        }
        end = chrono::steady_clock::now();

        std::chrono::duration<double> differenceRemovalsBST = end - start;

        cout << "\tStructure after the search and removal operations: " << endl;
        cout << "\t";
        tree1.print(root);
        cout << endl << endl;



       /*********************************************
        *                                           *
        *             Splay Tree Operations         *
        *                                           *
        *********************************************/

        cout << "Splay Tree Structures: \n" << endl;
        SplayTree s1;

        //Insertions

        int traversalInsertST = 0;

        start = chrono::steady_clock::now();
        for(int i = 0; i < insertions.size();i++)
        {
            traversalInsertST += s1.insert(s1.getRoot(),insertions[i]);
        }
        end = chrono::steady_clock::now();

        std::chrono::duration<double> differenceInsertionsST = end - start;

        cout << "\tStructure after insertion operations: " << endl;
        cout << "\t";
        s1.print(s1.getRoot());
        cout << endl;

        //Searches

        int traversalSearchST = 0;
        
        start = chrono::steady_clock::now();
        for(int i = 0; i < searches.size(); i++)
        {
            traversalSearchST += s1.search(s1.getRoot(), searches[i]);
        }
        end = chrono::steady_clock::now();

        std::chrono::duration<double> differenceSearchST = end - start;

        //Removals

        int traversalRemovalsST = 0;

        start = chrono::steady_clock::now();
        for(int i = 0; i < removals.size(); i++)
        {
            traversalRemovalsST += s1.remove(s1.getRoot(),removals[i]);
        }
        end = chrono::steady_clock::now();

        std::chrono::duration<double> differenceRemovalsST = end - start;

        cout << "\tStructure after search and removal operations: " << endl;
        cout << "\t";
        s1.print(s1.getRoot());
        cout << endl << endl;

       /********************************************
        *                                          *
        *                  OUTPUTS                 *
        *                                          *
        ********************************************/

        //Tabled output

        //Traversal Counts
        cout << setw(20) << "Operation" << setw(30) << "Binary Search Tree" << setw(30) << "Splay Tree" << endl;

        cout << setw(20) << "Insert: " << setw(30) << traversalInsertBST << setw(30) <<  traversalInsertST  << endl;
        cout << setw(20) << "Searches: " << setw(30) << traversalSearchBST << setw(30) << traversalSearchST << endl;
        cout << setw(20) << "Removals: " << setw(30) << traversalRemovalBST << setw(30) << traversalRemovalsST << endl;

        cout << setw(20) << "Total: " << setw(30) << traversalRemovalBST + traversalSearchBST + traversalInsertBST <<
                                         setw(30) << traversalInsertST + traversalSearchST + traversalRemovalsST << endl;

        cout << endl;
        
        //Time
        cout << setw(20) << "Operation" << setw(30) << "Binary Search Tree" << setw(30) << "Splay Tree" << endl;

        cout << setw(20) << "Insert: " << setw(30) << differenceInsertionsBST.count() << setw(30) <<  differenceInsertionsST.count()  << endl;
        cout << setw(20) << "Searches: " << setw(30) << differenceSearchesBST.count() << setw(30) << differenceSearchST.count() << endl;
        cout << setw(20) << "Removals: " << setw(30) << differenceRemovalsBST.count() << setw(30) << differenceRemovalsST.count() << endl;

        cout << setw(20) << "Total: " << setw(30) << differenceInsertionsBST.count() + differenceSearchesBST.count() + differenceRemovalsBST.count() <<
                                         setw(30) << differenceInsertionsST.count() + differenceSearchST.count() + differenceRemovalsST.count() << endl;

        cout << endl;


        //Comparing Efficiencies

        bool trav = (traversalRemovalBST + traversalSearchBST + traversalInsertBST) > (traversalInsertST + traversalSearchST + traversalRemovalsST);
        bool time = (differenceInsertionsBST.count() + differenceSearchesBST.count() + differenceRemovalsBST.count()) > differenceInsertionsST.count() + differenceSearchST.count() + differenceRemovalsST.count();

        if(trav && time)
        {
            cout << "The splay tree was more efficient both in time and traversal count. " << endl;
        }
        else if (!trav && !time)
        {
            cout << "The binary tree was more efficient both in time and traversal count. " << endl;
        }
        else
        {
            cout << "In terms of traversal count ";

            if(trav)
            {
                cout << "the splay tree was more efficient." << endl;
            }
            else
            {
                cout << "the binary search tree was more efficient." << endl;
            }

            cout << endl;

            cout << "In terms of time ";
            if(time)
            {
                cout << "the splay tree was more efficient." << endl;
            }
            else
            {
                cout << "the binary search tree was more efficient." << endl;
            }
        } 
        

        cout << endl;
        

    }
    catch(logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unkown exception caught in main" << endl;
    }

    return 0;
}

