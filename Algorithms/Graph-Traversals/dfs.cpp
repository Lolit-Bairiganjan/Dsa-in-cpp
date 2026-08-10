//Implementation of dfs in graph made using adj_list for O(V+E) time complexity using recursion

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

template <typename T>
class Graph{
    private:
        unordered_map<T, std::vector<T>> adjList;
        unordered_map<T, bool> visited;
    public:
        void addEdge(const T &u, const T &v, bool isDirected = false){
            adjList[u].push_back(v);
            if(!isDirected) adjList[v].push_back(u);
        }
        void printGraph(){
            for(const auto &[node, neighbours] : adjList){
                cout << node << "->";
                for(const T &neighbour : neighbours){
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }

        void dfsTraversal(const T &startNode){
            visited[startNode] = true;
            cout << startNode << " ";
            for(const T &node : adjList[startNode]){
                if(visited.find(node) == visited.end()){
                    dfsTraversal(node);
                }
            }

        }
};

int main()
{
    Graph<int>g;

    g.addEdge(10, 20);
    g.addEdge(20, 30);
    g.addEdge(10, 40);

    g.printGraph();

    g.dfsTraversal(10);
    return 0;
}