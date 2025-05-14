#ifndef GRAPH_H
#define GRAPH_H
#include <climits>
#include <iostream>
#include "heap.h"

class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int start, int end, int weight) {
        adjMatrix[start][end] = weight;
        adjMatrix[end][start] = weight;
    }

    void primMST() {
        int* parent = new int[numVertices];
        int* key = new int[numVertices];
        bool* inMST = new bool[numVertices];

        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            inMST[i] = false;
            parent[i] = -1;
        }

        key[0] = 0;
        MinHeap heap(numVertices);
        for (int vertex = 0; vertex < numVertices; vertex++) {
            heap.insert(vertex, key[vertex]);
        }

        while (!heap.isEmpty()) {
            int current = heap.extractMin();
            inMST[current] = true;

            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                int weight = adjMatrix[current][neighbor];
                if (weight > 0 && !inMST[neighbor] && weight < key[neighbor]) {
                    key[neighbor] = weight;
                    parent[neighbor] = current;
                    heap.decreaseKey(neighbor, weight);
                }
            }
        }

        int totalCost = 0;
        for (int end = 1; end < numVertices; end++) {
            int start = parent[end];
            int weight = adjMatrix[start][end];
            std::cout << start << " - " << end << ": " << weight << "\n";
            totalCost += weight;
        }

        std::cout << "Total cost of MST: " << totalCost << std::endl;

    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif


