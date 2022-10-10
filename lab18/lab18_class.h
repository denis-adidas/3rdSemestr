//
// Created by Денис Адидас on 9/27/22.
//

#ifndef LAB18_LAB18_CLASS_H
#define LAB18_LAB18_CLASS_H
#include "iostream"
#include "map"

template <typename T>
class multiset {
protected:
    int size;
    std::map<T, int> data;
public:

    multiset(T i);
    ~multiset();
    void insert(int val);
    int find(int index);
    void erase(int val);
    template <typename U>
    friend std::ostream& operator<< (std::ostream& os, const multiset<U>& a);

};

#endif //LAB18_LAB18_CLASS_H
