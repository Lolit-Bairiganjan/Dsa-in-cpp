//Graph containing elements starting with 0, 1, 2... n

#include<iostream>
#include<vector>

using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> adj_matrix;
    
    public:
        Graph(int V){
            this->V = V;
            adj_matrix = vector<vector<int>>(V, vector<int>(V, 0));
        }

        void addEdge(const int &u, const int &v, bool isDirected = false){
            adj_matrix[u][v] = 1;
            if(!isDirected) adj_matrix[v][u] = 1;
        }

        void printGraph(){
            for(int i=0; i<V; i++){
                for(int edge : adj_matrix[i]) cout << edge << " ";
                cout << endl;
            }
        }
};

int main(){
    Graph g(5);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.printGraph();
}