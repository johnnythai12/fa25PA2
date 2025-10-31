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
        int smallest = weightArr[0];
        weightArr[0] = weightArr[size-1];
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
            if (weightArr[parentNode] > weightArr[pos]) {
                swap (weightArr[pos], weightArr[parentNode]);
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
            if (leftChild < size && weightArr[leftChild] < weightArr[smallest]) {
                smallest = leftChild;
            }
            //comparing with right child node with left child of the parent
            //depends if the left Child was smaller than the parent node.
            if (rightChild < size && weightArr[rightChild] < weightArr[smallest]) {
                smallest = rightChild;
            }
            //if child node is smaller than the parent node swap it
            //then moves the parent node down
            if (smallest != pos) {
                swap (weightArr[pos], weightArr[smallest]);
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif