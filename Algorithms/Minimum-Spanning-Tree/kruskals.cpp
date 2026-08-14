#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

const int INF = 1e9;

template <typename T>
class Graph{
    private:
        unordered_map<T, vector<pair<T, int>>> adjList;
        unordered_map<T, vector<pair<T, int>>> mst;
        unordered_map<T, bool> visited;
        priority_queue<pair<int, pair<T, T>>, vector<pair<int, pair<T, T>>>, greater<pair<int, pair<T, T>>>> pq;
    public:
        void addEdge(const T &u, const T &v, int weight){
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }

        void printGraph(){
            for(const auto &[node, neighbours] : adjList){
                cout << node << " -> ";

                for(const auto &neighbour : neighbours){
                    cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
                }

            cout << endl;
            }
        }
        void kruskals(){
            
        }

        void printMst(){
            cout << "\n--- Minimum Spanning Tree ---" << endl;
            for(const auto &[node, neighbours] : mst){
                cout << node << " -> ";

                for(const auto &neighbour : neighbours){
                    cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
                }

            cout << endl;
            }
        }
        
};

int main()
{
    Graph<char>g;

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

    //g.printGraph();

    g.kruskals();

    g.printMst();
    return 0;
}