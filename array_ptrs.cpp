#include <iostream>

using namespace std;

int main() {
    // Instruction 1
    int myInts[4];
    for (int i = 0; i < 4; i++) {
        cin >> myInts[i];
    }
    int *my_ptrs[4];
    for (int i = 0; i < 4; i++) {
        my_ptrs[i] = &myInts[i];
    }
    
    cout << "\nCurrent values in myInts: ";
    for (int i = 0; i < 4; i++) {
        cout << myInts[i] << " ";
    }
    cout << "\nCurrent values in my_ptrs: ";
    for (int i = 0; i < 4;i++) {
        cout << *my_ptrs[i] << " ";
    }
}
