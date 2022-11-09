//
//  main.cpp
//  lab19
//
//  Created by Денис Адидас on 11/8/22.
//

/*
    Дано n предметов, каждый имеет порядковый номер
    Написать алгоритм, который выводит все перестановки
 
 */

#include <iostream>
#include "vector"

using namespace::std;

void v_out(vector<int>& a) {
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}

bool my_nextPermutation(vector<int>& s, int n) {
    int i = n - 1;
    while (s[i-1] >= s[i]) {
        if (--i == 0)
            return false;
    }
    int j = n - 1;
    while (j > i && s[j] <= s[i-1])
        j--;
    swap(s[i-1], s[j]);
    reverse(s.begin() + i, s.end());
    return true;
}

void foo(int n, int c, vector<int>& j){
    if (c==n){
        v_out(j);
        return;
    }
    for(int i = c;i<n;i++){
        swap(j[i],j[c]);
        foo(n,c+1,j);
        swap(j[i],j[c]);
    }
}


int main (int argc, const char * argv[]) {
    vector<int> elem = {2, 3, 1};
//    v_out(elem);
    sort(elem.begin(), elem.end());
//    v_out(elem);
    while (my_nextPermutation(elem, elem.size()))
           v_out(elem);
    return 0;
}
