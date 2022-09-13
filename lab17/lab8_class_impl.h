//
// Created by Денис Адидас on 9/6/22.
//

#include "lab8_class.h"


Point::Point(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
}
bool Point::operator<(Point& p) {
    if (this == &p) return false;
    return this->x < p.x && this->y < p.y && this->z < p.z;

}

template <typename T>
int compare(const void* x1, const void* x2) {
    return (*(T*)x2 < *(T*)x1);
}

template <typename T>
sorted_array<T>::sorted_array(size_t i) {
    size = 0;
    capacity = i;
    data = new T(capacity);
}

template <typename T>
sorted_array<T>::~sorted_array() { delete [] data; }

template <typename T>
sorted_array<T>::sorted_array(sorted_array& a) {
    size = a.size;
    capacity = a.capacity;
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }
}

template <typename T>
T& sorted_array<T>::operator[](size_t i) {
    return data[i];
};

//дописать исключения
template <typename T>
T& sorted_array<T>::at(T i) {
    if ((i >= 0) && (i <= size))
        return data[i];
    else {
        throw std::invalid_argument("Invalid index");
    }
}

//дописать исключения
template <typename T>
void sorted_array<T>::erase(size_t i) {
    if ((i > 0) && (i < size)) {
        int j = 0;
        for (j = i; j < size; j++) data[i] = data[i + 1];
        size--;
    }
    else {
        throw std::invalid_argument("Invalid index");
    }
};

//дописать исключения
template <typename T>
void sorted_array<T>::push(T i) {
    if (size < capacity) {
        data[size++] = i;
        qsort(data, size, sizeof(T), compare<T>);
        size++;
    }
    else {
        throw std::invalid_argument("Array full");
    }
}

template <typename T>
void sorted_array<T>::operator=(sorted_array& a) {
    if (&a == *this) return *this;
    delete [] data;
    size = a.size;
    capacity = a.capacity;
    data = new T(size);
    for (int i = 0; i < size ; i++) {
        data[i] = a.data[i];
    }
    return *this ;
}


