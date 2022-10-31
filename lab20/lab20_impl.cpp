//
//  lab20_impl.cpp
//  lab20
//
//  Created by Денис Адидас on 10/21/22.
//

#include "lab20_impl.hpp"
using namespace std;

void dfs(int start, vector<bool> & visited, const vector <vector <int> > g)
{
    visited[start] = true;
    for (auto i : g[start])
        if (!visited[i]) {
            dfs(i, visited, g);
        }
}
