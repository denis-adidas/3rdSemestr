//
// Created by Денис Адидас on 10/31/22.
//

#include "lab20_impl.h"

using namespace std;

void dfs(int start, vector<bool> & visited, const vector <vector <int> > g)
{
    visited[start] = true;
    for (auto i : g[start])
        if (!visited[i]) {
            dfs(i, visited, g);
        }
}
void fill_nodes(vector<string>& dfs_nodes, vector<vector<int>>& graph, int n) {
    int start = 0;
    while (start < 5) {
        vector<bool> visited(n);
        dfs(start, visited, graph);
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == true) {
                dfs_nodes[start].append(to_string(i+1));
            }
        }
        start++;
    }
}
void show_graph(ofstream& fout, vector<string>& dfs_nodes, vector<vector<int>>& graph) {
    fout << "digraph test { ";
    int start = 0;
    while (start < dfs_nodes.size()) {
        fout << "\"" << start + 1 << "(" << dfs_nodes[start] << ")\"";
        for (int i = 0; i < dfs_nodes[start].size() ; i++) {
            int d = dfs_nodes[start][i] - '0';
            fout << "->" << "\"" << d << "(" << dfs_nodes[d-1] << ")\"";
        }
        fout << endl;
        start++;
    }

    fout << "}";
}