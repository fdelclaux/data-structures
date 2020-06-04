
#include "p4.h"

int main(int argc, char* argv[])
{
    try{
        if(argc < 2)
        {
            throw logic_error("Please include the name of the file as an argument.");
        }
        
        string filename = argv[1];

        ifstream inFile;
        
        inFile.open(filename.c_str());

        if(!inFile)
        {
            throw logic_error("Could not open file, please try again.");
        }

        string start;
        string end;

        inFile >> start >> end;

        char scrap;

        inFile >> scrap;

        string s;
        string e;
        int c;

        Graph g1;

        while(inFile >> s >> e >> c)
        {
            g1.insertEdge(s,c,e);
        }

        g1.dijkstras(g1.findNode(start));

        // cout << "done" << endl;

        Node* finalDest = g1.findNode(end);

        cout << "\nPath: ";

        g1.printPath(finalDest);
        cout << endl;

        cout << "Cost: " << finalDest->dist << "\n"<<  endl;



        return 0;
    }
    catch(logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unkown exception caught in main." << endl;
    }
}