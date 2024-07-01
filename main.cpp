#include <iostream>
#include <limits>
#include "Checker/errors.h"
#include "Arrays/array_set.h"
#include "Tests/tests_dynamic_array.h"
#include "Tests/tests_array_sequence.h"
#include "Tests/tests_linked_list.h"
#include "Tests/tests_list_sequence.h"
#include "Tests/tests_array_set.h"
#include "classes/Chars.h"
#include "Arrays/MutDynamicArray.h"


using namespace std;
int getInputInRange(int min, int max) {
    int choice;
    while (true) {
        cout << "Выберите действие (" << min << "-" << max << "): ";
        cin >> choice;
        if (cin.fail()) { // Проверка на некорректный ввод
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите целое число.\n";
        } else if (choice < min || choice > max) { // Проверка на допустимый диапазон
            cout << "Ошибка: выберите число из указанного диапазона.\n";
        } else {
            break;
        }
    }
    return choice;
}

void testChars() {
    Chars charObj;
    int choice;
    string input;

    while (true) {
        cout << "\n--- Тестирование класса Chars ---\n";
        cout << "1. Ввести строку\n";
        cout << "2. Вывести строку\n";
        cout << "3. Сравнить с другой строкой\n";
        cout << "4. Вернуться в главное меню\n";

        choice = getInputInRange(1, 4);
        Chars other;
        switch (choice) {
            case 1:
                cout << "Введите строку: ";
                cin >> input;
                charObj = Chars(input);
                cout << "Строка успешно установлена.\n";
                break;
            case 2:
                cout << "Текущая строка: " << charObj << endl;
                break;
            case 3:
                cout << "Введите строку для сравнения: ";
                cin >> input;
                other = Chars(input);
                if (charObj == other) {
                    cout << "Строки равны.\n";
                } else {
                    cout << "Строки не равны.\n";
                }
                break;
            case 4:
                return;
        }
    }
}

void testComplexNumber() {
    ComplexNumber complexObj;
    int choice;
    double re, im;

    while (true) {
        cout << "\n--- Тестирование класса ComplexNumber ---\n";
        cout << "1. Ввести комплексное число\n";
        cout << "2. Вывести комплексное число\n";
        cout << "3. Сравнить с другим комплексным числом\n";
        cout << "4. Вернуться в главное меню\n";

        choice = getInputInRange(1, 4);
        ComplexNumber other;
        switch (choice) {
            case 1:
                cout << "Введите действительную часть: ";
                cin >> re;
                cout << "Введите мнимую часть: ";
                cin >> im;
                complexObj = ComplexNumber(re, im);
                cout << "Комплексное число успешно установлено.\n";
                break;
            case 2:
                cout << "Текущее комплексное число: " << complexObj << endl;
                break;
            case 3:

                cout << "Введите действительную часть для сравнения: ";
                cin >> re;
                cout << "Введите мнимую часть для сравнения: ";
                cin >> im;
                other = ComplexNumber(re, im);
                if (complexObj == other) {
                    cout << "Комплексные числа равны.\n";
                } else {
                    cout << "Комплексные числа не равны.\n";
                }
                break;
            case 4:
                return;
        }
    }
}

void testDynamicArray() {
    DynamicArray<int> dynamicArray;
    int choice, index, element;

    while (true) {
        cout << "\n--- Тестирование класса DynamicArray ---\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Получить элемент по индексу\n";
        cout << "3. Изменить элемент по индексу\n";
        cout << "4. Вывести размер и ёмкость массива\n";
        cout << "5. Вернуться в главное меню\n";

        choice = getInputInRange(1, 6);
        int result;
        switch (choice) {
            case 1:
                cout << "Введите элемент для добавления: ";
                cin >> element;
                dynamicArray.Append(element);
                cout << "Элемент успешно добавлен.\n";
                break;
            case 2:
                cout << "Введите индекс элемента: ";
                cin >> index;
                result = dynamicArray.GetElement(index);
                cout << "Элемент по индексу " << index << ": " << result << endl;

                break;
            case 3:
                cout << "Введите индекс элемента: ";
                cin >> index;
                cout << "Введите новое значение элемента: ";
                cin >> element;
                dynamicArray.Replace(element, index);
                cout << "Элемент успешно изменён.\n";
                break;
            case 4:
                cout << "Размер массива: " << dynamicArray.GetSize() << endl;
                cout << "Ёмкость массива: " << dynamicArray.GetCapacity() << endl;
                break;
            case 5:
                return;
        }
    }
}

