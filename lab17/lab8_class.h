//
// Created by Денис Адидас on 9/6/22.
//

#ifndef LAB17_LAB8_CLASS_H
#define LAB17_LAB8_CLASS_H
#include "iostream"
#include "cstdlib"

class Point {
protected:
    int x;
    int y;
    int z;
public:
    Point();
    Point(int a, int b, int c);
    bool operator<(Point& p);
    friend std::ostream& operator <<( std::ostream& os, Point a) {
        std::cout << a.x << a.y << a.z << std::endl;
        return os;
    }
};




template <class T>
class sorted_array {
protected:
    size_t size;
    int capacity;
    T* data;
public:
    sorted_array(size_t i);
    ~sorted_array();
    sorted_array(sorted_array& a);
    T& operator[](size_t i);
    void push(T i);
    void erase(size_t i);
    T& at(T i);
    void operator=(sorted_array& a);


};


#endif //LAB17_LAB8_CLASS_H
