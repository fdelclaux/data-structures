/*
*   Author: Felipe Delclaux
*   Project #2a
*   BST.cpp
*   February 14, 2020
*   COSC160
*/

#include "BST.h"


/****************************************************
 *                                                  *
 *              BINARY SEARCH TREE                  *
 *                                                  *
 ****************************************************/

Node::Node(int info, Node *left, Node* right)
{
    value = info;
    leftChild = left;
    rightChild = right;
} 

BST::BST()
{
    root = NULL;
    nodeCount = 0;

}

BST::BST(const BST& tree)
{

    root = tree.root;
    nodeCount = tree.nodeCount;

}


BST::~BST()
{
    clear(root);
}


int BST::search(Node* current, int value)
{
    int traversal = 0;
    traversal++;
    if(current == NULL || current->value == value)
    {
        return traversal;
    }

    else if(current->value > value)
    {
        traversal += search(current->leftChild, value);
    }
    else if(current->value < value)
    {
        traversal += search(current->rightChild, value);
    }

    return traversal;

}


int BST::insert(Node* &current, int value)
{
    int traversal = 0;
    Node *addMe = new Node(value, NULL, NULL);
    if(current == NULL) 
    {   
        traversal++;
        current = addMe;
        nodeCount++;
    }

    else if(current->value >= value )
    {
        traversal++;
        if(current->leftChild != NULL)
        {
            traversal += insert(current->leftChild, value);
        }
        else
        {
            current->leftChild = addMe; 
            nodeCount++;  
        }
    }
    
    else if(current->value < value )
    {
        traversal++;
        if(current->rightChild != NULL)
        {
            traversal += insert(current->rightChild, value);
        }
        else
        {
            current->rightChild = addMe;
            nodeCount++;
        }
    }

    return traversal;
        
}

int BST::removeMin(Node* &parent, Node* &node)
{
    int traversal = 0;
    if(parent != NULL)
    {
        traversal++;
        if(parent->leftChild != NULL)
        {
            traversal += removeMin(node, node->leftChild);
        }
        else
        {
            parent->leftChild = node->rightChild;
            parent->value = node->value;
            root = splay(parent, parent->value);
            delete node;
        }
        
    }
    else
    {
        traversal++;
        //throw logic_error("Item trying to be deleted was not found or the tree is empty");
    }

    return traversal;
    
}

int BST::remove(Node* &current, int value)
{
    int traversal = 0;
    nodeCount--;
    if(current != NULL)
    {
        traversal++;
        if(current->value < value)
        {
            
            traversal += remove(current->rightChild, value);
            
        }
        else if(current->value > value)
        {
            traversal += remove(current->leftChild, value);
        }
        else if (current->leftChild != NULL && current->rightChild != NULL)
        {
            traversal+= removeMin(current, current->rightChild);
        }
        else
        {
            Node* trash = current;
            
            traversal++;
            if(current->leftChild != NULL)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
            root = splay(current, value);
            delete trash;
            
        }
        
    }
    else
    {
        traversal++;
        //throw logic_error("Item trying to be deleted was not found or the tree is empty");
    }

    return traversal;
    
    

}

void BST::print(Node* current)
{
    cout << "[";

    if(current == NULL)
    {
        cout << "] ";
        return;
    }

    cout << current->value;

    if(current->leftChild == NULL && current->rightChild == NULL)
    {
        cout << "]";
        return;
    }
    

    print(current->leftChild);

    print(current->rightChild);
    
    cout << "] ";

}



void BST::clear(Node* & t)
{
    if(t != NULL)
    {
        clear(t->leftChild);
        clear(t->rightChild);
        delete t;
    }

    t = NULL;
}

