//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        //puts the idx at the end of the weightArr.
        weightArr[size] = idx;
        //restores the order of the heap
        upheap(idx, weightArr);
        //updates the size of the heap because an element was added.
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {}

            if (weightArr[i] < weightArr[j]) {
                int tmp = weightArr[i];
            }

        }


        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif