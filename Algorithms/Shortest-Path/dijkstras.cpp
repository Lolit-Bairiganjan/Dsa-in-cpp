#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

template <typename T>
class Graph{
    private:
        unordered_map<T, vector<pair<T, int>>> adjList;
    public:
        void addEdge(const T &u, const T &v, int weight, bool isDirected = false){
            adjList[u].push_back({v, weight});
            if(!isDirected) adjList[v].push_back({u, weight});
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
};

int main()
{
    Graph<int>g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    g.printGraph();
    return 0;
}