#ifndef HEAP_H
#define HEAP_H

#include <climits>

class MinHeap {
  public: MinHeap(int capacity): capacity(capacity),
  size(0) {
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];
    for (int i = 0; i < capacity; i++) {
      keyArray[i] = INT_MAX;
      position[i] = -1;
    }
  }
  void insert(int vertex, int key) {
    if (size == capacity) return;
    heapArray[size] = vertex;
    keyArray[vertex] = key;
    position[vertex] = size;
    int idx = size++;
    while (idx > 0) {
      int parentIdx = (idx - 1) / 2;
      if (keyArray[heapArray[parentIdx]] <= keyArray[heapArray[idx]]) break;
      swapnodes(idx, parentIdx);
      idx = parentIdx;
    }
  }
  int extractMin() {
    if (size == 0) return -1;
    int root = heapArray[0];
    position[root] = -1;
    heapArray[0] = heapArray[--size];
    position[heapArray[0]] = 0;
    minHeapify(0);
    return root;
  }
  void decreaseKey(int vertex, int newkey) {
    int i = position[vertex];
    keyArray[vertex] = newkey;
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (keyArray[heapArray[parent]] <= keyArray[heapArray[i]]) break;
      swapnodes(i, parent);
      i = parent;
    }
  }
  bool isInMinHeap(int vertex) {
    return position[vertex] != -1;
  }
  bool isEmpty() {
    return size == 0;
  }
  private: int * heapArray;int * keyArray;int * position;
  int capacity;
  int size;
  void minHeapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
      smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
      smallest = right;
    if (smallest != idx) {
      swapnodes(idx, smallest);
      minHeapify(smallest);
    }
  }
  void swapnodes(int a, int b) {
    int tmp = heapArray[a];
    heapArray[a] = heapArray[b];
    heapArray[b] = tmp;
    position[heapArray[a]] = a;
    position[heapArray[b]] = b;
  }
};

#endif