#ifndef LAB2_3_ARRAY_SET_IMPL_H
#define LAB2_3_ARRAY_SET_IMPL_H
#include "array_set.h"
template<class T>
void ArraySet<T>::Prepend(T element) {
    if(!Contained(element)){
        set.Prepend(element);
    }
}

template<class T>
void ArraySet<T>::Append(T element) {
    if(!Contained(element)){
        set.Append(element);
    }
}

template<class T>
void ArraySet<T>::Insert(T element, int index) {
    if(!Contained(element)){
        set.Insert(element, index);
    }
}

template<class T>
void ArraySet<T>::Swap(int index1, int index2) {
    set.Swap(index1, index2);
}

template<class T>
void ArraySet<T>::Replace(T element, int index) {
    set.Replace(element, index);
}

template<class T>
T ArraySet<T>::GetElement(int index) const {
    return set.GetElement(index);
}

template<class T>
int ArraySet<T>::GetSize() const {
    return set.GetSize();
}

template<class T>
bool ArraySet<T>::Equal(ArraySet<T>& copy) {
    if(set.GetSize() == copy.set.GetSize()){
        for(int i = 0; i < copy.GetSize(); i++){
            if(!(Contained(copy.GetElement(i)) && copy.Contained(copy.GetElement(i)))){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool ArraySet<T>::Contained(T element) {
    for(int i = 0; i < set.GetSize(); i++){
        if(element == GetElement(i)){
            return true;
        }
    }
    return false;
}

template<class T>
bool ArraySet<T>::IsItSub(ArraySet<T>& copy) {
    if(GetSize() < copy.GetSize()){
        return false;
    }
    for(int i = 0; i < copy.GetSize(); i++){
        if(!(Contained(copy.GetElement(i)) && copy.Contained(copy.GetElement(i)))){
            return false;
        }
    }
    return true;
}
//
template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Map(Func func) {
    ArraySet<T> returned_class;
    for(int i = 0; i < GetSize(); i++){
        returned_class.Append(func(GetElement(i)));
    }
    return returned_class;
}

template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Where(Func func) {
    ArraySet<T> returned_class;
    for(int i = 0; i < GetSize(); i++){
        if(func(GetElement(i))){
            returned_class.set.Append(GetElement(i));
        }
    }
    return returned_class;
}

template<class T>
template<typename Func>
T ArraySet<T>::Reduce(Func func) {
    T temp = GetElement(0);
    for(int i = 0; i < GetSize(); i++){
        temp = temp + func(GetElement(i));
    }
    return temp;
}

template<class T>
ArraySet<T> ArraySet<T>::Intersection(ArraySet<T>& c1) {
    ArraySet<T> return_class;
    int temp_size = c1.GetSize() + GetSize();
    int size_c1, size_c2;
    size_c1 = c1.GetSize();
    size_c2 = GetSize();
    int real_size = 0;
    ArraySequence<T> temp_data;
    for(int i = 0; i < size_c1; i++){
        for(int j = 0; j < size_c2; j++){
            if(c1.GetElement(i) == GetElement(j)){
                if(!temp_data.IsContained(GetElement(j))){
                    temp_data.Append(GetElement(j));
                }
            }
        }
    }
    for(int i = 0; i < temp_data.GetSize(); i++){
        if(!return_class.Contained(temp_data.GetElement(i))){
            return_class.Append(temp_data.GetElement(i));
        }
    }
    return return_class;
}

template<class T>
ArraySet<T> ArraySet<T>::Union(ArraySet<T>& c1) {
    ArraySet<T> return_class;
    ArraySequence<T> temp = ArraySequence<T>(c1.set);
    temp.Concat(set);
    for(int i = 0; i < temp.GetSize(); i++){
        if(!return_class.Contained(temp.GetElement(i))){
            return_class.Append(temp.GetElement(i));
        }
    }
    return return_class;
}

template<class T>
ArraySet<T> ArraySet<T>::Subtraction(ArraySet<T>& c2) {
    ArraySet<T> returned_class;
    for(int i = 0; i < GetSize(); i++){
        if(!(c2.Contained(GetElement(i)))){
            returned_class.Append(GetElement(i));
        }
    }
    return returned_class;
}
#endif
