#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include "GraphStructure.hpp"
#include "DataStructures.hpp"

int recursiveDjisktraPrototype(node *EntryNode, node *FinalNode);
void testCaseOne();
void testCaseTwo();

int main(int argc, char **argv)
{
    testCaseTwo();
    return 0;
}

void testCaseTwo(){
    MinHeapImplementation currentQueue;


    graph mainGraph;
    node nodeOne(1, {}, false);
    node nodeTwo(2, {}, true);
    node nodeThree(3, {}, true);
    node nodeFour(4, {}, true);
    node nodeFive(5, {}, true);
    node nodeSix(6, {}, true);
    node nodeSeven(7, {}, true);
    nodeOne.pushConnection(&nodeTwo, 1);
    nodeOne.pushConnection(&nodeThree, 2);
    nodeTwo.pushConnection(&nodeFour, 3);
    nodeThree.pushConnection(&nodeFour, 2);
    nodeFour.pushConnection(&nodeSix, 3);
    nodeFour.pushConnection(&nodeFive, 6);
    nodeFive.pushConnection(&nodeSeven, 5);
    nodeSix.pushConnection(&nodeSeven, 4);

    recursiveDjisktraPrototype(&nodeOne, &nodeSeven);
}




void testCaseOne(){
    MinHeapImplementation currentQueue;


    graph mainGraph;
    node nodeOne(3, {}, true);
    node nodeTwo(2, {}, true);
    node nodeThree(1, {}, true);
    node nodeFour({4, {std::pair<node*, int>{&nodeOne, 5}, std::pair<node*, int>{&nodeThree, 6}, std::pair<node*, int>{&nodeTwo, 7}}, false});
    nodeOne.pushConnection(&nodeThree, 2);
    nodeThree.pushConnection(&nodeTwo, 2);
    node nodeFive(5, {}, true);
    nodeTwo.pushConnection(&nodeFive, 3);
    nodeThree.pushConnection(&nodeFive, 2);
    nodeOne.pushConnection(&nodeFive, 1);

    mainGraph.pushNode(&nodeOne);
    mainGraph.pushNode(&nodeTwo);
    mainGraph.pushNode(&nodeThree);
    mainGraph.pushNode(&nodeFour);

    recursiveDjisktraPrototype(&nodeFour, &nodeFive);


}

int recursiveDjisktraPrototype(node *EntryNode, node *FinalNode)
{
    if (*EntryNode == *FinalNode)
    {
        std::cout << "Min value is: " << FinalNode->getCurrentMarked();
    }
    else
    {
        std::cout << "Calling function" << std::endl;
        for (auto i : EntryNode->getConnections())
        {
            std::cout << "Current node id: " << i.first->getIdentifier();
            std::cout << std::endl;
            std::cout << "Current node value: " << i.second;
            std::cout << std::endl;
            std::cout << "Current node sentinel: " << i.first->getCurrentMarked();
            std::cout << std::endl;
            if (EntryNode->getCurrentMarked() + i.second < i.first->getCurrentMarked() && !i.first->isChecked())
            {
                std::cout << "Modifying ID: " << i.first->getIdentifier() << std::endl;
                std::cout << "From: " << i.first->getCurrentMarked() << std::endl;
                i.first->changeMarkedValue(EntryNode->getCurrentMarked() + i.second);
                std::cout << "To: " << i.first->getCurrentMarked() << std::endl;
            }
        }
        EntryNode->toggleChecked();
        for (auto i : EntryNode->getConnections())
        {
            if (i.first == FinalNode)
            {
                std::cout << "Final node data: " << FinalNode->getCurrentMarked() << std::endl;
                return FinalNode->getCurrentMarked();
            }
        }
        node *next = EntryNode->getMinPair().first;
        recursiveDjisktraPrototype(next, FinalNode);
    }
}