void testLinkedList() {
    LinkedList<int> linkedList;
    int choice, index, element;

    while (true) {
        cout << "\n--- Тестирование класса LinkedList ---\n";
        cout << "1. Добавить элемент в начало\n";
        cout << "2. Добавить элемент в конец\n";
        cout << "3. Вставить элемент по индексу\n";
        cout << "4. Получить элемент по индексу\n";
        cout << "5. Изменить элемент по индексу\n";
        cout << "6. Вывести размер списка\n";
        cout << "7. Вернуться в главное меню\n";

        choice = getInputInRange(1, 8);
        int result;
        switch (choice) {
            case 1:
                cout << "Введите элемент для добавления в начало: ";
                cin >> element;
                linkedList.Prepend(element);
                cout << "Элемент успешно добавлен в начало.\n";
                break;
            case 2:
                cout << "Введите элемент для добавления в конец: ";
                cin >> element;
                linkedList.Append(element);
                cout << "Элемент успешно добавлен в конец.\n";
                break;
            case 3:
                cout << "Введите индекс элемента для вставки: ";
                cin >> index;
                cout << "Введите элемент для вставки: ";
                cin >> element;
                linkedList.Insert(element, index);
                cout << "Элемент успешно вставлен по индексу " << index << ".\n";
                break;
            case 4:
                cout << "Введите индекс элемента: ";
                cin >> index;
                result = linkedList.GetElement(index);
                cout << "Элемент по индексу " << index << ": " << result << endl;

                break;
            case 5:
                cout << "Введите индекс элемента для изменения: ";
                cin >> index;
                cout << "Введите новое значение элемента: ";
                cin>> element;
                linkedList.Replace(element, index);
                cout << "Элемент успешно изменён по индексу " << index << ".\n";
                break;
            case 6:
                cout << "Размер списка: " << linkedList.GetSize() << endl;
                break;
            case 7:
                return;
        }
    }
}

void testListSequence() {
    ListSequence<int> listSequence;
    int choice, index, element;
    ListSequence<int> subsequence;
    while (true) {
        cout << "\n--- Тестирование класса ListSequence ---\n";
        cout << "1. Добавить элемент в начало\n";
        cout << "2. Добавить элемент в конец\n";
        cout << "3. Вставить элемент по индексу\n";
        cout << "4. Получить элемент по индексу\n";
        cout << "5. Изменить элемент по индексу\n";
        cout << "6. Вывести размер последовательности\n";
        cout << "7. Получить подпоследовательность\n";
        cout << "8. Вернуться в главное меню\n";

        choice = getInputInRange(1, 10);
        int result;
        ListSequence<int> other;
        switch (choice) {
            case 1:
                cout << "Введите элемент для добавления в начало: ";
                cin >> element;
                listSequence.Prepend(element);
                cout << "Элемент успешно добавлен в начало.\n";
                break;
            case 2:
                cout << "Введите элемент для добавления в конец: ";
                cin >> element;
                listSequence.Append(element);
                cout << "Элемент успешно добавлен в конец.\n";
                break;
            case 3:
                cout << "Введите индекс элемента для вставки: ";
                cin >> index;
                cout << "Введите элемент для вставки: ";
                cin >> element;
                listSequence.Insert(element, index);
                cout << "Элемент успешно вставлен по индексу " << index << ".\n";
                break;
            case 4:
                cout << "Введите индекс элемента: ";
                cin >> index;
                result = listSequence.GetElement(index);
                cout << "Элемент по индексу " << index << ": " << result << endl;
                break;
            case 5:
                cout << "Введите индекс элемента для изменения: ";
                cin >> index;
                cout << "Введите новое значение элемента: ";
                cin >> element;
                listSequence.Replace(element, index);
                cout << "Элемент успешно изменён по индексу " << index << ".\n";
                break;
            case 6:
                cout << "Размер последовательности: " << listSequence.GetSize() << endl;
                break;
            case 7:
                int a, b;
                cout << "Введите начальный индекс подпоследовательности: ";
                cin >> a;
                cout << "Введите конечный индекс подпоследовательности: ";
                cin >> b;
                subsequence = listSequence.GetSub(a, b);
                cout << "Подпоследовательность с индексами от " << a << " до " << b << ": ";
                for (int i = 0; i < subsequence.GetSize(); ++i) {
                    cout << subsequence.GetElement(i) << " ";
                }
                cout << endl;

                break;
            case 8:
                return;
        }
    }
}

