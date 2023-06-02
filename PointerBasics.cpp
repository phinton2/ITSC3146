#include <iostream>

using namespace std;

int main() {
    // Instruction 1
    int myInt = 15;
    int* myPointer = &myInt;
    
    // Instruction 2
    cout << "Memory address of myInt: " << &myInt; // memory address of myInt
    cout << "\nMemory adress of myPointer: " << myPointer; // memory address of myPointer
    cout << "\nValue of myInt: " << myInt; // value of myInt
    cout << "\nValue of myPointer: " << *myPointer; // value of myPointer
    cout << "\nValue pointed to by myPointer: " << *myPointer; // value pointed to by myPointer
    
    // Instruction 3
    myInt = 10; // changes value from 15 to 10
    cout << "\n\nMemory address of myInt: " << &myInt; // memory address of myInt
    cout << "\nValue of myPointer: " << *myPointer;// value of myPointer
    cout << "\nValue of myInt: " << myInt; // value of myInt
    cout << "\nValue pointed to by myPointer: " << *myPointer; // value pointed to by myPointer
}
