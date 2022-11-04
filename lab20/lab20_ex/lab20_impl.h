//
// Created by Денис Адидас on 10/31/22.
//

#ifndef lab20_impl_hpp
#define lab20_impl_hpp

#include <iostream>
#include "vector"
#include "string"
#include "fstream"
#include "stdlib.h"

using namespace std;

void dfs(int start, vector<bool> & visited, const vector <vector <int> > g);
void fill_nodes(vector<string>& dfs_nodes, vector<vector<int>>& graph, int n);
void show_graph(ofstream& fout, vector<string>& dfs_nodes, vector<vector<int>>& graph);


#endif /* lab20_impl_hpp */
