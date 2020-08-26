#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int nodes;
    vector<vector<int> > adjList;

    public:
    Graph(int n) {
        this->nodes = n;
        adjList.resize(n);
    }

    void addNode(int v, int u) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool BFS(int source, int destination) {
        queue<int> q;
        vector<bool> visited(nodes, false);
        q.push(source);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            visited[top] = true;
            vector<int> edges = adjList[top];
            for(int i = 0; i < edges.size(); i++) {
                if(!visited[edges[i]]) q.push(edges[i]);
                if(edges[i] == destination) return true;
            }
        }
        return false;
    }

    bool BFSRecursive() {
        
    }
};

int main() {
    Graph g(5);
    g.addNode(0, 1);
    g.addNode(1, 3);
    g.addNode(0, 2);
    cout << g.BFS(2, 4) << endl;
}