void testArraySequence() {
    cout << "Testing ArraySequence<int>...\n";
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ArraySequence<int> seq(size, arr);
    cout << "Size of sequence: " << seq.GetSize() << endl;
    cout << "First element: " << seq.GetFirst() << endl;
    cout << "Last element: " << seq.GetLast() << endl;
    cout << "Element at index 2: " << seq.GetElement(2) << endl;

    seq.Append(6);
    cout << "After appending 6, size is: " << seq.GetSize() << endl;
    cout << "Last element now: " << seq.GetLast() << endl;

    seq.Prepend(0);
    cout << "After prepending 0, size is: " << seq.GetSize() << endl;
    cout << "First element now: " << seq.GetFirst() << endl;

    seq.Replace(100, 3);
    cout << "After replacing element at index 3 with 100: " << seq.GetElement(3) << endl;

    cout << "Sequence elements: ";
    for (int i = 0; i < seq.GetSize(); ++i) {
        cout << seq.GetElement(i) << " ";
    }
    cout << endl;

    cout << "Testing subsequence from index 1 to 3...\n";
    ArraySequence<int> subseq = seq.GetSub(1, 3);
    cout << "Subsequence size: " << subseq.GetSize() << endl;
    cout << "Subsequence elements: ";
    for (int i = 0; i < subseq.GetSize(); ++i) {
        cout << subseq.GetElement(i) << " ";
    }
    cout << endl;

    cout << "ArraySequence<int> tests completed.\n\n";
}

void testArraySet() {
    cout << "Testing ArraySet<int>...\n";
    ArraySet<int> set;

    set.Append(1);
    set.Append(2);
    set.Append(3);
    set.Append(4);
    set.Append(5);

    cout << "Size of set: " << set.GetSize() << endl;

    cout << "Elements in set: ";
    for (int i = 0; i < set.GetSize(); ++i) {
        cout << set.GetElement(i) << " ";
    }
    cout << endl;

    ArraySet<int> copy;
    copy.Append(3);
    copy.Append(4);
    copy.Append(5);

    cout << "Is copy a subset of set? " << (set.IsItSub(copy) ? "Yes" : "No") << endl;

    ArraySet<int> intersection = set.Intersection(copy);
    cout << "Intersection of set and copy: ";
    for (int i = 0; i < intersection.GetSize(); ++i) {
        cout << intersection.GetElement(i) << " ";
    }
    cout << endl;

    ArraySet<int> unionSet = set.Union(copy);
    cout << "Union of set and copy: ";
    for (int i = 0; i < unionSet.GetSize(); ++i) {
        cout << unionSet.GetElement(i) << " ";
    }
    cout << endl;

    ArraySet<int> subtraction = set.Subtraction(copy);
    cout << "Subtraction of set by copy: ";
    for (int i = 0; i < subtraction.GetSize(); ++i) {
        cout << subtraction.GetElement(i) << " ";
    }
    cout << endl;

    cout << "ArraySet<int> tests completed.\n\n";
}

