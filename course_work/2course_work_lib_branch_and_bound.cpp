//
//  2course_work_lib_branch_and_bound.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/29/22.
//

#include "2course_work_1_lib.hpp"


using namespace std;

void graph::copyToFinal(vector<int>& way) {
    int i;
    for (i = 0; i < nodes; i++)
        final_path.push_back(way[i]);
    final_path.push_back(way[0]);
}

int graph::FirstMinInRow(int i) {
    int min = INT_MAX;
    for (int j = 0; j < nodes; j++)
    {
        if ((g[i][j] < min) and (i != j)) {
            min = g[i][j];
        }
    }
    return min;
}

int graph::SecondMinInRow(int i) {
    int first = INT_MAX, second = INT_MAX;

    for (int j = 0; j < nodes; j++) {
        if (i == j) {
            continue;
        }
        if (g[i][j] <= first) {
            second = first;
            first = g[i][j];
        }
        else if (g[i][j] <= second && g[i][j] != first) {
            second = g[i][j];
        }
    }
    return second;
}

void graph::TSPRec(int current_bound, int current_weight, int level, vector<int> way, vector<int> visited) {
    if (level == nodes) {
        // check if there is an edge from last vertex in path back to the first vertex
        if (g[way[level - 1]][way[0]] != 0) {
            int curr_res = current_weight + g[way[level - 1]][way[0]];
            if (curr_res < final_result) {
                copyToFinal(way);
                final_result = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < nodes; i++) {

        vector<int> visitedInPath;
        vector<int> used;
        int j;
        for (j = 0; j < nodes; j++)
            visitedInPath.push_back(visited[j]);
            
        for (j = 0; j < nodes; j++)
            used.push_back(way[j]);
            

        if (g[used[level - 1]][i] > 0 && visitedInPath[i] == 0) {
            int temp = current_bound;
            current_weight += g[used[level - 1]][i];

            if (level == 1)
                current_bound -= (FirstMinInRow(used[level - 1]) + FirstMinInRow(i));
            else
                current_bound -= (SecondMinInRow(used[level - 1]) + FirstMinInRow(i));

            if (current_bound + current_weight < final_result) {
                used[level] = i;
                visitedInPath[i] = 1;
                TSPRec(current_bound, current_weight, level + 1, used, visitedInPath);
            }
            
            current_weight -= g[used[level - 1]][i];
            current_bound = temp;
        }
    }
}

void graph::TSP() {

    int current_bound = 0;

    for (int i = 0; i < nodes + 1; i++) way.push_back(-1);
    for (int i = 0; i < nodes; i++) visited.push_back(0);


    int i;
    for (i = 0; i < nodes; i++)
        current_bound += (FirstMinInRow(i) + SecondMinInRow(i));

//    current_bound = round(current_bound / 2);

    visited[0] = 1;
    way[0] = 0;
    TSPRec(current_bound, 0, 1, way, visited);
}
