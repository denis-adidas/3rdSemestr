//дописать поинт и не использовать qsort


#include "iostream"
#include "lab8_class_impl.h"



int main() {

    sorted_array<char> a(10);
    a.push('c');
    a.push('a');
    Point a;
    try {
        a.erase(4);
    }
    catch(char* err) {
        std::cout << "error" << std::endl;
    }

    std::cout << a[2];


}
