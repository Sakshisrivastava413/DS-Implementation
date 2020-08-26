#include <iostream>
#include <vector>

using namespace std;

class Graph {
    vector<vector<int> > adjMat;
    public:
        Graph(int n) {
            adjMat.resize(n, vector<int>(n, 0));
        }

        void addNode(int from, int to) {
            adjMat[from][to] = 1;
            adjMat[to][from] = 1;
        }

        void printGraph() {
            for(int i = 0; i < adjMat.size(); i++) {
                for(int j = 0; j < adjMat.size(); j++) {
                    cout << adjMat[i][j] << " ";
                }
                cout << endl;
            }
        }

        bool hasEdge(int to, int from) {
            return adjMat[to][from];
        }
};

int main() {
    Graph g(4);
    g.addNode(0, 3);
    g.addNode(0, 2);
    g.addNode(2, 3);
    g.printGraph();
    cout << g.hasEdge(1, 2) << endl;
    cout << g.hasEdge(3, 2) << endl;
}