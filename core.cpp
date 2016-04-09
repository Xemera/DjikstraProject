#include <iostream>
#include "GraphStructure.hpp"
#include "DataStructures.hpp"
#include <utility>
#include <vector>
#include <list>


int main(int argc, char **argv)
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
    std::cout << a.min();

    return 0;
}
