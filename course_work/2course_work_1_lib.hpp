//
//  2course_work_1_lib.hpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/16/22.
//

#ifndef _course_work_1_lib_hpp
#define _course_work_1_lib_hpp

#include "iostream"
#include <chrono>
#include "cstdlib"
#include "fstream"
#include "vector"
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

class graph {
protected:
    vector<vector<int>> g;
    vector<int> way, min_way;
    vector<int> visited;
    vector<int> final_path;
    int distance, nodes;
    int final_result;
    
public:
    graph(string path);
    int sum();
    void solve(int source, int current);
    void copyToFinal(std::vector<int>& way);
    int firstMinInRow(int vertex_index);
    int secondMinInRow(int i);
    void TSPRec(int curr_bound, int current_weight, int level, std::vector<int> way, std::vector<int> vis);
    void TSP();
    void show_res() {
        for (auto i : final_path) {
            cout << i << " ";
        }
    }
};

#endif /* _course_work_1_lib_hpp */
