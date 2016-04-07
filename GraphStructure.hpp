#ifndef GRAPHSTRUCTURE_H
#define GRAPHSTRUCTURE_H
#include <utility>
#include <list>
#include <vector>

class node
{
private:
    int identifier;
    std::list<std::pair<node*, int> > connections; //pair of weight and ptr.
public:
    node(int identifierin, std::list<std::pair<node*, int> > connectionsin);
    void pushConnection(node* input, int weight);
    std::list<std::pair<node*, int> > getConnections();
    std::pair<node*, int> getMinPair();
    int getIdentifier();

};

class graph
{
private:
    std::vector<node*> nodes;
    node* getID(int identifier);
public:
    void pushNode(node* input);
    std::vector<node*> getNodeVector();

};

#endif
