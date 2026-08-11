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

        void dijkstra(const T &source){
            unordered_map<T, int>dist;

            for(const auto &pair : adjList){
                dist[pair.first] = INF;
            }
            using pii = pair<int, T>;
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            pq.push({0, source});
            dist[source] = 0;

            while(!pq.empty()){
                const auto [curr_dist, u] = pq.top();
                pq.pop();
                // Not using visited hash_map to check if a node was visited. Using this instead
                if(curr_dist > dist[u]) continue;

                for(const auto &edge : adjList[u]){
                    T v = edge.first;
                    int weight = edge.second;

                    if(dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    } 
                }
            }
            std::cout << "--- Shortest Distances from " << source << " ---\n";
            for (const auto& [node, d] : dist) {
                if (d == INF) {
                    std::cout << source << " to " << node << " : Unreachable\n";
                } else {
                    std::cout << source << " to " << node << " : " << d << "\n";
                }
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

    g.dijkstra(0);
    return 0;
}