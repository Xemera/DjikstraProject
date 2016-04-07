#include <iostream>
#include "GraphStructure.hpp"
#include <utility>
#include <vector>
#include <list>


int main(int argc, char **argv)
{
    graph a;
    node b(0, {});
    node c(1, {});
    node d(1, {});
    a.pushNode(&b);
    a.pushNode(&c);
    a.pushNode(&d);
    std::vector<node*> nodeVec = a.getNodeVector();
    node *testOne = nodeVec[0];
    node *testTwo = nodeVec[1];
    node *testThree = nodeVec[3];
    testTwo->pushConnection(testOne, 2);
    testTwo->pushConnection(testThree, 5);
    testTwo->getMinPair();

    return 0;
}
