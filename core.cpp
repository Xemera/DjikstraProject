#include <iostream>
#include "GraphStructure.hpp"
#include "DataStructures.hpp"
#include <utility>
#include <vector>
#include <list>


int main(int argc, char **argv)
{
    MinHeapImplementation a;
    a.insert(11);
    a.insert(9);
    a.insert(17);
    a.insert(2);
    a.insert(12);
    a.insert(5);
    a.deleteMin();
    a.deleteMin();
    a.decreaseKey(2, 4);
    std::cout << a.min();

    return 0;
}
