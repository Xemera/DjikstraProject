#include "DataStructures.hpp"
#include <iostream>
#include <vector>
#include <list>

void ListImplementation::insert(int input) //O(1) STL Contains a tail pointer
{
    data.push_back(input); //Easy.
}

int ListImplementation::min()
{
    auto it = data.begin();
    int minimumValue = *it;


    while (it != data.end())
    {
        if (*it < minimumValue)
        {
            minimumValue = *it;
        }
        it++;

    }

    return minimumValue;
}

void ListImplementation::deleteMin() //Requires a search, O(n) time
{
    auto it = data.begin();
    auto itDelete = it;

    while (it != data.end())
    {
        if (*it < *itDelete)
        {
            itDelete = it;
        }
        it++;
    }

    data.erase(itDelete);
}

bool ListImplementation::isEmpty() //just check first value: O(1) time.
{
     return data.empty();
}

void MinHeapImplementation::insert(int input) //O(1) STL Contains a tail pointer
{
    hackVar++;
    heap.push_back(input);
    walkUp(heap.size() - 1);

}

void MinHeapImplementation::walkUp(int index)
{
    int current = index;
    int parent = index / 2;

    while (parent >= 0)
    {
        if (heap[current] <= heap[parent])
        {
            int temp = heap[current];
            heap[current] = heap[parent];
            heap[parent] = temp;
        }

        if (parent == 0)
            break;
        parent = parent / 2;
        current = current / 2;

    }
}

void MinHeapImplementation::walkDown(int index)
{
    int current = index;
    int child = index * 2;
    int temp;

    while (child < hackVar)
    {
        if (child == hackVar - 1)
        {
            child++;
        }

        if (heap[current] <= heap[child])
        {
            heap[current] = heap[child];
            current = child;
            child = child * 2;
        }
        else
            break;

    heap[current] = temp;
    }
}

void MinHeapImplementation::decreaseKey(int index, int value)
{
    heap[index] = value;
    walkUp(index);
}

int MinHeapImplementation::min() //O(1)
{
    return heap[0];
}

void MinHeapImplementation::deleteMin() //Requires a search, O(n) time
{
    hackVar--;
    heap[0]= heap[hackVar];
    walkDown(1);
}

bool MinHeapImplementation::isEmpty() //just check first value: O(1) time.
{
    return not hackVar;
}
