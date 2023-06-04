//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
// Paydreanne E. Hinton

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

int comparePatientsByAge(const void* patient1, const void* patient2) {
    const patient* p1 = static_cast<const patient*>(patient1);
    const patient* p2 = static_cast<const patient*>(patient2);
    if (p1 -> age < p2 -> age) {
        return -1;
    } else if (p1 -> age == p2-> age) {
        return 0;
    } else {
        return 1;
    }
}



//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE

int comparePatientsByBalance(const void* patient1, const void* patient2) {
    const patient* p1 = static_cast<const patient*>(patient1);
    const patient* p2 = static_cast<const patient*>(patient2);
    if (p1 -> balance < p2 -> balance) {
        return -1;
    } else if (p1 -> balance == p2-> balance) {
        return 0;
    } else {
        return 1;
    }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)

int comparePatientsByName(const void* patient1, const void* patient2) {
    const patient* p1 = static_cast<const patient*>(patient1);
    const patient* p2 = static_cast<const patient*>(patient2);
    return strncmp(p1 -> name, p2 -> name, 5);
}


// Function to display the list of patients
void displayPatientList(const patient* patient_list, int patient_list_size) {
    for (int i = 0; i < patient_list_size; i++) {
        cout << (i+1) << ") Name: " << patient_list[i].name << "\n   Age: " << patient_list[i].age << "\n   Balance: $" << patient_list[i].balance << "\n\n";
    }
    cout << endl;
}

//  The main program
int main()
{
    int total_patients = 5;
    
    //  Storing some test data
    struct patient patient_list[5] = {
        {25, "Juan Valdez", 1250},
        {15, "James Morris", 2100},
        {32, "Tyra Banks", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
    patient p;
    
    cout << "Patient List: " << endl;
    
    //  TODO:
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
    displayPatientList(patient_list, total_patients); // displays unsorted list of patients

    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    
    cout << "Patient List - Sorted by Age: " << endl;
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByAge); // sorts by age
    displayPatientList(patient_list, total_patients); // outputs list of patients except sorted by age

    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByBalance); // sorts by balance
    displayPatientList(patient_list, total_patients); // outputs list of patients except sorted by balance
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    
    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByName); // sorts by name
    displayPatientList(patient_list, total_patients); // outputs list of patients except sorted by name
    
    cout << endl;
    
    return 0;
}
