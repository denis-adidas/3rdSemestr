//
//  2course_work_1_lib.hpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/16/22.
//

#ifndef _course_work_1_lib_hpp
#define _course_work_1_lib_hpp

#include "iostream"

#include "fstream"
#include "vector"

using namespace std;

class graph {
protected:
    vector<vector<int>> g;
    vector<int> way, min_way;
    vector<int> visited;
    vector<int> fullGraph;
    int size, min_distance, distance;
    int nodes;
    
public:
    graph(string path) {
        size = 0;
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
        min_distance = 100;
        distance = 0;
    }
    int sum() {
        int sum = 0;
        for (auto i : visited)
                sum += i;
        return sum;
    }
    void dfs(int v, int v_start);
    void solve(int source, int current);
    void ShowGraph() {
        for (auto i : way) {
            cout << i << " ";
        }
    }
    int min_in_str(vector<int>& a, vector<int>& used) {
        int min = 100;
        int index = -1;
        for (auto i : a) {
            if (a[i] < min && !used[i]){
                min = a[i];
                index = i;
            }
        }
        return index;
    }
    int path(int current);
    void minimal(int current);
    
};
#endif /* _course_work_1_lib_hpp */
