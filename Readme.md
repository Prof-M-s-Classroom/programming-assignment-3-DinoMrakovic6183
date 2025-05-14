[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Dino Mrakovic

## Description
This program makes a minimum spanning tree using Prim’s algorithm.
First the graph is stored as an adjacency matrix in the graph.h Graph class.
The constructor fills the adjacency matrix with 0's. addEdge adds an undirected edge by 
setting adjMatrix[start][end] and adjMatrix[end][start] to the given weight 
(both directions are filled since the graph is undirected).
To follow Prim’s algorithm, every vertex is added to a custom min heap from heap.h, 
where the key (edge weight) is used as the priority.
The insert function adds each vertex to the heap.
While the heap is not empty, it keeps taking out the vertex with the smallest key using extractMin, 
and updates its neighbors using decreaseKey if a cheaper edge is found.
The isInMinHeap function makes sure we only update keys for vertices still in the heap.
When the heap is finally empty, it prints all the MST edges and the total cost.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity  |
|----------------------|------------------|
| Insert in MinHeap    | O(log n)         |
| Extract Min          | O(log n)         |
| Decrease Key         | O(log n)         |
| Prim’s MST Overall   | O(n^2)           |

_Explain why your MST implementation has the above runtime._

Each heap operation (insert, extractMin, decreaseKey) runs in O(log n) time.
For each vertex, checking neighbors takes O(n) time.
Because it's checking every vertex on every row/column, the runtime is O(n)*O(n)= O(n^2)

## Test Case Description

Input:  
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Output:
0 - 1: 2
1 - 2: 3
0 - 3: 6
1 - 4: 5
Total cost of MST: 16