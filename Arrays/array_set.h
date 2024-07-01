#ifndef LAB2_3_ARRAY_SET_H
#define LAB2_3_ARRAY_SET_H

#include "array_sequence.h"
#include "../list_sequence/list_sequence.h"

#include <stdexcept>


template<class T>
class ArraySet {
private:
    ArraySequence<T> set;
public:
    void Prepend(T element);
    void Append(T element);
    void Insert(T element, int index);
    void Swap(int index1, int index2);
    void Replace(T element, int index);
    T GetElement(int index) const;
    int GetSize() const;
    bool Equal(ArraySet<T>& copy);
    bool Contained(T element);
    bool IsItSub(ArraySet<T>& copy);

    template<typename Func>
    ArraySet<T> Map(Func func);

    template<typename Func>
    ArraySet<T> Where(Func func);

    template<typename Func>
    T Reduce(Func func);

    ArraySet<T> Intersection(ArraySet<T>& c1);
    ArraySet<T> Union(ArraySet<T>& c1);
    ArraySet<T> Subtraction(ArraySet<T>& c2);


};

#include "array_set_impl.h"
#endif // LAB2_3_ARRAY_SET_H
