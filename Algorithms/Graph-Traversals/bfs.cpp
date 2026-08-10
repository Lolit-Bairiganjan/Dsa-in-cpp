//Implementation of bfs in graph made using adj_list for O(V+E) time complexity

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

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

        void bfsTraversal(const T &startNode){
            queue<T> bfsQueue;
            bfsQueue.push(startNode);
            visited[startNode] = true;

            while(!bfsQueue.empty()) {

                T currNode = bfsQueue.front();
                bfsQueue.pop();
                cout << currNode << " ";

                for(const T &node : adjList[currNode]){
                    if(visited.find(node) == visited.end()){
                        bfsQueue.push(node);
                        visited[node] = true;
                    }
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

    g.bfsTraversal(10);
    return 0;
}