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
void testCaseThree();

int main(int argc, char **argv)
{
    testCaseThree();
    return 0;
}

void testCaseThree(){
    MinHeapImplementation currentQueue;
    graph mainGraph;

    node nodeTwenty(20, {}, false);
    node nodeZero(0, {}, true);
    node nodeOne(1, {}, true);
    node nodeTwo(2, {}, true);
    node nodeThree(3, {}, true);
    node nodeFour(4, {}, true);
    node nodeFive(5, {}, true);
    node nodeSix(6, {}, true);
    node nodeSeven(7, {}, true);
    node nodeEight(8, {}, true);
    node nodeNine(9, {}, true);
    node nodeTen(10, {}, true);
    node nodeEleven(11, {}, true);
    node nodeTwelve(12, {}, true);
    node nodeThirteen(13, {}, true);
    node nodeFourteen(14, {}, true);
    node nodeFifteen(15, {}, true);
    node nodeSixteen(16, {}, true);
    node nodeSeventeen(17, {}, true);
    node nodeEighteen(18, {}, true);
    node nodeNineteen(19, {}, true);
    node nodeTwentyOne(21, {}, true);

    //COLUMN 1
    nodeTwenty.pushConnection(&nodeZero, 0);
    nodeTwenty.pushConnection(&nodeFive, 7);
    nodeTwenty.pushConnection(&nodeTen, 3);
    nodeTwenty.pushConnection(&nodeFifteen, 3);

    //COLUMN 2
    nodeZero.pushConnection(&nodeFive, 7);
    nodeFive.pushConnection(&nodeZero, 7);

    nodeFive.pushConnection(&nodeTen, 7);
    nodeTen.pushConnection(&nodeFive, 7);

    nodeTen.pushConnection(&nodeFifteen, 1);
    nodeFifteen.pushConnection(&nodeTen, 1);

    //TRANSITIONS 2- 3
    nodeZero.pushConnection(&nodeOne, 10);
    nodeOne.pushConnection(&nodeZero, 10);
    nodeFive.pushConnection(&nodeSix, 5);
    nodeSix.pushConnection(&nodeFive, 5);
    nodeTen.pushConnection(&nodeEleven, 1);
    nodeEleven.pushConnection(&nodeTen, 1);
    nodeFifteen.pushConnection(&nodeSixteen, 4);
    nodeSixteen.pushConnection(&nodeFifteen, 4);

    //COLUMN 3
    nodeOne.pushConnection(&nodeSix, 3);
    nodeSix.pushConnection(&nodeOne, 3);

    nodeSix.pushConnection(&nodeEleven, 0);
    nodeEleven.pushConnection(&nodeSix, 0);

    nodeEleven.pushConnection(&nodeSixteen, 8);
    nodeSixteen.pushConnection(&nodeEleven, 8);

    //TRANSITIONS 3 - 4
    nodeOne.pushConnection(&nodeTwo, 1);
    nodeTwo.pushConnection(&nodeOne, 1);
    nodeSix.pushConnection(&nodeSeven, 10);
    nodeSeven.pushConnection(&nodeSix, 10);
    nodeEleven.pushConnection(&nodeTwelve, 6);
    nodeTwelve.pushConnection(&nodeEleven, 6);
    nodeSixteen.pushConnection(&nodeSeventeen, 10);
    nodeSeventeen.pushConnection(&nodeSixteen, 10);

    //COLUMN 4
    nodeTwo.pushConnection(&nodeSeven, 0);
    nodeSeven.pushConnection(&nodeTwo, 0);

    nodeSeven.pushConnection(&nodeTwelve, 6);
    nodeTwelve.pushConnection(&nodeSeven, 6);

    nodeTwelve.pushConnection(&nodeSeventeen, 0);
    nodeSeventeen.pushConnection(&nodeTwelve, 0);


    //TRANSITIONS 5 - 6
    nodeTwo.pushConnection(&nodeThree, 7);
    nodeThree.pushConnection(&nodeTwo, 7);
    nodeSeven.pushConnection(&nodeEight, 1);
    nodeEight.pushConnection(&nodeSeven, 1);
    nodeTwelve.pushConnection(&nodeThirteen, 10);
    nodeThirteen.pushConnection(&nodeTwelve, 10);
    nodeSeventeen.pushConnection(&nodeEighteen, 0);
    nodeEighteen.pushConnection(&nodeSeventeen, 0);

    //COLUMN 4
    nodeThree.pushConnection(&nodeEight, 4);
    nodeEight.pushConnection(&nodeThree, 4);

    nodeEight.pushConnection(&nodeThirteen, 3);
    nodeThirteen.pushConnection(&nodeEight, 3);

    nodeThirteen.pushConnection(&nodeEighteen, 3);
    nodeEighteen.pushConnection(&nodeThirteen, 3);

    //TRANSITIONS 6 - 7
    nodeThree.pushConnection(&nodeFour, 5);
    nodeFour.pushConnection(&nodeThree, 5);
    nodeEight.pushConnection(&nodeNine, 8);
    nodeNine.pushConnection(&nodeEight, 8);
    nodeThirteen.pushConnection(&nodeFourteen, 10);
    nodeFourteen.pushConnection(&nodeThirteen, 10);
    nodeEighteen.pushConnection(&nodeNineteen, 10);
    nodeNineteen.pushConnection(&nodeEighteen, 10);

    //COLUMN 4
    nodeFour.pushConnection(&nodeNine, 1);
    nodeNine.pushConnection(&nodeFour, 1);

    nodeNine.pushConnection(&nodeFourteen, 1);
    nodeFourteen.pushConnection(&nodeNine, 1);

    nodeFourteen.pushConnection(&nodeNineteen, 4);
    nodeNineteen.pushConnection(&nodeFourteen, 4);

    //TRANSITION 7 - 8
    nodeFour.pushConnection(&nodeTwentyOne, 1);
    nodeNine.pushConnection(&nodeTwentyOne, 4);
    nodeFourteen.pushConnection(&nodeTwentyOne, 4);
    nodeNineteen.pushConnection(&nodeTwentyOne, 3);

    recursiveDjisktraPrototype(&nodeTwenty, &nodeTwentyOne);
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
        std::cout << "  Entry NODE: " << EntryNode->getIdentifier() << std::endl;
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

        next->toggleChecked();
        do
        {
             next->popMinPair();
        } while (next->getMinPair().first->isChecked());

        recursiveDjisktraPrototype(next, FinalNode);
    }
}
