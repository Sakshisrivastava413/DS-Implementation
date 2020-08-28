#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    int n;
    vector<vector<pair<int, int> > > graph;
    public:
        Graph(int n) {
            graph.resize(n);
            this->n = n;
        }
        void addEdge(int u, int v, int w) {
            graph[u].push_back({w, v});
            // graph[v].push_back({w, u});
        }
        void dijkstra(int source) {
            vector<int> distance(n, INT_MAX);
            distance[source] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
            q.push({ 0, source });
            while(!q.empty()) {
                int curr = q.top().second;
                int currWt = q.top().first;
                q.pop();
                for(int i = 0; i < graph[curr].size(); i++) {
                    int node = graph[curr][i].second;
                    int nodeWt = graph[curr][i].first;
                    if(currWt + nodeWt < distance[node]) {
                        distance[node] = currWt + nodeWt;
                        q.push({distance[node], node});
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                cout << source << " -> " << i << " = " << distance[i] << endl;
            }
        }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
    g.dijkstra(0);

}