/*
*   Author: Felipe Delclaux
*   Project #2a
*   ST.cpp
*   February 14, 2020
*   COSC160
*/

#include "ST.h"

/*********************************************************
 *                                                       *
 *                        SPLAY TREE                     *
 *                                                       *
 *********************************************************/

SplayNode::SplayNode(int info, SplayNode *left, SplayNode* right, SplayNode* parent)
{
    value = info;
    leftChild = left;
    rightChild = right;
    this->parent = parent;
} 

SplayTree::SplayTree()
{

    root = NULL;
    nodeCount = 0;

}


SplayTree::SplayTree(const SplayTree& rhsObj)
{

    root = rhsObj.root;
    nodeCount = rhsObj.nodeCount;

}


SplayTree::~SplayTree()
{
    clear(root);
}

SplayNode* SplayTree::leftRotate(SplayNode* node)
{
    SplayNode* temp = node->rightChild;
    SplayNode* b = temp->leftChild;
    SplayNode* p = node->parent;

    if(p)
    {
        if(p->rightChild == node)
            p->rightChild = temp;
        else
        {
            p->leftChild = temp;
        }
        
    }

    if(b)
    {
        temp->leftChild->parent = node;
    }
    
    temp->parent = p;
    
    temp->leftChild = node;
    
    node->parent = temp;
    
    node->rightChild = b;

    return temp;

}

SplayNode* SplayTree::rightRotate(SplayNode* node)
{
    SplayNode* temp = node->leftChild; 
    SplayNode* b = temp->rightChild;
    SplayNode* p = node->parent;
    
    if(p)
    {
        if(p->rightChild == node)
        {
            p->rightChild = temp;
        }
        else
        {
            p->leftChild = temp;
        }
        
    }
    
    if(b)
        temp->rightChild->parent = node;

    temp->parent = node->parent;

    temp->rightChild = node;
    
    node->parent = temp;

    node->leftChild = b;

    return temp;

}

SplayNode* SplayTree::splay(SplayNode* &node, int key, int &traversal)
{
    
    traversal++;
    while(node->parent != NULL)
    {
        if(node->parent->parent == NULL)
        {
            if(node->parent->value > key )
                node = rightRotate(node->parent);
            
            else if(node->parent->value < key)
                node = leftRotate(node->parent);
        }
        

        else if(node->parent->parent->value > key)
        {
            if(node->parent->value > key) //ZigZig
            {
                node=rightRotate(node->parent);
                node=rightRotate(node->parent);
            }
            else //ZigZag
            {
                node=leftRotate(node->parent);
                node=rightRotate(node->parent);
            }
            
            
        }
        else
        {
            if(node->parent->value > key) //ZigZag
            {
                node =rightRotate(node->parent);
                node = leftRotate(node->parent);
            }
            else//ZigZig
            {
                node = leftRotate(node->parent);
                node = leftRotate(node->parent);
            }
        }            
        
        
    }
       
    return node;
    
 }

int SplayTree::search(SplayNode* current, int value)
{
    int traversal = 0;
    traversal++;
    if(current == NULL)
    {
        return traversal;
    }

    if(current->value == value)
    {
        root = splay(current, value,traversal);
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


int SplayTree::insert(SplayNode* &current, int value)
{
    int traversal = 0;
    SplayNode *addMe = new SplayNode(value, NULL, NULL, NULL);

    if(current == NULL)
    {
        //traversal++;
        current = addMe;
        nodeCount++;
    }

    else if(current->value > value)
    {
        traversal++;
        if(current->leftChild != NULL)
        {
            traversal += insert(current->leftChild, value);
        }
        else
        {
            current->leftChild = addMe;
            addMe->parent = current;
            root = splay(addMe, value,traversal);
            nodeCount++;
        }
        
    }
    else if(current->value < value)
    {
        traversal++;
        if(current->rightChild != NULL)
        {
            traversal += insert(current->rightChild, value);
        }
        else
        {
            current->rightChild = addMe;
            addMe->parent = current;
            root = splay(addMe, value,traversal);
            nodeCount++;
        }
        
    }

    return traversal;
    
}


int SplayTree::remove(SplayNode* current, int value)
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
        else
        {

            root = splay(current, value,traversal);

            if(root->leftChild == NULL)
            {
                root = root->rightChild;
                root->parent = NULL;
            }
            else if(root->rightChild == NULL)
            {
                root = root->leftChild;
                root->parent = NULL;
            }
            else
            {
                SplayNode* pos = current->leftChild;
                while(pos->rightChild != NULL)
                {
                    pos = pos->rightChild;
                }

                pos->rightChild = current->rightChild;
                current->rightChild->parent = pos;
                root = root->leftChild;
                root->parent = NULL;
            }
           
            

            delete current;
        
        }
    }
    else
    {
        traversal++;
        //throw logic_error("Item trying to be deleted was not found or the tree is empty");
    }

    return traversal;
}


void SplayTree::print(SplayNode* current)
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


void SplayTree::clear(SplayNode* &t)
{
    if(t != NULL)
    {
        delete t->parent;
        clear(t->leftChild);
        clear(t->rightChild);
        delete t;
    }

    t = NULL;
}
