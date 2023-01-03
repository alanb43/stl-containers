#include "Vector.h"
#include <iostream>

int main() {
    Vector<int> my_Vec; // default
    Vector<int> my_Vec2(size_t(10)); // reserving space
    Vector<int> my_Vec3(size_t(5),43); // reserve + initialize with value
    Vector<int> my_Vec4(my_Vec3); // copy constructor

    std::cout << my_Vec3[size_t(2)] << std::endl; // should be 43
    my_Vec4[size_t(0)] = 100; // changing copied object
    // demonstrating that deep copy is working
    std::cout << "Original: " << my_Vec3[size_t(0)] << std::endl; // 43
    std::cout << "Modified: " << my_Vec4[size_t(0)] << std::endl; // 100

    return 0;
}
