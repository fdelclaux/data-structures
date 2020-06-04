/* 
* Graph.h
*
* Node Class Implementation
*
* Edge Class Implementation
*
* Priority Queue structure Implementation
*
* Graph Structure Implementation
*
* Felipe Delclcaux
* COSC160
* Project 4
*/

#include "Graph.h"

int DEFAULT_DIST = 1000000;
/**************************
 *    costEdge function   *
 **************************/

int costEdge(Node* s, Node* e)
{
    int index;
    for(index = 0; index < s->adj.size();index++)
    {
        if(s->adj[index]->info == e->info)
        {
            break;
        }
    }
    return s->costs[index];
}

/**************************
 * 
 *      Node Class        *
 *                        
 **************************/

Node::Node(string info ,  bool known , int dist , Node* path)
{
    this->info = info;
    this->known = known;
    this->dist = dist;
    this->path = path;
}

Node::~Node()
{

}
/**************************
 *                        *
 *       Heap/Queue       *
 *     Implementation     *
 *                        *
 **************************/


PQueue::PQueue()
{
    currentSize = 0;
    maxSize = 0;
    inOrder = true;
    queue.push_back(new Node());
}


PQueue::PQueue(int maxSize)
{
    queue.reserve(maxSize);
    currentSize = 0;
    maxSize = maxSize;
    inOrder = true;
    queue.push_back(new Node());
}


PQueue::~PQueue()
{
    for(int i = 0; i < queue.size();i++)
    {
        delete queue.at(i);
    }
}


PQueue::PQueue(const PQueue& q)
{

    queue = q.queue;
    currentSize = q.currentSize;
    maxSize = q.maxSize;
    inOrder = q.inOrder;

}

void PQueue::enqueue(Node* &v)
{
    currentSize++;
    queue.push_back(v);
    // cout << "enq: " << queue[currentSize]->info << endl;
    if(currentSize > 1 && v->dist < queue[currentSize/2]->dist )
        inOrder = false;
}

Node* PQueue::dequeue()
{
    if(!inOrder)
        build();

    // cout << "Queue: ";
    // for(int i = 1; i<=currentSize;i++)
    // {
    //     cout  << queue[i]->info << " " << queue[i]->dist << " ";
    // }
    // cout << endl << "size: " << currentSize << endl;
    Node* returnVal = queue[1];
    // cout << "deq: " << returnVal->info << endl;
    queue[1] = queue[currentSize];
    queue.erase(queue.begin()+currentSize);
    currentSize--;
    if(currentSize > 1)
    {
        // cout << "percolate" << endl;
        percolateDown(1);
    }
    
    return returnVal;
}


void PQueue::build()
{
    int i = currentSize/2;
    while(i > 0)
    {
        percolateDown(i);
        i--;
    }
    inOrder = true;
}


void PQueue::percolateDown(int hole)
{
    Node* temp = queue[hole];

    while(hole <= currentSize/2)
    {
        int child = hole*2;
        if(child != currentSize && queue[child + 1]->dist < queue[child]->dist)
            child++;
        if(queue[child]->dist < temp->dist)
        {
            queue[hole] = queue[child];
            hole = child;
        }
        else
        {
            break;
        }
    }

    queue[hole] = temp;
}



/*****************************
 *                           *
 *    Graph Implementation   *
 *                           *
 *****************************/


Graph::Graph()
{
    nodeCount = 0;
}

Graph::~Graph()
{
    for(int i = 0 ; i < nodes.size(); i++)
    {
        delete nodes.at(i);
    }
}

Graph::Graph(const Graph& g)
{
    nodes = g.nodes;
    queue = g.queue;
}

Node* Graph::findNode(string n)
{
    for(int i = 0; i < nodes.size();i++)
    {
        if(nodes.at(i)->info == n)
        {
            return nodes.at(i);
        }
    }
    
    throw std::logic_error("Node given for Dijkstra's algorithm does not exist ");
    
}

void Graph::insertEdge(string start, int cost, string end)
{
    
    bool sFound = false;
    bool eFound = false;
    Node* startNode;
    Node* endNode;
    for(int i = 0; i < nodes.size(); i++)
    {
        if(start ==  nodes.at(i)->info)
        {
            startNode = nodes.at(i);
            sFound = true;
        }
        else if(end == nodes.at(i)->info)
        {
            endNode = nodes.at(i);
            eFound = true;
        }
    }
    
    if(!sFound)
    {
        startNode = new Node(start);
        nodes.push_back(startNode);
    }

    if(!eFound)
    {
        endNode = new Node(end);
        nodes.push_back(endNode);
    }

    // cout << "Insert: " <<endl;
    // cout << startNode->info << " " << cost << " " << endNode->info << "\n" << endl;
    
    startNode->adj.push_back(endNode); 
    startNode->costs.push_back(cost);

}

void Graph::dijkstras(Node* s)
{
    for(int i = 0; i < nodes.size();i++)
    {
        nodes.at(i)->dist = DEFAULT_DIST;
        nodes.at(i)->known = false;
        // cout << nodes.at(i)->info << endl;

    }

    s->dist = 0;
    queue.enqueue(s);
    Node* thisV;
    while(!(queue.isEmpty()))
    {
        thisV = queue.dequeue();
        if(!thisV->known)
        {
            thisV->known = true;
            for(int i = 0; i < thisV->adj.size();i++)
            {
                if(!(thisV->adj[i]->known))
                {
                    int newCost = costEdge(thisV, thisV->adj[i]);
                    if((thisV->dist + newCost) < thisV->adj[i]->dist)
                    {
                        thisV->adj[i]->dist = thisV->dist + newCost;
                        thisV->adj[i]->path = thisV;    
                    }
                    queue.enqueue(thisV->adj[i]);
                }
            }
        }
        
    }

}

void Graph::printPath(Node* v)
{

    if(v->path != NULL)
    {
        printPath(v->path);
        cout<< "-";
    }
    cout << v->info;
}

