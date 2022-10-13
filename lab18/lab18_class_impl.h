//
// Created by Денис Адидас on 9/27/22.
// посчитатать кол-во уникальных слов с помощью мултисета
//
#include "lab18_class.h"

template <class T>
multiset<T>::multiset(T i) {
    size=1;
    data.template emplace(i, 1);
}

template <class T>
multiset<T>::multiset() {
    size=0;
}

template <class T>
multiset<T>::~multiset() {
    data.clear();
}

template <class T>
void multiset<T>::insert(T val) {
    if (data.find(val) != data.end()) {
        data[val]++;
        size++;
    }
    else {
        data.template emplace(val, 1);
        size++;
    }
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

template <typename T>
int multiset<T>::get_size() {
    return data.size();
}


