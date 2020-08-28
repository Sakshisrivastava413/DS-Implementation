#include<iostream>
#include<vector>

using namespace std;

void bellmanFord(vector<vector<int> > graph, int N, int E, int source) {
    vector<int> distance(N, INT_MAX);
    distance[source] = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < E; j++) {
            if(distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]])
                distance[graph[j][1]] = distance[graph[j][0]] + graph[j][2];
        }
    }

    bool negitiveCycle = false;
    for(int j = 0; j < E; j++) {
        if(distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]]) {
            cout << "Negitive cycle detected";
            negitiveCycle = true;
            break;
        }
    }
    
    if(!negitiveCycle) {
        for(int i = 0; i < N; i++) {
            cout << source << " -> " << i << " = " << distance[i] << endl;
        }
    }
}

int main() {
    int N = 5;
    int E = 8;
    vector<vector<int> > graph = {
        { 0, 1, -1 }, { 0, 2, 4 }, 
        { 1, 2, 3 }, { 1, 3, 2 },  
        { 1, 4, 2 }, { 3, 2, 5 },  
        { 3, 1, 1 }, { 4, 3, -3 }
    };
    bellmanFord(graph, N, E, 0); 

}