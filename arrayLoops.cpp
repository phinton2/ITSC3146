#include <iostream>

using namespace std;

int main() {
    // 1) create input for 10 integers to be placed in array "arr"
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    
    // 2) print array in order of entry
    cout << "\nPrinting array in order: ";
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    
    // 3) print array in reversed order of entry
    cout << "\nPrinting array in reverse order: ";
    for (int j = 0; j < 10; j++) {
        cout << arr[9-j] << " ";
    }
    
    // 4) print array integers in least to greatest order
    cout << "\nPrinting array in order from least to greatest number: ";
    int temp = 0;
    while (temp < (sizeof(arr)/sizeof(*arr))) { // while temp is less than the length of arr
       for (int i = temp + 1; i < (sizeof(arr)/sizeof(*arr)); i++) {
           if (arr[temp] > arr[i]) { // if integer to left (temp will be either on/closest to index 0) is greater than integer to right side of it (i will be directly "right" next to temp) ...
               int temp2 = arr[temp]; // store value of temp index value in "temp2"
               arr[temp] = arr[i]; // store value of i index value in temp index; this "erases" the original value of temp allowing it to switch places with the lesser i index value
               arr[i] = temp2; // store value of temp2 (the original temp value before it's "deletion") in i; allows successful "switching" placement of least values to leftmost side and greatest values to rightmost side
           }
       }
        temp++; // needed to end while loop
    }
   // prints result
   for (int j = 0; j < 10; j++) {
        cout << arr[j] << " ";
    }
    return 0;
    
    
    // resources studied:
    /*
    1) https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    2) https://www.youtube.com/watch?v=91asU4hSnd4
    3) https://www.youtube.com/watch?v=Fs_elYHrTHU
    4) https://www.sololearn.com/learning/1051
    */
}
