// Paydreanne E. Hinton
#include <iostream>

// Swaps pointer parameter values
void swap(int *num1, int *num2) {
    int swap = *num1; // swap will store num1
    *num1 = *num2; // num1 will store num2
    *num2 = swap; // num2 will store num1's initial value
}

int main() {
    // variables
    int num1, num2;

    std::cout << "Initial value of num1: ";
    std::cin >> num1; // takes num1 integer value

    std::cout << "Initial value of num2: ";
    std::cin >> num2; // takes num2 integer value

    swap(&num1, &num2); // call memory address of num1 and num2

    std::cout << "\nSwapped value of num1: " << num1; // print new value of num1
    std::cout << "\nSwapped value of num2: " << num2; // print new value of num2
    
    /*
    1) https://en.cppreference.com/w/cpp/algorithm/swap
    2) https://stackoverflow.com/questions/15672805/c-swapping-pointers
    */

    return 0;
}
