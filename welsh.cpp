#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Edge {
    int u, v, cost;
};

string getColorName(int color) {
    static vector<string> colorNames = {
        "red", "green", "blue", "yellow", "cyan", "magenta", "orange", "purple", "pink", "gray"
    };
    return colorNames[color % colorNames.size()];
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    vector<vector<int>> adj(n + 1);

    cout << "\nEnter edges (u v cost):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        adj[edges[i].u].push_back(edges[i].v);
        adj[edges[i].v].push_back(edges[i].u);
    }

    // Sort nodes by degree
    vector<pair<int, int>> degree;
    for (int i = 1; i <= n; i++)
        degree.push_back({(int)adj[i].size(), i});
    sort(degree.rbegin(), degree.rend());

    vector<int> color(n + 1, -1);
    int colorCount = 0;

    // Welsh–Powell Algorithm
    for (auto &node : degree) {
        int u = node.second;
        if (color[u] == -1) {
            color[u] = colorCount;
            for (auto &node2 : degree) {
                int v = node2.second;
                if (color[v] == -1) {
                    bool canColor = true;
                    for (int neighbor : adj[v])
                        if (color[neighbor] == colorCount)
                            canColor = false;
                    if (canColor)
                        color[v] = colorCount;
                }
            }
            colorCount++;
        }
    }

    // Print color results
    cout << "\nNode Colors (Welsh–Powell Result):\n";
    cout << "----------------------------------\n";
    for (int i = 1; i <= n; i++)
        cout << "Node " << setw(2) << i << " → " << getColorName(color[i]) << "\n";

    cout << "\nTotal colors used: " << colorCount << "\n";

    // Generate Graphviz DOT file
    ofstream dot("graph_output.dot");
    dot << "graph G {\n";
    dot << "  layout=neato;\n  overlap=false;\n  splines=true;\n";

    // Nodes with colors
    for (int i = 1; i <= n; i++) {
        dot << "  " << i << " [style=filled, fillcolor=\"" << getColorName(color[i])
            << "\", fontcolor=black, shape=circle, label=\""
            << i << "\"];\n";
    }

    // Edges with costs
    for (auto &ed : edges) {
        dot << "  " << ed.u << " -- " << ed.v
            << " [label=\"" << ed.cost << "\", fontsize=10];\n";
    }

    dot << "}\n";
    dot.close();

    cout << "\nDOT file generated: graph_output.dot\n";

    // Graphviz
    int result = system("dot -Tpng graph_output.dot -o graph_output.png");
    if (result == 0) {
        cout << "Graph image saved as: graph_output.png ✅\n";
    } else {
        cout << "Could not generate image automatically.\n";
        cout << "If you have Graphviz installed, run this manually:\n";
        cout << "dot -Tpng graph_output.dot -o graph_output.png\n";
    }

    return 0;
}

/*
Enter number of nodes: 5
Enter number of edges: 6
Enter edges (u v cost):
1 2 4
1 3 5
2 3 6
2 4 2
3 5 3
4 5 1
*/