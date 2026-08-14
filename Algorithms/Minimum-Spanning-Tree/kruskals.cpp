#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm> // Added for std::minmax / std::min / std::max

using namespace std;

template <typename T>
class Graph {
private:
    unordered_map<T, vector<pair<T, int>>> adjList;
    unordered_map<T, vector<pair<T, int>>> mst;

    // Helper find function with Path Compression
    T findRoot(T node, unordered_map<T, T>& parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = findRoot(parent[node], parent);
    }

    // Helper union function with Union by Rank
    bool uniteSets(T u, T v, unordered_map<T, T>& parent, unordered_map<T, int>& rank) {
        T rootU = findRoot(u, parent);
        T rootV = findRoot(v, parent);

        // Cycle detected: both nodes already belong to the same set
        if (rootU == rootV)
            return false;

        // Union by Rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }

        return true;
    }

public:
    void addEdge(const T &u, const T &v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void printGraph() {
        for (const auto &[node, neighbours] : adjList) {
            cout << node << " -> ";
            for (const auto &neighbour : neighbours) {
                cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
            }
            cout << endl;
        }
    }

    void kruskals() {
        mst.clear();
        int totalWeight = 0;

        // Min-Heap priority queue storing: {weight, {u, v}}
        priority_queue<pair<int, pair<T, T>>, 
                       vector<pair<int, pair<T, T>>>, 
                       greater<pair<int, pair<T, T>>>> pq;

        // DSU tables
        unordered_map<T, T> parent;
        unordered_map<T, int> rank;

        // Step 1: Initialize DSU parents and push unique edges into PQ
        set<pair<T, T>> seenEdges;

        for (const auto &[u, neighbours] : adjList) {
            parent[u] = u; // Each vertex is its own parent initially
            rank[u] = 0;

            for (const auto &edge : neighbours) {
                T v = edge.first;
                int weight = edge.second;

                // Normalize pair (u < v) to prevent inserting both (u, v) and (v, u)
                pair<T, T> edgePair = (u < v) ? make_pair(u, v) : make_pair(v, u);
                if (seenEdges.find(edgePair) == seenEdges.end()) {
                    seenEdges.insert(edgePair);
                    pq.push({weight, {u, v}});
                }
            }
        }

        int totalVertices = parent.size();
        int edgesCount = 0;

        // Step 2: Greedily process edges in increasing order of weight
        while (!pq.empty() && edgesCount < totalVertices - 1) {
            auto topEdge = pq.top();
            pq.pop();

            int weight = topEdge.first;
            T u = topEdge.second.first;
            T v = topEdge.second.second;

            // Step 3: Check and merge components via DSU
            if (uniteSets(u, v, parent, rank)) {
                // Add to MST adjacency list (undirected)
                mst[u].push_back({v, weight});
                mst[v].push_back({u, weight});

                totalWeight += weight;
                edgesCount++;
            }
        }

        cout << "MST Total Weight: " << totalWeight << endl;
    }

    void printMst() {
        cout << "\n--- Minimum Spanning Tree ---" << endl;
        for (const auto &[node, neighbours] : mst) {
            cout << node << " -> ";
            for (const auto &neighbour : neighbours) {
                cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<char> g;

    g.addEdge('A', 'B', 7);
    g.addEdge('A', 'C', 8);
    g.addEdge('B', 'C', 3);
    g.addEdge('B', 'D', 6);
    g.addEdge('B', 'D', 8);
    g.addEdge('C', 'D', 4);
    g.addEdge('C', 'E', 3);
    g.addEdge('D', 'E', 2);
    g.addEdge('D', 'F', 5);
    g.addEdge('E', 'F', 2);

    g.kruskals();
    g.printMst();

    return 0;
}