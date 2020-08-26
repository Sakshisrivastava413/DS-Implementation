#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    vector<vector<int> > adjMat;
    unordered_map<int, vector<int> > adjList;

    public:
        Graph(int n) {
            adjMat.resize(n, vector<int>(n, 0));
        }

        void addNode(int from, int to) {
            adjMat[from][to] = 1;
            adjMat[to][from] = 1;

            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        void printGraph() {
            for(int i = 0; i < adjMat.size(); i++) {
                for(int j = 0; j < adjMat.size(); j++) {
                    cout << adjMat[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl << endl;

            for(auto i = adjList.begin(); i != adjList.end(); i++) {
                cout << i->first << "-> ";
                for(int j = 0; j < i->second.size(); j++) {
                    cout << i->second[j] << " ";
                }
                cout << endl;
            }
        }

        bool hasEdge(int to, int from) {
            return adjMat[to][from];
        }

        bool hasEdgeInList(int to, int from) {
            auto edges = adjList[to];
            for(int j = 0; j < edges.size(); j++) {
                if(edges[j] == from) return true; 
            }
            return false;
        }
};

int main() {
    Graph g(4);
    g.addNode(0, 3);
    g.addNode(0, 2);
    g.addNode(2, 3);
    g.printGraph();
    cout << g.hasEdge(1, 2) << endl << endl;
    cout << g.hasEdge(3, 2) << endl << endl;
    cout << g.hasEdgeInList(1, 2) << endl << endl;
}