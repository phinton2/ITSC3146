// Paydreanne E. Hinton
#include <iostream>

using namespace std;

int main() {
    int myInts[4];
    for (int i = 0; i < 4; i++) { // add integers to myInts array
        cin >> myInts[i];
    }
    int *my_ptrs[4];
    for (int i = 0; i < 4; i++) { // assign memory address of myInts to myPtrs to assign values
        my_ptrs[i] = &myInts[i];
    }
    
    cout << "\nCurrent values in myInts: ";
    for (int i = 0; i < 4; i++) { // displays unordered values of myInts
        cout << myInts[i] << " ";
    }
    cout << "\nCurrent values in my_ptrs: ";
    for (int i = 0; i < 4;i++) { // displays unordered values of my_ptrs
        cout << *my_ptrs[i] << " ";
    }
    
    cout << "\nSorted values of my_ptrs (least to greatest): ";
    for (int i = 0; i < 4; i++) { // pushes least integers to leftmost side and greatest integers to rightmost side
        for (int j = 0; j < 4 - i - 1; j++) { // 
            if (*my_ptrs[j] > *my_ptrs[j + 1]) {
                int* temp = my_ptrs[j]; // assign my_ptrs values to pointer temp variable
                my_ptrs[j] = my_ptrs[j + 1]; // moves pointer value on right (j+1) to left side (j)
                my_ptrs[j + 1] = temp; // assigns pointer temp value to "right" value in my_ptrs
            }
        }
    }
    
    for (int i = 0; i < 4;i++) { // prints ordered version of my_ptrs
        std::cout << *my_ptrs[i] << " ";
    }
    cout << "\nValues of myInt array (should remain unchanged!): ";
    for (int i = 0; i < 4;i++) { // displays unchanged order of values in myInts
        std::cout << myInts[i] << " ";
    }
}
