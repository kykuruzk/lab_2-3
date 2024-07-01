#ifndef ARRAY_SET_TESTS_H
#define ARRAY_SET_TESTS_H
#include "cassert"
#include "../Arrays/array_set.h"


void tests_array_set(){
    ArraySet<int> test1;  // 2 3 5
    ArraySet<int> test2;  // 5 2 3
    ArraySet<int> test3;
    ArraySet<int> test4;
    ArraySet<int> test5;
    test1.Append(2);
    test1.Append(3);
    test1.Append(5);
    test2.Append(5);
    test2.Append(2);
    test2.Append(3);
    assert(test1.Equal(test2));
    assert((test1.Union(test2)).Equal(test2));
    test2.Append(10); // 2 3 5 10
    assert(test2.Contained(10));
    test1.Append(10);
    test4 = test1.Subtraction(test2);
    assert(test4.Equal(test5));
};

#endif