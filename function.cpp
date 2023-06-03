// Paydreanne E. Hinton
#include <iostream>

// Function to swap the values of two integers
void swap(int& num1, int& num2) {
    int swap = num1; // swap will store num1
    num1 = num2; // num1 will store num2
    num2 = swap; // num2 will store num1's initial value
}

int main() {
    int num1, num2;

    // Ask the user for input
    std::cout << "Initial value of num1: ";
    std::cin >> num1;

    std::cout << "Initial value of num2: ";
    std::cin >> num2;

    // Call the swap function to swap the values
    swap(num1, num2);

    // Print the swapped values
    std::cout << "\nSwapped value of num1: " << num1;
    std::cout << "\nSwapped value of num2: " << num2;
    
    /*
    1) https://en.cppreference.com/w/cpp/algorithm/swap
    2) https://stackoverflow.com/questions/15672805/c-swapping-pointers
    */
    
    return 0;
}
