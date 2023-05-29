#include <iostream>

using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    
    cout << "\nPrinting array in order: ";
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    
    cout << "\nPrinting array in reverse order: ";
    for (int j = 0; j < 10; j++) {
        cout << arr[9-j] << " ";
    }
    
    cout << "\nPrinting array in order from least to greatest number: ";
   int temp = 0;
   while (temp < (sizeof(arr)/sizeof(*arr))) {
   for (int i = temp + 1; i < (sizeof(arr)/sizeof(*arr)); i++) {
       if (arr[temp] > arr[i]) {
           int tmp = arr[temp];
           arr[temp] = arr[i];
           arr[i] = tmp;
       }
   }
   temp++;
   }
   
   for (int j = 0; j < 10; j++) {
        cout << arr[j] << " ";
    }
    return 0;
}
