//
//  2course_work_lib_branch_and_bound.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/29/22.
//

#include "2course_work_1_lib.hpp"


using namespace std;

//vector<vector<int>> read_tsp_file(const char* fname);

//int N;
//int nodes;
//std::vector<int> final_path;
//int final_res = INT_MAX;

/* vector<vector<int>> distance_matrix = { {0,83,93,129,133,139,151,169,135,114,110},
                                        {83, 0,40,53,62,64,91, 116,93,84,95},
                                        {93,40, 0,42,42,49,59,81,54,44,58},
                                        {129,53,42, 0,11,11,46,72,65,70,88},
                                        {133,62,42,11, 0, 9,35,61,55,62,82},
                                        {139,64,49,11, 9, 0,39,65,63,71,90},
                                        {151,91,59,46,35,39, 0,26,34,52,71},
                                        {169, 116,81,72,61,65,26, 0,37,59,75},
                                        {135,93,54,65,55,63,34,37, 0,22,39},
                                        {114,84,44,70,62,71,52,59,22, 0,20},
                                        {110,95,58,88,82,90,71,75,39,20, 0} };*/

void graph::copyToFinal(vector<int>& way) {
    int i;
    for (i = 0; i < nodes; i++)
        final_path.push_back(way[i]);
    final_path.push_back(way[0]);
}

int graph::firstMinInRow(int vertex_index) {
    int min = INT_MAX;
    for (int i = 0; i < nodes; i++)
    {
        if (g[vertex_index][i] < min and vertex_index != i) {
            min = g[vertex_index][i];
        }
    }
    return min;
}

int graph::secondMinInRow(int i) {
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

//function that takes as arguments:
//curr_bound -> lower bound of the root node - to co je výš ve stromu
//curr_weight-> stores the weight of the path so far - aktualni cost
//level-> current level while moving in the search space tree - level ve stromu
//curr_pat -> where the solution is being stored, which would later be copied to final_path
//vis -> stores info about which nodes were already visited
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

    int i;
    for (i = 0; i < nodes; i++) {

        vector<int> visitedInPath;
        vector<int> current_path;
        int j;
        for (j = 0; j < nodes; j++) { visitedInPath.push_back(visited[j]); }
        for (j = 0; j < nodes; j++) { current_path.push_back(way[j]); }

        if (g[current_path[level - 1]][i] != 0 && visitedInPath[i] == 0) {
            int temp = current_bound;
            current_weight += g[current_path[level - 1]][i];

            if (level == 1)
                current_bound -= ((firstMinInRow(current_path[level - 1]) +
                    firstMinInRow(i)) / 2);
            else
                current_bound -= ((secondMinInRow(current_path[level - 1]) +
                    firstMinInRow(i)) / 2);

            if (current_bound + current_weight < final_result) {
                current_path[level] = i;
                visitedInPath[i] = 1;
                // call TSPRec for the next level
                TSPRec(current_bound, current_weight, level + 1, current_path, visitedInPath);

            }

            //reset changes if not found better cost in branch at current level
            current_weight -= g[current_path[level - 1]][i];
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
        current_bound += (firstMinInRow(i) + secondMinInRow(i));

    current_bound = round(current_bound / 2);

    visited[0] = 1;
    way[0] = 0;
    TSPRec(current_bound, 0, 1, way, visited);
}
