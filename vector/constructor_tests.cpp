#include "Vector.h"
#include <iostream>
#include <cassert>

using std::cout, std::endl;

int main() {
    cout << "running constructor tests" << endl;
    Vector<int> my_Vec; // default
    Vector<int> my_Vec2(size_t(10)); // reserving space
    Vector<int> my_Vec3(size_t(5),43); // reserve + initialize with value
    Vector<int> my_Vec4(my_Vec3); // copy constructor

    assert(my_Vec3[size_t(2)] == 43);
    my_Vec4[size_t(0)] = 100; // changing copied object
    // demonstrating that deep copy is working
    assert(my_Vec3[size_t(0)] == 43);
    assert(my_Vec4[size_t(0)] == 100);

    Vector<int> my_Vec5(std::move(my_Vec4)); // move constructor
    assert(my_Vec4.empty());
    assert(my_Vec5.size() == 5);
    assert(my_Vec5[size_t(0)] == 100);

    Vector<int> my_Vec6 {1,2,3,4}; // initializer list constructor
    assert(my_Vec6.size() == 4);

    cout << "constructor tests passed" << endl;
    return 0;
}