void testMutDynamicArray() {
    cout << "Testing MutDynamicArray<int>...\n";

    // Создание объекта MutDynamicArray
    MutDynamicArray<int> array;
    array.Append(1).Append(2).Append(3).Append(4).Append(5);

    cout << "Size of array: " << array.GetSize() << endl;

    cout << "Elements in array: ";
    for (int i = 0; i < array.GetSize(); ++i) {
        cout << array.GetElement(i) << " ";
    }
    cout << endl;

    array.Prepend(0);
    cout << "After prepending 0, elements in array: ";
    for (int i = 0; i < array.GetSize(); ++i) {
        cout << array.GetElement(i) << " ";
    }
    cout << endl;

    array.Replace(100, 3);
    cout << "After replacing element at index 3 with 100, elements in array: ";
    for (int i = 0; i < array.GetSize(); ++i) {
        cout << array.GetElement(i) << " ";
    }
    cout << endl;

    array.Swap(0, 5);
    cout << "After swapping elements at indices 0 and 5, elements in array: ";
    for (int i = 0; i < array.GetSize(); ++i) {
        cout << array.GetElement(i) << " ";
    }
    cout << endl;

    cout << "MutDynamicArray<int> tests completed.\n\n";
}

void tests(){
    start_DA_tests();
    start_AS_tests();
    start_LL_tests();
    start_LS_tests();
    tests_array_set();
}

template<typename T>
void prints(ArraySet<T> to_print){
    if(to_print.GetSize() == 0){
        return;
    }
    for(int i = 0; i < to_print.GetSize(); i++){
        cout << to_print.GetElement(i) << " ";
    }
    cout << '\n';
}
template<typename T>
void prints(DynamicArray<T> to_print){
    for(int i = 0; i < to_print.GetSize(); i++){
        cout << to_print.GetElement(i) << " ";
    }
    cout << '\n';
}

void displayMenu() {
    cout << "===== Menu =====\n";
    cout << "0. Tests\n";
    cout << "1. Test Chars\n";
    cout << "2. Test ComplexNumber\n";
    cout << "3. Test DynamicArray\n";
    cout << "4. Test LinkedList\n";
    cout << "5. Test ListSequence\n";
    cout << "6. Test ArraySequence\n";
    cout << "7. Test ArraySet\n";
    cout << "8. Test MutDynamicArray\n";
    cout << "9. Exit\n";
    cout << "================\n";
}

int main() {
    int choice;
    ArraySet<int> test5;
    ArraySet<int> test6;
    ArraySet<int> test7;
    int a;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                tests();


                for(int i = 0; i< 15; i++){
                    test5.Append(i);
                }
                cout << "set: ";
                prints(test5);
                cout << "set where with bool(x) = 1 if x % 2 == 0: ";
                test6 = test5.Where([](int x){return (x % 2 == 0);});
                prints(test6);
                cout << "set map with f(x) = x * x: ";
                test7 = test5.Map([](int x){return (x * x);});
                prints(test7);
                cout << "set reduce with sum: ";
                a = test5.Reduce([](int x){return x;});
                cout << a << "\n";

                try{
                    int number;
                    cin >> number;
                    int test_number = test5.GetElement(number);
                    cout << test_number << endl;
                }
                catch (IndexOutOfRange* e){
                    cout << e->IndexErrorList(1) << endl;
                    delete e;
                }

                try{
                    int number;
                    cin >> number;
                    int test_number = test5.GetElement(number);
                    cout << test_number << endl;
                }
                catch (IndexOutOfRange* e){
                    cout << e->IndexErrorList(1) << endl;
                    delete e;
                }
                break;
            case 1:
                testChars();
                break;
            case 2:
                testComplexNumber();
                break;
            case 3:
                testDynamicArray();
                break;
            case 4:
                testLinkedList();
                break;
            case 5:
                testListSequence();
                break;
            case 6:
                testArraySequence();
                break;
            case 7:
                testArraySet();
                break;
            case 8:
                testMutDynamicArray();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}