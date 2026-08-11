# 🚀 Data Structures & Algorithms in C++

Welcome to **Dsa-in-cpp**! This repository contains efficient, modern C++ implementations of fundamental Data Structures and Design & Analysis of Algorithms (DAA) concepts.

---

## 📌 Repository Overview

This repository is structured to help understand, implement, and master core algorithms and data structures ranging from basic trees to advanced graph traversals and shortest path algorithms.

---

## 📂 Topic Index

### 1. 🌐 Graph Algorithms
* **Graph Representation**: Generic Adjacency List using `std::unordered_map<T, std::vector<std::pair<T, int>>>` with structured bindings.
* **Graph Traversal**:
  * **BFS (Breadth-First Search)**: Ideal for unweighted single-source shortest path ($O(V + E)$).
  * **DFS (Depth-First Search)**: Deep path exploration using recursion/stack.
* **Shortest Path Algorithms**:
  * **Dijkstra's Algorithm**: Single-Source Shortest Path (SSSP) for weighted graphs with non-negative edge weights using `std::priority_queue` (Min-Heap).

### 2. 🌲 Trees & Binary Search Trees (BST)
* **BST Operations**: Insertion, Searching, and Traversal (Inorder, Preorder, Postorder).
* **BST Deletion**: Complete logic handling 0 children (leaf), 1 child, and 2 children (Inorder Successor).

### 3. 🧮 Fundamentals & Practice
* **Sorting & Divide/Conquer**: Quick Sort, Merge Sort.
* **Algorithmic Strategies**: Greedy Choice vs. Dynamic Programming (0/1 vs. Fractional Knapsack, Hash Maps vs. DP).

---