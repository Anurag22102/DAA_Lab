#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent;
    int rank;
};


class Graph {
    int V, E;
    vector<Edge> edges;


public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }
    
    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
    
    void Union(Subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);


        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    
    void KruskalMST() {
        vector<Edge> result;
        
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });
        
        Subset *subsets = new Subset[V];
        
        for (int v = 0; v < V; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        
        int i = 0, e = 0;
        while (e < V - 1 && i < E) {
            
            Edge next_edge = edges[i++];


            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
            
            if (x != y) {
                result.push_back(next_edge);
                Union(subsets, x, y);
                e++;
            }
        }
        
        cout << "Edges of MST:\n";
        int minimumCost = 0;
        for (i = 0; i < e; ++i) {
            cout << result[i].src << " - " << result[i].dest << "  Weight: " << result[i].weight << endl;
            minimumCost += result[i].weight;
        }
        cout << "Minimum Cost of MST: " << minimumCost << endl;


        delete[] subsets;
    }
};


int main() {
    int V = 4;
    int E = 5;
    Graph graph(V, E);
    
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    
    graph.KruskalMST();


    return 0;
}
