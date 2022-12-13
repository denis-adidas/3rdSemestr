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
//#include "sstream>
#include "algorithm"


using namespace std;

class graph {
protected:
    vector<vector<int>> g;
    vector<int> way;
    vector<int> visited;
    vector<int> final_path;
    int distance, nodes;
    int final_result;
public:
    graph(string path);
    int sum();
    void solve(int source, int current);
    void copyToFinal(vector<int>& way);
    int FirstMinInRow(int vertex_index);
    int SecondMinInRow(int i);
    void greedy(int source);
    void TSPRec(int curr_bound, int current_weight, int level, vector<int> way, vector<int> vis);
    void TSP(int source);
    void print_graph();
};

#endif /* _course_work_1_lib_hpp */
