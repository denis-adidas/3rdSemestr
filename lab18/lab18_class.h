//
// Created by Денис Адидас on 9/27/22.
//

#ifndef LAB18_LAB18_CLASS_H
#define LAB18_LAB18_CLASS_H
#include "iostream"
#include "map"
#include "string"
#include "fstream"
#include <sstream>

template <typename T>
class multiset {
protected:
    int size;
    std::map<T, int> data;
public:

    multiset();
    multiset(T i);
    ~multiset();
    void insert(T val);
    int find(int index);
    void erase(int val);
    template <typename U>
    friend std::ostream& operator<< (std::ostream& os, const multiset<U>& a);
    int get_size();

};

#endif //LAB18_LAB18_CLASS_H
