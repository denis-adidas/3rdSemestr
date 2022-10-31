//
//  main.cpp
//  lab20
//
//  Created by Денис Адидас on 10/21/22.
//

#include "lab20_impl.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    
    int n, m;
    
    string s;
    ifstream file("/Users/denis_adidas/XCode project/lab20/lab20/graph_input.txt");
    
    getline(file,s);
    char* cstr = new char[s.length()+1];
    strcpy(cstr, s.c_str());
    
    char* token = strtok(cstr, " \n");
    n = atoi(token);
    token = strtok(NULL, " \n");
    m = atoi(token);
    
    
    
    
    vector<vector<int>> graph(n);
    int u, v;

    for (int i = 0; i < m; i++) {
        getline(file, s);
        strcpy(cstr, s.c_str());
        token = strtok(cstr, " \n");
        u = atoi(token);
        token = strtok(NULL, " \n");
        v = atoi(token);
        u--; v--;
        graph[u].push_back(v);
    }
//        cout << graph[3][0] << "!!" << endl;


    
    int start = 0;
    while (start < 5) {
        vector <bool> visited(n);
        dfs(start, visited, graph);
        cout << "Result for " << start + 1 << ": ";
        for (int i = start; i < visited.size(); i++)
            if (visited[i] == true) cout << i + 1 << " ";
        cout << endl;
        start++;
    }
    file.close();
    return 0;
}
