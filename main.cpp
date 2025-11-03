//
// Created by Manju Muralidharan on 10/19/25.
// Depth First Search or DFS for a Graph: https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
// Stack in C++ STL: https://www.geeksforgeeks.org/cpp/stack-in-cpp-stl/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "heap.h"
using namespace std;

// Global arrays for node information
const int MAX_NODES = 64;
int weightArr[MAX_NODES];
int leftArr[MAX_NODES];
int rightArr[MAX_NODES];
char charArr[MAX_NODES];

// Function prototypes
void buildFrequencyTable(int freq[], const string& filename);
int createLeafNodes(int freq[]);
int buildEncodingTree(int nextFree);
void generateCodes(int root, string codes[]);
void encodeMessage(const string& filename, string codes[]);

int main() {
    int freq[26] = {0};

    // Step 1: Read file and count letter frequencies
    buildFrequencyTable(freq, "input.txt");

    // Step 2: Create leaf nodes for each character with nonzero frequency
    int nextFree = createLeafNodes(freq);

    // Step 3: Build encoding tree using your heap
    int root = buildEncodingTree(nextFree);

    // Step 4: Generate binary codes using an STL stack
    string codes[26];
    generateCodes(root, codes);

    // Step 5: Encode the message and print output
    encodeMessage("input.txt", codes);

    return 0;
}

/*------------------------------------------------------
    Function Definitions (Students will complete logic)
  ------------------------------------------------------*/

// Step 1: Read file and count frequencies
void buildFrequencyTable(int freq[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open " << filename << "\n";
        exit(1);
    }

    char ch;
    while (file.get(ch)) {
        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';

        // Count only lowercase letters
        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a']++;
    }
    file.close();

    cout << "Frequency table built successfully.\n";
}

// Step 2: Create leaf nodes for each character
int createLeafNodes(int freq[]) {
    int nextFree = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            charArr[nextFree] = 'a' + i;
            weightArr[nextFree] = freq[i];
            leftArr[nextFree] = -1;
            rightArr[nextFree] = -1;
            nextFree++;
        }
    }
    cout << "Created " << nextFree << " leaf nodes.\n";
    return nextFree;
}

// Step 3: Build the encoding tree using heap operations
int buildEncodingTree(int nextFree) {
    // TODO:
    // 1. Create a MinHeap object.
    MinHeap heap;

    // 2. Push all leaf node indices into the heap.
    heap.push(nextFree, weightArr);

    int sizeOfHeap = heap.size;

    cout << weightArr[nextFree] << " HEAP SIZE" << endl;
    cout << nextFree << " LEAF NODES" << endl;

    // 3. While the heap size is greater than 1:
    //    - Pop two smallest nodes
    //    - Create a new parent node with combined weight
    //    - Set left/right pointers
    //    - Push new parent index back into the heap

     while (sizeOfHeap >= 1) {
       int leftChild = heap.pop(weightArr);
         cout << leftChild << " left child " << weightArr[leftChild] << endl;
       int rightChild = heap.pop(weightArr);
         cout << rightChild << " right child " << weightArr[rightChild] << endl;
       int parentNode = nextFree++;
         cout << parentNode << " PARENTNNFNFN----- " << endl;
       weightArr[parentNode] = weightArr[leftChild] + weightArr[rightChild];
       heap.push(parentNode, weightArr);
         sizeOfHeap = heap.size + 1;
        cout << sizeOfHeap << " parent node ";
    }

    // 4. Return the index of the last remaining node (root)
    int root = heap.pop(weightArr);

    return root; // placeholder
}

// Step 4: Use an STL stack to generate codes
void generateCodes(int root, string codes[]) {
    // TODO:
    // Use stack<pair<int, string>> to simulate DFS traversal.
    // Left edge adds '0', right edge adds '1'.
    // Record code when a leaf node is reached.

    stack<pair<int, string>> codesStack = {};
    codesStack.push(make_pair(root, codes[root]));
    while (!codesStack.empty()) {
        //stores the top element of the stack
        //then get the first and second elements of the element in the stack
        //then stores it separately
        pair<int, string> parentNode = codesStack.top();
        int rootNode = parentNode.first;
        string code = parentNode.second;
        //cout << charArr[rootNode] << "-----" << code << "\n";


        codesStack.pop();
        //checking if it is a leaf node
        if (leftArr[rootNode] == -1 && rightArr[rootNode] == -1) {
            char code1 = charArr[rootNode];
            //cout << code1 << endl;
            //cout << rootNode << "\n";
            //cout << rightArr[rootNode] << "letter222" << endl;
            //cout << leftArr[rootNode] << "letter223" << endl;
        }
        else {
            if (rightArr[rootNode] != -1) {
                codesStack.push(make_pair(rightArr[rootNode], code + '1'));
                //cout << rightArr[rootNode] << "letter" << endl;
            }
            if (leftArr[rootNode] != -1) {
                codesStack.push(make_pair(leftArr[rootNode], code + '0'));
                //cout << rightArr[rootNode] << "letter2" << endl;
            }
        }
    }
    //cout << "Generated codes for root " << root << "\n";




}

// Step 5: Print table and encoded message
void encodeMessage(const string& filename, string codes[]) {
    cout << "\nCharacter : Code\n";
    for (int i = 0; i < 26; ++i) {
        if (!codes[i].empty())
            cout << char('a' + i) << " : " << codes[i] << "\n";
    }

    cout << "\nEncoded message:\n";

    ifstream file(filename);
    char ch;
    while (file.get(ch)) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        if (ch >= 'a' && ch <= 'z')
            cout << codes[ch - 'a'];
    }
    cout << "\n";
    file.close();
}