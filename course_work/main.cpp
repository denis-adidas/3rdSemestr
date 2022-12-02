//
//  main.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/9/22.
//

#include "2course_work_1_lib.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string path = "/Users/denis_adidas/XCode project/2course_work_1/2course_work_1/matrix.txt";

    int n;
//    cout << "Enter a nodes: " << endl;
//    cin >> n;
    graph a(path);
//    a.solve(0, 0);
//    cout << "Nodes: " << n;
    a.TSP();
    a.show_res();
    
    
//    a.dfs(0, 0);
//    a.ShowGraph();
    return 0;
}
