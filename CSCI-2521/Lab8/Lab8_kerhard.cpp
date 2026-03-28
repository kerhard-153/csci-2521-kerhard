/**
 * @file Lab8_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-03-28
 * @brief Demonstrates stack vs heap memory and the use of pointers and references.
 */

#include <iostream>

using namespace std;

/**
 * @brief Entry point for the memory exploration program.
 * Explains the difference between stack and heap memory allocation by
 * demonstrating how pointers and references relate to memory addresses.
 *
 * @return 0 to indicate success.
 */

int main() {

    int stackInt = 10;

    int* heapInt = new int(20);

    int* ptrToStack = &stackInt;

    int& refToStack = stackInt;

    cout << "Stack Variable (stackInt):" << endl;
    cout << "  Value: " << stackInt << endl;
    cout << "  Address: " << &stackInt << endl << endl;

    cout << "Heap Variable (heapInt):" << endl;
    cout << "  Value: " << *heapInt << endl;
    cout << "  Address: " << heapInt << endl << endl;

    cout << "Pointer to Stack (ptrToStack):" << endl;
    cout << "  Value Pointed To: " << *ptrToStack << endl;
    cout << "  Address Stored: " << ptrToStack << endl << endl;

    cout << "Reference to Stack (refToStack):" << endl;
    cout << "  Value Referred To: " << refToStack << endl;
    cout << "  Address: " << &refToStack << endl << endl;

    delete heapInt;


	return 0;
}