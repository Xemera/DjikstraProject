#include <iostream>
#include "GraphStructure.hpp"
#include <utility>
#include <vector>
#include <gtest/gtest.h>
#include <list>

struct nodeInitializationTest : testing::Test
{

    graph a;

    nodeInitializationTest()
    {
    }
};

TEST_F(nodeInitializationTest, IntegerInitializesProperly)
{
    node b(0, {});
    node c(1, {});
    a.pushNode(&b);
    a.pushNode(&c);
    std::vector<node*> nodeVec = a.getNodeVector();
    node *testOne = nodeVec[0];
    node *testTwo = nodeVec[1];
    testTwo->pushConnection(testOne, 2);
    ASSERT_EQ(testTwo->getConnections().front().second, 2);
}

TEST_F(nodeInitializationTest, PointerInitializesProperly)
{
    node b(0, {});
    node c(1, {});
    a.pushNode(&b);
    a.pushNode(&c);
    std::vector<node*> nodeVec = a.getNodeVector();
    node *testOne = nodeVec[0];
    node *testTwo = nodeVec[1];
    testTwo->pushConnection(testOne, 2);
    ASSERT_EQ(testTwo->getConnections().front().first, testOne);
}

TEST_F(nodeInitializationTest, GetMinGood)
{
    node b(0, {});
    node c(1, {});
    node d(1, {});
    a.pushNode(&b);
    a.pushNode(&c);
    a.pushNode(&d);
    std::vector<node*> nodeVec = a.getNodeVector();
    node *testOne = nodeVec[0];
    node *testTwo = nodeVec[1];
    node *testThree = nodeVec[2];
    testTwo->pushConnection(testOne, 2);
    testTwo->pushConnection(testThree, 5);
    ASSERT_EQ(testTwo->getMinPair().first, testOne);
}


int main(int argc, char **argv)
{
    std::cout << "Program initialized." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
