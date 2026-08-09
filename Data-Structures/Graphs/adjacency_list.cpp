#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

template <typename T>
class Graph{
    private:
        unordered_map<T, std::vector<T>> adjList;
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
};

int main()
{
    Graph<int>g;

    g.addEdge(10, 20);
    g.addEdge(20, 30);
    g.addEdge(10, 40);

    g.printGraph();
    return 0;
}