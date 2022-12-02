//
//  2course_work_1_lib.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/16/22.
//

#include "2course_work_1_lib.hpp"
#include "cstdlib"

using namespace std;

graph::graph(string path) {
    string s;
    ifstream file(path);
    getline(file, s);
    char* cstr = new char[s.length()+1];
    strcpy(cstr, s.c_str());
        
    
    char* token = strtok(cstr, " \n");
    nodes = atoi(token);
        
    g.resize(nodes);
    
    int v;
    for (int i = 0; i < nodes; i++) {
        getline(file, s);
        strcpy(cstr, s.c_str());
        token = strtok(cstr, " \n");
        while (token != NULL) {
            v = atoi(token);
            g[i].push_back(v);
            token = strtok(NULL, " \n");
        }
    }
    file.close();
    visited.resize(nodes);
    min_way.resize(nodes);
    final_result = INT_MAX;
    distance = 0;
}


int graph::sum() {
    int sum = 0;
    for (auto i : visited)
        sum += i;
    return sum;
}

void graph::solve(int source, int current) {
    
    if ((current == 0) && (sum() == nodes)) {
        way.push_back(source);
        if (distance < final_result){
            final_result = distance;
            for(int i = 0; i < nodes; i++)
                min_way[i] = way[i];
            cout << source + 1 << " ";
            for (auto i : min_way) {
                cout << i + 1 << " ";
            }
            cout << endl;
            cout << "Distance: " << final_result << endl;
            return;
        }
    }
    if (visited[current] == 1) {
        return;
    }
    
    visited[current] = 1;
    vector<int> used(nodes);
    used[current] = 1;
    
    
    for(int i = 0; i < nodes; i++){
        if(!used[i] && g[current][i]){
                distance += g[current][i];
                way.push_back(i);
                solve(source, i);
                distance -= g[current][i];
                way.pop_back();
                used[i] = 0;
            }
        }
    visited[current] = 0;
    return;
}
