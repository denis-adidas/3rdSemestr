//дописать поинт и не использовать qsort


#include "iostream"
#include "lab8_class_impl.h"


int main() {

//    char a = 'a';
//    char c = 'c';
//    std::cout << (a < c);

    sorted_array<Point> a(10);

    Point b(1, 5, 3);
    Point c(2, 6, 4);
    a.push(b);
    a.push(c);


//    try {
//        a.erase(4);
//    }
//    catch(char* err) {
//        std::cout << "error" << std::endl;
//    }
for (int i = 0; i < 10; i++)
    std::cout << a[i];

//
}
