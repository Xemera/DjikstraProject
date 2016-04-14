#include "GraphStructure.hpp"
#include <iostream>

node::node(int identifierin, std::list<std::pair<node*, int> > connectionsin, bool isHead)
{
    identifier = identifierin;
    connections = connectionsin;

    if (isHead == true)
    {
        currentMarked = 10000;
    }
    else
    {
        currentMarked = 0;
    }

    checked = false;
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

    return *currentMinPointer;
}

void node::popMinPair()
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

    std::cout << "      Removed " << currentMinPointer->first->identifier << std::endl;
    connections.remove(*currentMinPointer);
}


int node::getIdentifier()
{
     return identifier;
}

int node::getCurrentMarked()
{
     return currentMarked;
}

void node::addMarkedValue(int delta)
{
    currentMarked = currentMarked + delta;
}

void node::changeMarkedValue(int value)
{
    currentMarked =  value;
}

bool node::operator==(node arg)
{
    //really simple operation overload.
    return this->identifier == arg.identifier;
}


void node::toggleChecked()
{
    checked = true;
}

bool node::isChecked()
{
    return checked;
}

void graph::pushNode(node *input)
{
    nodes.push_back(input);
}

std::vector<node*> graph::getNodeVector()
{
     return nodes;
}

