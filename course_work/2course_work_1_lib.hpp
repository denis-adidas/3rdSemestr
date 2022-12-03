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
    void TSP();
    
    void print_graph() {
        ofstream fout("/Users/denis_adidas/XCode project/2course_work_1/2course_work_1/output.dot");
        fout << "digraph test { ";
        for (auto i : g)
            for (auto j : i) {
                fout << "->" << j + 1;
            }
        fout << "}";
    }
    
    void checkResult() {
        int flag = 0;
        for (int i = 0; i < final_path.size(); i++) {
            if (final_path[i] > 0) flag++;
        }
        if (flag != nodes - 1) {
            cout << "Some nodes aren't connected! \nPlease, check source file!" << endl;
        }
    }
    void show_res() {
        cout << "Way: ";
        for (int i = final_path.size() - nodes - 1; i < final_path.size(); i++) {
            cout << final_path[i] + 1 << " ";
        }
        cout << endl << "Distance: " << final_result << endl;
    }
};

#endif /* _course_work_1_lib_hpp */
