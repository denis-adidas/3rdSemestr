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
#include <sstream>
#include <algorithm>

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
    void copyToFinal(std::vector<int>& way);
    int FirstMinInRow(int vertex_index);
    int SecondMinInRow(int i);
    void greedy(int source);
    void TSPRec(int curr_bound, int current_weight, int level, std::vector<int> way, std::vector<int> vis);
    void TSP(int source);

    void print_graph() {
        ofstream fout("/Users/denis_adidas/CLionProjects/2courses_work/output.dot");
        fout << "digraph test { ";
        for (int i = 0; i < g.size(); i++) {
            fout << i + 1;
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] > 0)
                    fout << "->" << j + 1;
            }
            fout << endl;
        }
        fout << "}";
    }
};

#endif /* _course_work_1_lib_hpp */
