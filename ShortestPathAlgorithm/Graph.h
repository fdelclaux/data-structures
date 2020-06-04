/* 
* Graph.h
*
* Node Class 
*
* Edge Class 
*
* Priority Queue structure 
*
* Graph Structure 
*
* Felipe Delclcaux
* COSC160
* Project 4
*/

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <list>
#include <vector>

using std::list;
using std::string;
using std::vector;
using std::cout;
using std::endl;


class Node
{   
    public:
  
        string info;
        vector<Node*> adj;
        vector<int> costs;
        bool known;
        int dist;
        Node* path;

        Node(string info = " ",  bool known = false, int dist = 0, Node* path = NULL);
        ~Node();

};



/**************************
 *                        *
 *       Heap/Queue       *
 *          Class         *
 *                        *
 **************************/


class PQueue
{
    private:
        vector<Node*> queue;
        int currentSize;
        int maxSize;
        bool inOrder;

    public:

        PQueue();
        PQueue(int maxSize);
        ~PQueue();
        PQueue(const PQueue&);

        void enqueue(Node*&);
        Node* dequeue();

        void build();
        void percolateDown(int hole);

        bool isEmpty(){ return (currentSize == 0);};


};

/**************************
 *                        *
 *       Graph Class      *
 *                        *
 **************************/

class Graph
{
    private:
        vector<Node*> nodes;
        PQueue queue;
        int nodeCount;

    public:
        Graph();
        ~Graph();
        Graph(const Graph&);

        Node* findNode(string);
        
        void insertEdge(string start, int cost, string end);
        void dijkstras(Node*);

        bool isEmpty(){ return queue.isEmpty();};

        void printPath(Node*);

};



