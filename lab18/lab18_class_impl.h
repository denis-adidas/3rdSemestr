//
// Created by Денис Адидас on 9/27/22.
//
#include "lab18_class.h"

template <class T>
multiset<T>::multiset(T i) {
    size++;
    data.template emplace(i, 1);
}
template <class T>
multiset<T>::~multiset() {
    data.clear();
}

template <class T>
void multiset<T>::insert(int val) {
    if (data.find(val) != data.end()) {
        data[val]++;
        size++;
    }
    else
        data.template emplace(val, 1);
}

template <class T>
void multiset<T>::erase(int val) {
    if (data.find(val) != data.end()) {
        if (data[val] > 0) {
            data[val]--;
            size--;
        }
    }
    else {
        throw std::invalid_argument("No value at such index");
    }
}

template <class T>
int multiset<T>::find(int index) {
    return data.find(index)->first;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const multiset<T>& a){
    for(auto it = a.data.begin(); it != a.data.end(); ++it)
    {
        int i = 0;
        while (i < it->second) {
            os << it->first << std::endl;
            i++;

        }
    }
    return os;
};





