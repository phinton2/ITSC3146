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
    
    cout << "\nSorted values of my_ptrs (least to greatest): ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (*my_ptrs[j] > *my_ptrs[j + 1]) {
                int* temp = my_ptrs[j];
                my_ptrs[j] = my_ptrs[j + 1];
                my_ptrs[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < 4;i++) {
        std::cout << *my_ptrs[i] << " ";
    }
    cout << "\nOld myInt array (should remain unchanged!)";
    for (int i = 0; i < 4;i++) {
        std::cout << myInts[i] << " ";
    }
}
