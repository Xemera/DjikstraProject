#include "DataStructures.hpp"
#include <iostream>
#include <algorithm>
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

    while (parent > 0)
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

    if (heap.size() > 1)
    {
    if (heap[0] > heap[1])
    {
         int temp = heap[0];
         heap[0] = heap[1];
         heap[1] = temp;
    }
    }

    if (heap.size() > 2)
    {
    if (heap[0] > heap[2])
    {
         int temp = heap[0];
         heap[0] = heap[2];
         heap[2] = temp;
    }
    }




}

void MinHeapImplementation::walkDown( int input )
{
int child;
int tmp = input;

    if (heap.size() > 1)
    {
        if (heap[0] > heap[1])
        {
            std::swap(heap[0], heap[1]);
        }
    }

    if (heap.size() > 2)
    {
        if (heap[0] > heap[2])
        {
            std::swap(heap[0], heap[2]);
        }
    }

    for( ; input * 2 <= heap.size() - 1; input = child )
    {
    if (true)
    {


    child = input * 2;


    if( child < heap.size() - 1 && heap[ child + 1 ] < heap[ child ] )
        ++child;


        if( heap[ child ] < heap[tmp] )
        {
           std::swap(heap[input], heap[child]);
           tmp = child;

        }
        else
        break;

      }

    }

            std::swap(heap[input], heap[child]);
};



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
        if (heap.size() > 3)
        {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        hackVar--;
        walkDown(1);
        }
        else if (heap.size() == 2)
        {
            int a = heap[1];
            int b = heap[2];
            if (a < b)
            {
                 heap[0] = b;
                 heap.pop_back();
            }
            else
            {
                heap[0] = a;
                heap[1] = heap[2];
                heap.pop_back();
            }
        }
        else
        {
             heap[0] = heap[1];
             heap.pop_back();
        }
}

bool MinHeapImplementation::isEmpty() //just check first value: O(1) time.
{
    return not !heap.empty();
}
