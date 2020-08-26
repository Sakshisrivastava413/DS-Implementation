#include <iostream>
#include <vector>
#include <stack>

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
    bool DFS(int source, int destination) {
        stack<int> s;
        vector<bool> visited(nodes, false);
        s.push(source);
        while(!s.empty()) {
            int top = s.top();
            visited[top] = true;
            s.pop();
            vector<int> edges = adjList[top];
            for(int i = 0; i < edges.size(); i++) {
                if(!visited[edges[i]]) s.push(edges[i]);
                if(edges[i] == destination) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addNode(0, 1);
    g.addNode(1, 3);
    g.addNode(0, 2);
    g.addNode(2, 4);
    cout << g.DFS(1, 4) << endl;
}