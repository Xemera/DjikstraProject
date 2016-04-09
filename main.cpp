#include <iostream>
#include "GraphStructure.hpp"
#include "DataStructures.hpp"
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

struct linkedListStructTest : testing::Test
{
    linkedListStructTest()
    {
    }
};

struct minHeapTest : testing::Test
{
    minHeapTest()
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

TEST_F(nodeInitializationTest, GetMinGoodThree)
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

TEST_F(nodeInitializationTest, GetMinGoodEight)
{
    node b(0, {});
    node c(1, {});
    node d(1, {});
    node e(1, {});
    node f(1, {});
    node g(1, {});
    node h(1, {});
    node i(1, {});

    a.pushNode(&b);
    a.pushNode(&c);
    a.pushNode(&d);
    a.pushNode(&e);
    a.pushNode(&f);
    a.pushNode(&g);
    a.pushNode(&h);
    a.pushNode(&i);

    std::vector<node*> nodeVec = a.getNodeVector();

    node *testOne = nodeVec[0];
    node *testTwo = nodeVec[1];
    node *testThree = nodeVec[2];
    node *testFour = nodeVec[3];
    node *testFive = nodeVec[4];
    node *testSix = nodeVec[5];
    node *testSeven = nodeVec[6];
    node *testEight = nodeVec[7];

    testTwo->pushConnection(testOne, 5);
    testTwo->pushConnection(testThree, 5);
    testTwo->pushConnection(testFour, 2);
    testTwo->pushConnection(testFive, 3);
    testTwo->pushConnection(testSix, 8);
    testTwo->pushConnection(testSeven, 1);
    testTwo->pushConnection(testEight, 3);

    ASSERT_EQ(testTwo->getMinPair().first, testSeven);
}

TEST_F(linkedListStructTest, LinkedListInsertGood)
{
     ListImplementation a;
     a.insert(5);
     ASSERT_EQ(a.min(), 5);
}

TEST_F(linkedListStructTest, LinkedListMinGood)
{
     ListImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     ASSERT_EQ(a.min(), 5);
}

TEST_F(linkedListStructTest, LinkedListDeleteMinGood)
{
     ListImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     ASSERT_EQ(a.min(), 15);
}

TEST_F(linkedListStructTest, IsEmptyGoodNotEmpty)
{
     ListImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     ASSERT_EQ(false, a.isEmpty());
}

TEST_F(linkedListStructTest, isEmptyGoodEmpty)
{
     ListImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     ASSERT_EQ(true, a.isEmpty());
}

TEST_F(linkedListStructTest, deleteAndGetMin)
{
     ListImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     ASSERT_EQ(a.min(), 105);
}

TEST_F(minHeapTest, minHeapInsertGood)
{
     MinHeapImplementation a;
     a.insert(5);
     ASSERT_EQ(a.min(), 5);
}

TEST_F(minHeapTest, minHeapMinSmall2Good)
{
     MinHeapImplementation a;
     a.insert(15);
     a.insert(5);
     ASSERT_EQ(a.min(), 5);
}

TEST_F(minHeapTest, minHeapMinSmall3Good)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     ASSERT_EQ(a.min(), 5);
}


TEST_F(minHeapTest, minHeapMinGood)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     ASSERT_EQ(a.min(), 5);
}

TEST_F(minHeapTest, minHeapDeleteMinGood)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     ASSERT_EQ(a.min(), 15);
}

TEST_F(minHeapTest, IsEmptyGoodNotEmpty)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     ASSERT_EQ(false, a.isEmpty());
}

TEST_F(minHeapTest, isEmptyGoodEmpty)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     ASSERT_EQ(true, a.isEmpty());
}

TEST_F(minHeapTest, deleteAndGetMin)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     a.deleteMin();
     a.deleteMin();
     a.deleteMin();
     ASSERT_EQ(a.min(), 105);
}

TEST_F(minHeapTest, deleteAndGetMinOutput)
{
     MinHeapImplementation a;
     a.insert(25);
     a.insert(5);
     a.insert(15);
     a.insert(105);
     ASSERT_EQ(a.min(), 5);
}


TEST_F(minHeapTest, testDeleteMinOne)
{
     MinHeapImplementation a;
    a.insert(11);
    a.insert(91);
    a.insert(2);
    a.insert(5);
    a.insert(100);
    a.insert(-22);
    a.insert(-21);
    a.deleteMin();
    a.deleteMin();
    ASSERT_EQ(a.min(), 2);
}

TEST_F(minHeapTest, testDeleteMinOneOutput)
{
     MinHeapImplementation a;
    a.insert(11);
    a.insert(91);
    a.insert(2);
    a.insert(5);
    a.insert(100);
    a.insert(-22);
    a.insert(-21);
    ASSERT_EQ(a.min(), -22);
}


TEST_F(minHeapTest, testDeleteMinTwo)
{
     MinHeapImplementation a;
    a.insert(11);
    a.insert(91);
    a.insert(100);
    a.insert(-22);
    a.insert(-21);
    a.deleteMin();
    a.deleteMin();
    ASSERT_EQ(a.min(), 11);
}

TEST_F(minHeapTest, testDeleteMinTwoOutput)
{
     MinHeapImplementation a;
    a.insert(11);
    a.insert(91);
    a.insert(100);
    a.insert(-22);
    a.insert(-21);
    ASSERT_EQ(a.min(), -22);
}


TEST_F(minHeapTest, testDeleteMinThree)
{
     MinHeapImplementation a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.insert(10);
    a.insert(11);
    a.deleteMin();
    a.deleteMin();
    a.deleteMin();
    a.deleteMin();
    a.deleteMin();
    a.deleteMin();
    ASSERT_EQ(a.min(), 6);
}

TEST_F(minHeapTest, testDeleteMinThreeOutput)
{
     MinHeapImplementation a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.insert(10);
    a.insert(11);
    ASSERT_EQ(a.min(), 1);
}


TEST_F(minHeapTest, testDecreaseKeyOne)
{
    MinHeapImplementation a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.insert(10);
    a.insert(11);
    a.decreaseKey(5, -9);
    ASSERT_EQ(a.min(), -9);
}


TEST_F(minHeapTest, testKeyFunctionalityMassive)
{
    MinHeapImplementation a;
    a.insert(1);
    a.insert(8);
    a.insert(3);
    a.insert(2);
    a.insert(5);
    a.insert(4);
    a.insert(2);
    a.insert(7);
    a.insert(8);
    a.insert(2);
    a.insert(40);
    a.insert(80);
    a.insert(-80);
    a.insert(-280);
    a.insert(0);
    a.insert(550);
    a.insert(9550);
    a.insert(51);
    a.insert(251);
    a.insert(2510);
    a.insert(2210);
    a.insert(22210);
    a.deleteMin();
    a.deleteMin();
    a.deleteMin();
    ASSERT_EQ(a.min(), 1);
}





int main(int argc, char **argv)
{
    std::cout << "Program initialized." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
