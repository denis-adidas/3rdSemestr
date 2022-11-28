//
//  2course_work_1_lib.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/16/22.
//

#include "2course_work_1_lib.hpp"
#include "cstdlib"

using namespace std;
    
void graph::solve(int source, int current) {
    
    if ((current == 0) && (sum() == nodes)) {
        way.push_back(source);
        if (distance < min_distance){
            min_distance = distance;
            cout << "Distance: " << min_distance << endl;
            return;
        }
    }
    else if (visited[current] == 1) {
        visited[current-1] = 0;
        way.pop_back();
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
                //visited[current] = 0;
                
            }
        
    }
}

//
//void graph::solve(int source, int current) {
//
//
//}
//int graph::path(int current)
//{
//    int i, nc = INT_MAX;
//    int min = INT_MAX;
//    int kmin;
//
//    for (i = 0; i < nodes; i++)
//    {
//        if ((g[current][i] != 0) && (!visited[i]))
//            if (g[current][i] < min)
//            {
//                min = g[current][i];
//                kmin = g[current][i];
//                nc = i;
//            }
//    }
//
//    distance += kmin;
//
//    return nc;
//}
//
//void graph::minimal(int current)
//{
//    int nmiasto = 0;
//    visited[current] = 1;
//
//
//    nmiasto = path(current);
//
//    if (nmiasto == INT_MAX)
//    {
//        nmiasto = 0;
//        cout << nmiasto + 1 << endl;
//        distance += g[current][nmiasto];
//
//        return;
//    }
//
//    minimal(nmiasto);
//}
