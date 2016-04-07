#include "GraphStructure.hpp"
#include <iostream>

node::node(int identifierin, std::list<std::pair<node*, int> > connectionsin)
{
    identifier = identifierin;
    connections = connectionsin;
}

void node::pushConnection(node* input, int weight)
{
    connections.push_back(std::pair<node*, int>{input, weight});
}

std::list<std::pair<node*, int> > node::getConnections()
{
    return connections;
}

std::pair<node*, int> node::getMinPair()
{
    auto currentMinPointer = connections.begin();
    auto iteratorLoop = connections.begin();

    int currentMin = currentMinPointer->second;

    for (auto i : connections)
    {
        if (i.second < currentMin)
        {
            currentMin = iteratorLoop->second;
            currentMinPointer = iteratorLoop;
        }
        iteratorLoop++;
    }

    std::cout << currentMinPointer->second;
    return *currentMinPointer;

}

int node::getIdentifier()
{
     return identifier;
}

void graph::pushNode(node *input)
{
    nodes.push_back(input);
}

std::vector<node*> graph::getNodeVector()
{
     return nodes;
}
