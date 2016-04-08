#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <vector>
#include <list>

class ListImplementation
{
    public:
        void insert(int data);
        int min();
        void deleteMin();
        //void decreaseKey();
        //Not neccessary for linked list implementation.
        bool isEmpty();
    private:
        std::list<int> data;

};

class MinHeapImplementation
{
    public:
        void insert(int data);
        int min();
        void deleteMin();
        void decreaseKey(int index, int value);
        bool isEmpty();
        void walkUp(int index);
        void walkDown(int index);
    private:
        int hackVar{0}; //It's to confusing to keep track of vectors weird notation.
        std::vector<int> heap{}; //Vector makes implementation a bit easier. same principles.

};


#endif

