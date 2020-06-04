/*
*   Author: Felipe Delclaux
*   Project #2a
*   BST.h
*   February 14, 2020
*   COSC160
*/

#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;
using std::logic_error; 


class Node
{

public:
    int value;
    Node *leftChild;
    Node *rightChild;
    
    
    Node(int value = 0, Node *leftChild = NULL, Node *rightChild = NULL);
    
}; 


//BST Class 

class BST
{
        friend std::ostream& operator<<(std::ostream& os, const BST &rhsObj);

private:
    Node *root;
    int nodeCount;

public:

    BST();
    BST(const BST&);
    ~BST();

    int search(Node* current, int value);
    int insert(Node* &current, int value);
    int remove(Node* &current, int value);
    int removeMin(Node* &parent, Node* &node);
    void print(Node* current);

    Node* getRoot(){return root;}
    int getNodeCount(){return nodeCount;}
    void clear(Node* &t);

};



