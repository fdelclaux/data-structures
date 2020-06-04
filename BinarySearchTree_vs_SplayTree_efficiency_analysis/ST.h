/*
*   Author: Felipe Delclaux
*   Project #2a
*   ST.cpp
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

class SplayNode
{

public:
    int value;
    SplayNode* parent;
    SplayNode *leftChild;
    SplayNode *rightChild;
    
    
    SplayNode(int value = 0, SplayNode *leftChild = NULL, SplayNode *rightChild = NULL, SplayNode *parent = NULL);
    
}; 

class SplayTree
{
        friend std::ostream& operator<<(std::ostream& os, const SplayTree &rhsObj);

    private:
        SplayNode *root;
        int nodeCount;

    public:
        SplayTree();
        SplayTree(const SplayTree&);
        ~SplayTree();

        SplayNode* leftRotate(SplayNode* node);
        SplayNode* rightRotate(SplayNode* node);
        SplayNode* splay(SplayNode* &node, int key, int &traversal); 

        int search(SplayNode* current, int value);
        int insert(SplayNode*& current, int value);
        int remove(SplayNode* current, int value);
        void print(SplayNode* current);

        SplayNode*& getRoot(){return root;}
        int getNodeCount(){return nodeCount;}
        void clear(SplayNode* &t);

}; 