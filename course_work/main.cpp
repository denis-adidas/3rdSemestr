//
//  main.cpp
//  2course_work_1
//
//  Created by Денис Адидас on 11/9/22.
//

#include "2course_work_1_lib.hpp"

using namespace std;



int main(int argc, const char * argv[]) {
    string path;


    cin >> path;

    graph a(path);
    graph b(path);
    a.print_graph();

    a.greedy(0);

    b.TSP(0);

    return 1;
}
