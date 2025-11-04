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
        data[size] = idx;
        //restores the order of the heap
        upheap(size, weightArr);
        //updates the size of the heap because an element was added.
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int smallest = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);

        return smallest; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0 ) {
            //stores the location of the parent node to parentNode
            int parentNode = (pos - 1)/ 2;
            //if parentNode is larger than child node swap it
            //then places the parentNode to the child node.
            //update the position to the parentNode position.
            if (weightArr[data[parentNode]] > weightArr[data[pos]]) {
                swap (data[pos], data[parentNode]);
                pos = parentNode;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos >= 0 ) {

            int leftChild = (pos * 2) + 1;
            int rightChild = (pos * 2) + 2;
            int smallest = pos;
            //comparing with left child node
            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
                smallest = leftChild;
            }
            //comparing with right child node with left child of the parent
            //depends if the left Child was smaller than the parent node.
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
                smallest = rightChild;
            }
            //if child node is smaller than the parent node swap it
            //then moves the parent node down
            if (smallest != pos) {
                swap (data[pos], data[smallest]);
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif